#include "stdafx.h"
#include <tchar.h>
#include <vector> 

#include "DataManage.h"

//
// 同じIDのものがあるかチェック
//
//  　dataID   ：ID
//  　list     ：dataDBオブジェクトのポインタ
//  　listIdx  : 同じIDを持つ要素のインデックス
//
//    戻り値    : =VARIANT_TRUE; 同じID有り
//              : =VARIANT_FALSE;同じID無し
//
VARIANT_BOOL dataManage::hasSameID(int dataID, class dataDB list, unsigned int *listIdx)
{
	int size = list.data.size(); //リストサイズ

	if(!list.data.empty())		//リストは空ではない？
	{

		vector<XmlMessage>::iterator it = list.data.begin(); 

		for(int i=0; i < size; i++)			//リストの構成要素の個数分ループ
		{
			if(it->getDataID() == dataID)	//同じクライアントIDのものがある？
			{
				*listIdx = i;				//要素インデックスを代入

				return VARIANT_TRUE;	
			}
			++it;
		}
	}
		
	return VARIANT_FALSE;	

}

// 
// 同じname属性のものがあるかチェック
//
//  　msgName ：name
//  　archive ：getメッセージリスト
//  　listIdx ：同じnameを持つ要素のインデックス
//
//    戻り値    : =VARIANT_TRUE; 同じname属性有り
//              : =VARIANT_FALSE;同じname属性無し
//
VARIANT_BOOL dataManage::hasSameName(BSTR msgName, XmlMessage *archive, unsigned int *listIdx)
{

	VARIANT_BOOL bMatch = VARIANT_FALSE;
	
	return archive->hasSameName(msgName, listIdx);	
}

// 
//　データ保存
//
//  　xml      : XmlMessageオブジェクトのポインタ
//	  dataID   : ID
//
void dataManage::saveData(XmlMessage *xml, unsigned int dataID)
{
	unsigned int listIdx;

	int msgID = 0;		//TODO：messageには1つのmessageのみに限定。後で拡張
	int type  = xml->getMsgType(msgID);	//TODO:１つのxmlデータの中にsetとgetの混在はないとの想定
								//この想定で良いか確認必要。また、xmlMessageでload時に混在時のエラー処理必要か？そこまでやる？
	
	xml->setDataID(dataID);

	switch(type)
	{

	case XmlMessage::msgSet:	// setメッセージ

		if(hasSameID(dataID,setList, &listIdx)) //同じIDがある？
		{
			vector<XmlMessage>::iterator it = setList.data.begin();
			for (unsigned int i = 0; i<listIdx; i++) it++;
			_bstr_t name = xml->list_name.at(msgID);
			XmlMessage archive = *it;

			if (hasSameName(name, &archive, &listIdx))//同じname属性がある？
			{
				//あったら修正  
				BSTR xmlMsg = xml->pDoc->Getxml();
				addSetMsgData(dataID, &xmlMsg);
				::SysFreeString(xmlMsg);
			}
			else
			{
				//なかったら追加
				setList.data.push_back(*xml); 
			}
			
		}
		else
		{
			//無ければ追加
			setList.data.push_back(*xml);
		}
		break;

	case XmlMessage::msgGet:	// getメッセージ

		if(hasSameID(dataID, getList, &listIdx)) //同じクライアントIDがある？
		{						
			//name属性が同じものがある？
			vector<XmlMessage>::iterator it = getList.data.begin();
			for (unsigned int i = 0; i<listIdx; i++) it++;
			_bstr_t name = xml->list_name.at(msgID); //TODO:本来メッセージ個数分ループが必要
			XmlMessage archive = *it;

			if (hasSameName(name, &archive, &listIdx))//同じname属性がある？
			{
				int tmp = archive.getMsgType(msgID);
				if(archive.getMsgType(msgID) == XmlMessage::msgClose)
				{
					//msgType前回値がcloseならば、データを削除してからmsgType=getで追加する
					it = getList.data.erase(it);		// itの位置の要素を削除
					getList.data.insert(it, *xml );     // itの位置に追加
				}
				else
				{
					//msgType前回値がgetならばメッセージを修正
					BSTR xmlMsg = xml->pDoc->Getxml();
					addSetMsgData(dataID, &xmlMsg);
					::SysFreeString(xmlMsg);
				}
			}
			else
			{
				//なかったら追加
				getList.data.push_back(*xml); 
			}
		}
		else //
		{
			getList.data.push_back(*xml);								
		}
		break;

	case XmlMessage::msgClose:	//closeメッセージ

		if(hasSameID(dataID, getList, &listIdx)) //同じクライアントIDがある？
		{

			vector<XmlMessage>::iterator it = getList.data.begin();
			for(unsigned int i =0; i<listIdx; i++) it++;
			_bstr_t name   = xml->list_name.at(msgID);
			XmlMessage archive = *it;

			if(hasSameName(name, &archive ,&listIdx))//同じname属性がある？
			{
				MSXML2::IXMLDOMNodePtr pMsg =archive.pDoc->selectSingleNode(L"/root/message");

				MSXML2::IXMLDOMNamedNodeMapPtr attNodePtr = pMsg->Getattributes();
				MSXML2::IXMLDOMNodePtr pType = attNodePtr->getNamedItem("type");

				pType->put_text(L"close");			//messageタイプをcloseに変更
				it->setMsgType(msgID, XmlMessage::msgClose);
			}	
		}
	
		break;

	case XmlMessage::msgMainLink:	// main link メッセージ

		if (hasSameID(dataID, mainLinkList, &listIdx)) //同じクライアントIDがある？
		{
			//同じIDのデータを削除してから追加する
			vector<XmlMessage>::iterator it = mainLinkList.data.begin();
			for(unsigned int i =0; i<listIdx; i++) it++;
			it = mainLinkList.data.erase(it);		// itの位置の要素を削除
			mainLinkList.data.insert(it, *xml);     // itの位置に追加
		}
		else
		{
			mainLinkList.data.push_back(*xml);
		}
		break;

	case XmlMessage::msgTypeErr:

		default:
		break;
	}
	
}
// 
// getメッセージに基づいてデータ取得
//
//   pParent    ：要素ポインタ
//   str_query　：get条件
//   pLeaf      ：名前が一致したノードポインタ
//
//
//    戻り値    : =VARIANT_TRUE; データ取得成功
//              : =VARIANT_FALSE; getメッセージに対応したデータなし
//
VARIANT_BOOL dataManage::getSetData(MSXML2::IXMLDOMElementPtr pParent, struct getMsg *str_query, MSXML2::IXMLDOMElementPtr *pLeaf)
{

	vector<_bstr_t> path_parent = str_query->path;
	int path_final_idx       = str_query->path.size() - 1 ;
	_bstr_t  name;

	int idx = str_query->path_idx;

	MSXML2::IXMLDOMNodeListPtr pNodes = NULL;	

	if(idx < path_final_idx)	//子ノードがある？
	{
		idx++; //vpathのインデックスを進める

		MSXML2::IXMLDOMNodeListPtr pNodes = pParent->GetchildNodes();
			
		long ll1 = pNodes->Getlength();
		for(int iNode = 0 ; iNode < pNodes->Getlength(); iNode++)	//子ノードの数だけループ
		{
			name = path_parent.at(idx);  

			MSXML2::IXMLDOMElementPtr pChild = pNodes->Getitem(iNode);//子ノード
			if(pChild != NULL)
			{
				_bstr_t temp = pChild->GetnodeName();
				if(_tcscmp(pChild->GetnodeName(),name) ==0)	//要素名が一致？
				{
					*pLeaf = pChild;
					str_query->path_idx = idx;
					if(getSetData(pChild, str_query, pLeaf)) 
					{
						return VARIANT_TRUE;//
					}
				}
			}
		}
		//一致するものが無いので追加 TODO:動作確認まだ

		if(str_query->mode == XmlMessage::modifiedSet)
		{
		
			MSXML2::IXMLDOMDocument2Ptr  pDoc =  pParent->GetownerDocument();

			name = path_parent.at(idx);  //追加
		    IElementPtr pElem = pDoc->createElement(name);
			pParent->appendChild(pElem);

			IElementPtr pPElem = pElem;

			while(++idx <= path_final_idx) 
			{
				name = path_parent.at(idx);  
			    pElem = pParent->GetownerDocument()->createElement(name);
				pPElem->appendChild(pElem);
				pPElem = pElem;
			}
	
			MSXML2::IXMLDOMNamedNodeMapPtr map = str_query->attNodePtr; //属性
			if(map!=NULL)
			{						
				for(long i =0; i <map->Getlength(); i++)	//属性の数だけ追加
				{				
					MSXML2::IXMLDOMNodePtr  pNode = map->Getitem(i);
					pElem->setAttribute(pNode->GetnodeName(), pNode->GetnodeValue());
				}
			}
			*pLeaf = pElem;
			return VARIANT_TRUE;
		}
	}
	else  //最下層のノード
 	{

		//pathに基づいてデータ取得		
		name      = path_parent.at(idx);  
		VARIANT_BOOL bMatch = TRUE;
		if(_tcscmp(pParent->GetnodeName(),name) ==0) //要素名が一致？
		{
			//属性aの一致性確認
			_bstr_t attA1, attA2;
			VARIANT_BOOL bool1, bool2;
			MSXML2::IXMLDOMNamedNodeMapPtr attNodePtr1, attNodePtr2;
			attNodePtr1 = str_query->attNodePtr;
			attNodePtr2 = pParent->Getattributes();

/*
			attNodePtr = str_query->attNodePtr;
			bool1 = getAttA(attNodePtr,&attA1);		//属性a値取得（get要求xml)
			attNodePtr = pParent->Getattributes();
			bool2 = getAttA(attNodePtr,&attA2);		//属性a値取得（db）

			if( bool1 != bool2) return VARIANT_FALSE; //次を検索
			if( attA1 != attA2) return VARIANT_FALSE; //次を検索
*/


			//属性の一致性確認
			if (!matchAttrs(attNodePtr1, attNodePtr2, L"a"))  return VARIANT_FALSE; //次を検索
			if (!matchAttrs(attNodePtr1, attNodePtr2, L"c"))  return VARIANT_FALSE; //次を検索
			if (!matchAttrs(attNodePtr1, attNodePtr2, L"tm")) return VARIANT_FALSE; //次を検索			
			//if (!matchAttrs(attNodePtr1, attNodePtr2, L"t"))  return VARIANT_FALSE; //次を検索
			//属性iの一致性確認
			int idx1, idx2;
			bool1 = getAttIValue(attNodePtr1, &idx1);		//属性i値取得（get要求xml)
			bool2 = getAttIValue(attNodePtr2, &idx2);		//属性i値取得（db)

			if( bool1 != bool2) return VARIANT_FALSE; //次を検索
			if( bool1 == VARIANT_FALSE)  //属性iがないもの
			{
				*pLeaf = pParent;
				return VARIANT_TRUE;
			}
			if( idx1  == idx2 )			//属性iが一致
			{
				*pLeaf = pParent;
				return VARIANT_TRUE;
			}
		}
	}

	return VARIANT_FALSE; // not found
	
}

// 
// メッセージの解析
//
//
//    戻り値    : =VARIANT_TRUE; データ取得成功
//              : =VARIANT_FALSE; getメッセージに対応したデータなし
//
VARIANT_BOOL dataManage::anaMessage(XmlMessage *setData, struct getMsg *str_query, 
									MSXML2::IXMLDOMElementPtr *pLeaf)
{

	int idx            = 0;
	_bstr_t  name;

	vector<_bstr_t> path  = str_query->path;	// get条件
	int path_final_idx = path.size() - 1 ;	// ノードパスのインデックス最大値


	MSXML2::IXMLDOMDocument2Ptr pXMLDom = setData->pDoc;		//setメッセージのdocumentポインタ
	MSXML2::IXMLDOMElementPtr  pRoot   = pXMLDom->documentElement;//setメッセージのルートポインタ
		
	idx++;

	if(pRoot->hasChildNodes())									//ルート直下に子ノードがある？
	{
		MSXML2::IXMLDOMNodeListPtr pMessage = pRoot->GetchildNodes();
		int msgNum = pMessage->Getlength();	
					
		for(int iMsg = 0; iMsg < msgNum; iMsg++)				//messageの数だけループ
		{
			MSXML2::IXMLDOMElementPtr
				pMsgElem = pMessage->Getitem(iMsg);				//message要素

			name      = path.at(idx);  //get条件要素名

			if(_tcscmp(pMsgElem->GetnodeName(),name) ==0)		//要素名が一致？　
			{
				if(idx < path_final_idx) 
				{
					if(pMsgElem->hasChildNodes())				//子ノードがある？
					{
						str_query->path_idx = idx;
						if (getSetData(pMsgElem, str_query, pLeaf))  //messageタグから渡す（Dataタグ無対応）
						{
							return VARIANT_TRUE;
						}
					}
					else
					{
						//該当するデータがない
					}
				}
			}
		}
	}

	return VARIANT_FALSE;	//	TODO:message要素の下には少なくとも１つの要素が必要
	
}

//
//	textを書き換える
//
void dataManage::putText(MSXML2::IXMLDOMElementPtr pParent, int encoding, struct getMsg str_query, BSTR str_temp)
{
			
	BSTR str   = str_temp;

	if(encoding == dataAttrEncoding::text)
	{
		IXMLDOMNodePtr attT= str_query.attNodePtr->getNamedItem("t"); //データ型及びベクトル要素数の属性
				
	
		BSTR dataType =NULL;
				
		if (attT == NULL) //T属性
		{
			dataType = SysAllocString(L"R");	//デフォルトを設定
		}
		else
		{
			attT->get_text(&dataType);
		}
				
		//属性t ID
		Base64Data::convertBintoText(str_temp, dataType, &str);
		::SysFreeString(dataType);
	}
	pParent->put_text(str);	//xmlに反映
	::SysFreeString(str);
}

//
//
//
void dataManage::lastBranch(MSXML2::IXMLDOMElementPtr pParent, vector<_bstr_t>vpath,
struct dataAttribute *dataAttr, int mode)
{
	struct getMsg str_query;
	str_query.path = vpath;
	str_query.path_idx = 0;
	str_query.mode = mode;
	if (pParent!=NULL) str_query.attNodePtr = pParent->Getattributes();
		
	MSXML2::IXMLDOMElementPtr pLeaf   = NULL;
	MSXML2::IXMLDOMElementPtr pDatas  = NULL;

	VARIANT_BOOL vbool  = VARIANT_FALSE;
	VARIANT_BOOL iStart = VARIANT_FALSE;
	XmlMessage setData;
	XmlMessage getData;
	XmlMessage mainLinkData;

	switch (mode)
	{
	case XmlMessage::replyMainLinkMsg: //mainLink sendメッセージに対する応答
		for (unsigned int i = 0; i < mainLinkList.data.size(); i++)
		{
			XmlMessage mainLinkData = mainLinkList.data.at(i);	
			if(mainLinkData.getDataID() == dataAttr->ID)
			{
				if (vbool=anaMessage(&mainLinkData, &str_query, (MSXML2::IXMLDOMElementPtr *)&pLeaf))
				{
					break; //データ取得したのでfor文を抜ける
				}
			}
		}
		if(vbool) 
		{
			/*mainlink sendメッセージのt属性*/
			MSXML2::IXMLDOMNamedNodeMapPtr attNodePtr = pLeaf->Getattributes();
			MSXML2::IXMLDOMNodePtr pAttT = attNodePtr->getNamedItem("t");

			if (pAttT != NULL)
			{
				/*request のt属性を書き換える*/
				MSXML2::IXMLDOMNodePtr pReqAttT = str_query.attNodePtr->getNamedItem("t");
				pReqAttT->Puttext(pAttT->Gettext());
			}
			putText(pParent, dataAttr->encoding, str_query, pLeaf->Gettext());
		}

		break;


	case XmlMessage::replyGetMsg: //getメッセージに対する応答 
			
		if (getAttSendValue(str_query.attNodePtr)) //属性 sendがenabledならば
		{
			for (unsigned int i = 0; i < setList.data.size(); i++)
			{
				XmlMessage setData = setList.data.at(i);	
				if (vbool=anaMessage(&setData, &str_query, (MSXML2::IXMLDOMElementPtr *)&pLeaf))
				{
					unsigned int dbID;
					//dbIDがあっているか確認
					dbID = setDBID(&setData);

					if (dataAttr->ID == dbID) //dbIDがあっていたら抜ける
					{
						break; //データ取得したのでfor文を抜ける
					}
					else{
						vbool = VARIANT_FALSE;
					}
				}
			}
			if(vbool)
			{
				if(pLeaf->hasChildNodes())
				{
					MSXML2::IXMLDOMNodeListPtr  pNodes =  pLeaf->GetchildNodes();
					for (int iNode = 0; iNode < pNodes->Getlength(); iNode++)		//子ノードの数だけループ
					{
						MSXML2::IXMLDOMElementPtr pChild = pNodes->Getitem(iNode);  //子
						if(pChild!=NULL)
						{
							//GET文では最終ノードだが、pLeafでは子ノードがある場合
							appendDeepChild(pChild, dataAttr, pParent);
						}
						else if(iNode ==0)
						{
							/*t属性*/
							MSXML2::IXMLDOMNamedNodeMapPtr attNodePtr = pLeaf->Getattributes();
							MSXML2::IXMLDOMNodePtr pAttT = attNodePtr->getNamedItem("t");
							if(pAttT!=NULL){
								/*request のt属性を書き換える*/
								MSXML2::IXMLDOMNodePtr pReqAttT = str_query.attNodePtr->getNamedItem("t");
								if(pReqAttT!=NULL)
								{
									pReqAttT->Puttext(pAttT->Gettext());
								}
							}
							putText(pParent, dataAttr->encoding, str_query, pLeaf->Gettext());
							break;
						}
					}
				}
				else
				{
					/*t属性*/
					MSXML2::IXMLDOMNamedNodeMapPtr attNodePtr = pLeaf->Getattributes();
					MSXML2::IXMLDOMNodePtr pAttT = attNodePtr->getNamedItem("t");

					if(pAttT!=NULL)
					{
						/*request のt属性を書き換える*/
						MSXML2::IXMLDOMNodePtr pReqAttT = str_query.attNodePtr->getNamedItem("t");
						if(pReqAttT!=NULL)
						{
							pReqAttT->Puttext(pAttT->Gettext());
						}
					}
					putText(pParent, dataAttr->encoding, str_query, pLeaf->Gettext());
				}
			}
			else{
				//見つからない
				printf("%s データが取得できません\n", (char*)str_query.path.at(str_query.path.size()-1));
			}
		}

		break;

	case XmlMessage::modifiedSet: //setメッセージ上書き

		for (unsigned int i = 0; i < setList.data.size(); i++)
		{			
			setData = setList.data.at(i);
			unsigned int dbID;
			//dbIDがあっているか確認
			dbID = setDBID(&setData);
			if (dataAttr->ID == dbID)
			{
				if (vbool=anaMessage(&setData, &str_query, (MSXML2::IXMLDOMElementPtr *)&pLeaf))
				{
					break;//for文を抜ける
				}
			}
			else
			{
					vbool = VARIANT_FALSE;
			}
			
		}
		if (vbool)
		{			
			putText(pLeaf, dataAttrEncoding::base64, str_query, pParent->Gettext());
		}
		else
		{
			// setDataの中に無いので追加する
			//
			//name属性が同じsetListを探す
			unsigned int idx = 0;   //name一致するものが見つからなかった場合はMAINに追加する
/*			for (unsigned int i = 0; i < getList.data.size(); i++)
			{
				XmlMessage getData = getList.data.at(i);
				_bstr_t nameL = getAttName(getData.pDoc, 0);
				_bstr_t nameP = getAttName(pParent->GetownerDocument(), 0);

				if (nameL == nameP)  //nameが一致
				{
					idx = i;
					break;
				}
			}
			*/
			
			for (unsigned int i = 0; i < setList.data.size(); i++)
			{
				XmlMessage setData = setList.data.at(i);			
				unsigned int dbID = setDBID(&setData);
				if (dataAttr->ID == dbID) //dbIDがあっていたら抜ける
				{
					idx = i;
					break; //データ取得したのでfor文を抜ける
				}

			}

			setData = setList.data.at(idx); 
			anaMessage(&setData, &str_query, (MSXML2::IXMLDOMElementPtr *)&pLeaf);
			//pLeafは一致したところまでの要素ポインタ
			MSXML2::IXMLDOMElementPtr pBranch = pLeaf;
			iStart = VARIANT_FALSE;
			
			for(size_t i = 0 ; i < str_query.path.size(); i++ )
			{
				_bstr_t name =   str_query.path.at(i);

				if(iStart == VARIANT_TRUE)
				{
					pDatas = setData.pDoc->createElement(name); //要素作成

					MSXML2::IXMLDOMNamedNodeMapPtr map = pParent->Getattributes(); //属性
					if(map!=NULL)
					{						
						for(long i =0; i <map->Getlength(); i++)	//属性の数だけ追加
						{				
							MSXML2::IXMLDOMNodePtr  pNode = map->Getitem(i);
							pDatas->setAttribute(pNode->GetnodeName(), pNode->GetnodeValue());
						}
					}
					pBranch->appendChild(pDatas);
					pBranch = pDatas;
				}

				if(_tcscmp(pLeaf->GetnodeName(),name) ==0)	//要素名が一致？
				{
					iStart = VARIANT_TRUE; //						
				}
			}	
			pDatas->put_text(pParent->Gettext()); //テキストを追記
		}

		break;

	case XmlMessage::modifiedGet: //getメッセージ上書き

		iStart = VARIANT_FALSE;

		for (unsigned int i = 0; i < getList.data.size(); i++)
		{
			XmlMessage getData = getList.data.at(i);
			if (vbool=anaMessage(&getData, &str_query, (MSXML2::IXMLDOMElementPtr *)&pLeaf))//TODO:どの属性の一致性まで見るか？
			{
				unsigned int dbID;
				//dbIDがあっているか確認
				dbID = setDBID(&getData);

				if (dataAttr->ID == dbID) //dbIDがあっていたら抜ける
				{
					break; //データ取得したのでfor文を抜ける
				}
				else{
					vbool = VARIANT_FALSE;
				}
			}
		}
		if (vbool)
		{
			MSXML2::IXMLDOMAttributePtr pAttr = pParent->getAttributeNode("send");
			if (pAttr != NULL)
			{
				pLeaf->setAttribute("send", pAttr->GetnodeValue()); //TODO:他に書き換えるものがあるか確認
			}
		}
		else
		{
			// getDataの中に無いので、追加する
			//
			IElementPtr pDatas  = NULL;
			VARIANT_BOOL iStart = VARIANT_FALSE;

			//name属性が同じgetListを探す
			unsigned int idx = 0;   //name一致するものが見つからなかった場合はMAINに追加する
			for (unsigned int i = 0; i < getList.data.size(); i++)
			{
				XmlMessage getData = getList.data.at(i);
				_bstr_t nameL = getAttName(getData.pDoc, 0);
				_bstr_t nameP = getAttName(pParent->GetownerDocument(), 0);
				if (nameL == nameP)  //nameが一致
				{
					idx = i;
					break;
				}
			}

			getData = getList.data.at(idx); 
			anaMessage(&getData, &str_query, (MSXML2::IXMLDOMElementPtr *)&pLeaf);
			//pLeafは一致したところまでの要素ポインタ
			MSXML2::IXMLDOMElementPtr pBranch = pLeaf;

			for(size_t i = 0 ; i < str_query.path.size(); i++ )
			{
				_bstr_t name =   str_query.path.at(i);

				if(iStart == VARIANT_TRUE)
				{
					pDatas = getData.pDoc->createElement(name); //要素作成

					MSXML2::IXMLDOMNamedNodeMapPtr map = pParent->Getattributes(); //属性
					if(map!=NULL)
					{						
						for(long i =0; i <map->Getlength(); i++)	//属性の数だけ追加
						{				
							MSXML2::IXMLDOMNodePtr  pNode = map->Getitem(i);
							pDatas->setAttribute(pNode->GetnodeName(), pNode->GetnodeValue());
						}
					}
					pBranch->appendChild(pDatas);
					pBranch = pDatas;
				}

				if(pLeaf!=NULL)
				{
					if(_tcscmp(pLeaf->GetnodeName(),name) ==0)	//要素名が一致？
					{
						iStart = VARIANT_TRUE; //						
					}
				}
			}	
		}

		break;
	default:
			break;
	}

}
// 
// 　子ノード検索
//
void dataManage::getInChild(MSXML2::IXMLDOMElementPtr pParent, vector<_bstr_t>vpath, 
		struct dataAttribute *dataAttr, int mode)
{
	vector<_bstr_t> path_parent = vpath;
	vector<_bstr_t> path_temp;

	MSXML2::IXMLDOMNodeListPtr pNodes = NULL;

	if (pParent!= NULL && pParent->hasChildNodes())	//子ノードがある？
	{
		MSXML2::IXMLDOMNodeListPtr pNodes = pParent->GetchildNodes();
		long size = pNodes->Getlength();
		for (int iNode = 0; iNode < size; iNode++)	 //子ノードの数だけループ
		{
			MSXML2::IXMLDOMElementPtr pNode = pNodes->Getitem(iNode);//子ノード
			if (pNode == NULL)
			{
				getLastBranchAttr(pParent, vpath, dataAttr, mode);
			}
			else
			{
				path_temp = path_parent; //親ノードの下に追加するため、いったん親ノードをコピー
				path_temp.push_back(pNode->GetnodeName());

				if (mode == XmlMessage::modifiedGet)  //getメッセージ上書きの場合
				{
					struct getMsg str_query;
					str_query.path = path_temp;
					str_query.path_idx = 0;
					str_query.mode = mode;
					str_query.attNodePtr = pNode->Getattributes();
					MSXML2::IXMLDOMElementPtr pLeaf = NULL;
					VARIANT_BOOL vbool = VARIANT_FALSE;
					for (unsigned int i = 0; i < getList.data.size(); i++)
					{
						XmlMessage getData = getList.data.at(i);
						if (vbool = anaMessage(&getData, &str_query, (MSXML2::IXMLDOMElementPtr *)&pLeaf))//TODO:どの属性の一致性まで見るか？
						{
							break;//for文を抜ける
						}
					}
					if (vbool)
					{
						MSXML2::IXMLDOMAttributePtr pAttr = pNode->getAttributeNode("send");
						if (pAttr != NULL)
						{
							pLeaf->setAttribute("send", pAttr->GetnodeValue()); //子ノードが存在するノードのsend属性を反映させる
						}
					}
				}

				getInChild(pNode, path_temp, dataAttr, mode);	//

				path_temp.pop_back();
			}
			size = pNodes->Getlength();  //配列をばらす場合など、要素を追加することがあるので
		}
	}
	else						 //最下層のノード
	{
		//lastBranch(pParent, vpath, dataAttr, mode);
		getLastBranchAttr(pParent, vpath, dataAttr, mode);
	}
}

// 
// Dataタグの属性設定
//
//
void dataManage::setDataTagAttr(MSXML2::IXMLDOMElementPtr elementPtr, struct dataAttribute* dataAttr)
{

	dataAttr->encoding = dataAttrEncoding::text;	//デフォルト値設定
	dataAttr->array_delimiter = dataAttrArray::tagged;	//デフォルト値設定

	MSXML2::IXMLDOMNamedNodeMapPtr attNodePtr = elementPtr->Getattributes();

	//encoding属性
	MSXML2::IXMLDOMNodePtr encodePtr = attNodePtr->getNamedItem("encoding");						
	if(encodePtr != NULL)
	{
		_bstr_t encode = encodePtr->Gettext();
		if(_tcscmp(encode , L"base64")==0)
		{
			dataAttr->encoding = dataAttrEncoding::base64;
			
		}
	}


	//array属性
	MSXML2::IXMLDOMNodePtr arrayDelimiterPtr = attNodePtr->getNamedItem("array");						
	if(arrayDelimiterPtr != NULL)
	{
		_bstr_t delimiter = arrayDelimiterPtr->Gettext();
		if(_tcscmp(delimiter , L"spaced")==0)
		{
			dataAttr->array_delimiter = dataAttrArray::spaced;
		}
		else
		{
			dataAttr->array_delimiter = dataAttrArray::tagged;
		}

	}

}

// 
// getメッセージの解析
//
//	result		:XMLデータ
//
//  戻り値      : =S_OK       (0) ;正常終了
//              : =S_FALSE    (1) ;異常終了
//              : =MSG_TYPE_NG(2) ;typeタグが不正
//
unsigned int  dataManage::setRequestData(XmlMessage *request, int DATAID)
{
	vector<_bstr_t> vpath, vpath_msg, vpath_root;	//要素の階層リスト

	MSXML2::IXMLDOMDocument2Ptr pXMLDom = request->pDoc;	
	IElementPtr  pRoot   = pXMLDom->documentElement;
		
	vpath_root.push_back(pRoot->GetnodeName());	//要素名を階層リストに追加

	if(pRoot->hasChildNodes())	//ルート直下に子ノード（messageノード）がある？
	{
		MSXML2::IXMLDOMNodeListPtr pMessage = pRoot->GetchildNodes();
		int msgNum = pMessage->Getlength();	
					
		for(int iMsg = 0; iMsg < msgNum; iMsg++)			//messageの数だけループ
		{
			IElementPtr pMsgElem = pMessage->Getitem(iMsg);	//message要素			
			int msgType = request->getMsgType(iMsg);

			if(msgType == XmlMessage::msgGet || msgType == XmlMessage::msgMainLink) 
			{
				vpath_msg = vpath_root;
				vpath_msg.push_back(pMsgElem->GetnodeName());	//要素名を階層リストに追加

				//メッセージタイプをsetに変える
			    INodePtr ptr = pMsgElem->attributes->getNamedItem("type");
				ptr->put_text(L"set");

				if(pMsgElem->hasChildNodes())						//message直下に子ノードがある？
				{
					INodeListPtr pNodes = pMsgElem->GetchildNodes(); //Data要素
			
					for(int iNode = 0 ; iNode < pNodes->Getlength(); iNode++)	//子ノードの数だけループ
					{
						IElementPtr pChild = pNodes->Getitem(iNode);//messageの孫ノード
						vpath = vpath_msg;
						vpath.push_back(pChild->GetnodeName());		//要素名を階層リストに追加


						struct dataAttribute dataAttr;

						setDataTagAttr(pChild, &dataAttr);
						dataAttr.ID = DATAID;
						if(msgType == XmlMessage::msgMainLink)
						{
							dataAttr.mode = XmlMessage::replyMainLinkMsg;
							getInChild(pChild, vpath, &dataAttr, XmlMessage::replyMainLinkMsg );
						}
						else
						{
							dataAttr.mode = XmlMessage::replyGetMsg;
							getInChild(pChild, vpath, &dataAttr, XmlMessage::replyGetMsg);
						}
					}
					return S_OK;								
				}
			}
			else
			{
				return MSG_TYPE_NG;	//メッセージのtypeタグが不正
			}
		}
	}

	return S_FALSE;	//	TODO:message要素の下には少なくとも１つの要素が必要	
}

//
// getメッセージによるデータ取得
//
//	DataID	    :setDBのデータID
//	result		:XMLデータ
//
//  戻り値      : =S_OK              (0) ;正常終了
//              : =S_FALSE           (1) ;異常終了
//
unsigned int dataManage::getMsgOnMainSetDB(unsigned int DataID,unsigned int clientID, BSTR *result)
{
	unsigned int match;
	BSTR  bstr;
	BSTR  xmlGetString;

	if(!hasSameID(clientID, getList, &match))	//同じIDがある？
	{
		if(getDatabyDBID(DataID, &bstr))
		{
			printf("setメッセージがありません DATA_ID=%d, FILE=%s, LINE=%d",
				DataID, __FILE__, __LINE__);
			return S_FALSE;
		}

		MSXML2::IXMLDOMDocument2Ptr  pDomDoc;
		HRESULT hr     = pDomDoc.CreateInstance( __uuidof(MSXML2::DOMDocument60) );
		pDomDoc->async = VARIANT_FALSE;	

		VARIANT_BOOL isSuccess = VARIANT_FALSE;
		HRESULT hr1  = pDomDoc->raw_loadXML(bstr, &isSuccess);
		::SysFreeString(bstr);

		if(setAttType(pDomDoc, L"get") == VARIANT_TRUE &&
			setAttEncode(pDomDoc, L"text") == VARIANT_TRUE) 
		{
			xmlGetString = pDomDoc->Getxml();
			XmlMessage *xml = new XmlMessage(xmlGetString, &hr);
			::SysFreeString(xmlGetString);
			saveData(xml, clientID);
			delete xml;

			if (getData(clientID, result)!= S_OK)
			{
				printf("xml文を取得できませんでした.clientID=%d, FILE=%s, LINE=%d",
					clientID, __FILE__, __LINE__);
				return S_FALSE; 
			}
		}
		else
		{
			return S_FALSE; 
		}
	}
	else
	{
			if (getData(clientID, result)!= S_OK)
			{
				printf("xml文を取得できませんでした.clientID=%d, FILE=%s, LINE=%d",
					clientID, __FILE__, __LINE__);
				return S_FALSE; 
			}
	}
	return S_OK; 
}
//
// getメッセージによるデータ取得
//
//	DataID	    :setDBのデータID
//	result		:XMLデータ
//
//  戻り値      : =S_OK              (0) ;正常終了
//              : =S_FALSE           (1) ;異常終了
//
unsigned int dataManage::getDatabyDBID(unsigned int DataID, BSTR *result)
{
	unsigned int match;

	if(hasSameID(DataID, setList, &match))	//同じIDがある？
	{
	    XmlMessage setData = setList.data.at(match); 
		setData.pDoc->get_xml(result);	
	}
	else
	{
		//データIDエラー
		printf("一致するデータIDがありません .　FILE = %s , LINE = %d\n", __FILE__, __LINE__);
		return S_FALSE;
	}
	return S_OK; 
}

//
//
//  戻り値      : =S_OK              (0) ;正常終了
//              : =S_FALSE           (1) ;異常終了
//              : =GET_ERR_MSG_TYPE  (2) ;typeタグが不正
//
unsigned int dataManage::appendData(XmlMessage *request)
{
	vector<_bstr_t> vpath, vpath_msg, vpath_root;	//要素の階層リスト

	MSXML2::IXMLDOMDocument2Ptr pXMLDom = request->pDoc;
	IElementPtr  pRoot = pXMLDom->documentElement;
	int mode = XmlMessage::modeErr;

	vpath_root.push_back(pRoot->GetnodeName());	//要素名を階層リストに追加

	if (pRoot->hasChildNodes())	//ルート直下に子ノード（messageノード）がある？
	{
		MSXML2::IXMLDOMNodeListPtr pMessage = pRoot->GetchildNodes();
		int msgNum = pMessage->Getlength();

		for (int iMsg = 0; iMsg < msgNum; iMsg++)			//messageの数だけループ
		{
			IElementPtr pMsgElem = pMessage->Getitem(iMsg);	//message要素
			
			//DBIDを取得
			unsigned int dbID;
			dbID = setDBID(request);

			if (request->getMsgType(iMsg) == XmlMessage::msgGet)
			{
				mode = XmlMessage::modifiedGet;
			}
			else if (request->getMsgType(iMsg) == XmlMessage::msgSet)
			{
				mode = XmlMessage::modifiedSet;
				if(setList.data.size()==0 || dbIDMap.size()> setList.data.size()) 
				{
					saveData(request, dbID); //
					return S_OK;
				}

			}
			else if (request->getMsgType(iMsg) == XmlMessage::msgMainLink)
			{
				mode = XmlMessage::modifiedSet;
			}
			else
			{
				return MSG_TYPE_NG;	//getメッセージのtypeタグが"get","set","mainLink send"以外								
			}

			vpath_msg = vpath_root;
			vpath_msg.push_back(pMsgElem->GetnodeName());	//要素名を階層リストに追加

			//if (pMsgElem->hasChildNodes())						//message直下に子ノードがある？
			//{
			//	INodeListPtr pNodes = pMsgElem->GetchildNodes(); //Data要素

			//	for (int iNode = 0; iNode < pNodes->Getlength(); iNode++)	//子ノードの数だけループ
			//	{
			//		IElementPtr pChild = pNodes->Getitem(iNode);//messageの孫ノード
			//		vpath = vpath_msg;
			//		vpath.push_back(pChild->GetnodeName());	//要素名を階層リストに追加

			//		struct dataAttribute dataAttr;
			//		setDataTagAttr(pChild, &dataAttr);
			//		dataAttr.mode = mode;
			//		dataAttr.ID = dbID;
			//		getInChild(pChild, vpath, &dataAttr, mode);	//子ノードの解析
			//	}
			//	return S_OK;
			//}
			vpath = vpath_msg;
			struct dataAttribute dataAttr;
			setDataTagAttr(pMsgElem, &dataAttr);
			dataAttr.mode = mode;
			dataAttr.ID = dbID;
			getInChild(pMsgElem, vpath, &dataAttr, mode);	//子ノードの解析 messageからわたし、Data要素から解析する
		}
		return S_OK;
	}

	return S_FALSE;	//	TODO:message要素の下には少なくとも１つの要素が必要	
}

//
// XMLメッセージDBの修正
//
//	ID	        :ID
//	result		:XMLデータ
//
//  戻り値      : =S_OK              (0) ;正常終了
//              : =S_FALSE           (1) ;異常終了
//              : =GET_ERR_MSG_TYPE  (2) ;typeタグが不正
//
unsigned int dataManage::addSetMsgData(unsigned int ID, BSTR *result)
{
	HRESULT hr = S_FALSE;
	unsigned int ret = S_FALSE;

	XmlMessage *msg = new XmlMessage(*result, &hr);	//出力編集用のメッセージを初期化

	if (hr == S_OK)
	{
		if ((ret = appendData(msg)) == 0)	//メッセージの解析
		{
#ifdef _DEBUG
			//printf(msg->pDoc->Getxml());
#endif
			printf(msg->pDoc->Getxml());
		}
	}
	delete msg;
	return ret;
}

// 
// 　ノードtextのエンコーディング
//
//
void dataManage::nodesEncoding(MSXML2::IXMLDOMElementPtr pParent, int encoding)
{

	if(encoding != dataAttrEncoding::text) return;//デコードが必要ないならリターン
	if(pParent == NULL)return ;
	
	MSXML2::IXMLDOMNodePtr child= pParent->GetfirstChild(); 
    while (child!=NULL) {
		if(child->GetfirstChild())
		{
			nodesEncoding(child, encoding);//子ノードがあるならば、再帰呼び出し
		}
		child = child->GetnextSibling();	//兄弟ノードをコピー
    }
	
	BSTR value_text;
	_bstr_t str = pParent->Gettext();
	if(str.length() > 0) 
	{
		MSXML2::IXMLDOMNamedNodeMapPtr attMapPtr = pParent->Getattributes();
		if(attMapPtr == NULL) 
		{
			//デフォルト"R"
			Base64Data::convertBintoText(str, _bstr_t("R"), &value_text);
		}
		else
		{
			MSXML2::IXMLDOMNodePtr attNodePtr = attMapPtr->getNamedItem("t");
			if(attNodePtr== NULL)
			{
				//デフォルト"R"
				Base64Data::convertBintoText(str, _bstr_t("R"), &value_text);
			}
			else
			{
				_variant_t attT = attNodePtr->Gettext();
				attT.ChangeType(VT_BSTR);
				//base64変換
				Base64Data::convertBintoText(str, attT.bstrVal, &value_text);
			}
		}
					
		pParent->put_text(value_text);
		::SysFreeString(value_text);
	}

}

//
// 配列要素をスペース区切りでsetする
//    pParent   ：要素ポインタ
//    vpath     ：タグ情報
//    dataAttr  ：属性(ELEMATTRIBUTES)
//    mode      ：モード
//    st        ：配列要素の要素番号（開始）
//    ed        ：配列要素の要素番号（終了）
// 
void dataManage::setArrayData(MSXML2::IXMLDOMElementPtr pParent, vector<_bstr_t>vpath, 
						struct dataAttribute *dataAttr, int mode, int st, int ed)
{
	if (ed < st || st < 0 || ed < 0)
	{
		printf("SET:%s 配列要素の指定が不適切です。\n", (char*)vpath.at(vpath.size()-1));
		return;
	}
	
	int tnum = ed - st + 1;
	TCHAR str[8];

	if (mode == XmlMessage::modifiedSet)
	{
		TCHAR** cmtext = NULL;
		BSTR text;
		TCHAR ctext[256];
		BSTR bntext;
		TCHAR *tmp;

		cmtext = (TCHAR **)malloc(sizeof(TCHAR *)* tnum);
		for (int i = 0; i < tnum; i++)
		{
			cmtext[i] = (TCHAR *)malloc(sizeof(TCHAR)* BASE64_BUFFER_SIZE);
		}
		if (cmtext == NULL)
		{
			printf("SET:%s メモリの確保失敗\n", (char*)vpath.at(vpath.size()-1));
			return;
		}
		//setするデータを取得
		text = pParent->Gettext();

		//textを空白で分割
		TCHAR *token;
		_stprintf_s(ctext, BASE64_BUFFER_SIZE, _T("%s"), (LPCTSTR)text);
		tmp = _tcstok_s(ctext, L" ", &token);
		_tcscpy_s(cmtext[0], BASE64_BUFFER_SIZE, tmp);
		for (int i = 1; i < tnum; i++)
		{
			tmp = _tcstok_s(NULL, L" ", &token);
			if (tmp != NULL)
			{
				_tcscpy_s(cmtext[i], BASE64_BUFFER_SIZE, tmp);
			}
			else
			{
				printf("SET:%s 配列データの数が足りません\n", (char*)vpath.at(vpath.size()-1));
				//解放
				for (int i = 0; i < tnum; i++)
				{
					if (cmtext[i] != NULL)
					{
						free(cmtext[i]);
					}
				}
				free(cmtext);
				::SysFreeString(text);
				return;
			}
		}
		//1つずつ登録
		for (int i = st; i <= ed; i++)
		{
			_bstr_t bstrt(cmtext[i - st]);   //指定要素が0から始まるとは限らないので
			bntext = bstrt.copy();
			
			_stprintf_s(str, 8, _T("%d"), i);
			pParent->setAttribute(L"i", str);  //i属性追加

			pParent->Puttext(bntext);  //setするデータを書き換え
			lastBranch(pParent, vpath, dataAttr, mode);

			::SysFreeString(bntext);
		}

		//解放
		for (int i = 0; i < tnum; i++)
		{
			if (cmtext[i] != NULL)
			{
				free(cmtext[i]);
			}
		}
		free(cmtext);
		::SysFreeString(text);
	}
	else if ((mode == XmlMessage::replyGetMsg) || (mode == XmlMessage::modifiedGet))
	{
		if (dataAttr->array_delimiter == dataAttrArray::tagged)
		{
			//GET文のXMLに追加したい
			MSXML2::IXMLDOMElementPtr pParent2;
			////1つずつ登録
			for (int i = st; i <= ed; i++)
			{
				//要素をコピーするやりかた
				MSXML2::IXMLDOMNodePtr clone = pParent->cloneNode(VARIANT_TRUE);
				nodesEncoding(clone, dataAttr->encoding);
				pParent2 = pParent->parentNode->insertBefore(clone, pParent.GetInterfacePtr()); //前に追加
				
				_stprintf_s(str, 8, _T("%d"), i);
				pParent2->setAttribute(L"i", str);  //i属性追加
				lastBranch(pParent2, vpath, dataAttr, mode);
			}
			//ノード削除
			pParent->parentNode->removeChild(pParent);
			pParent = pParent2;
		}
		else
		{
			lastBranchGetArray(pParent, vpath, dataAttr, mode, st, ed);
		}
	}
}

//
// 最終ノードの配列属性を変更
//    pParent   ：要素ポインタ
//    vpath     ：タグ情報
//    dataAttr  ：属性(ELEMATTRIBUTES)
//    mode      ：モード
void dataManage::getLastBranchAttr(MSXML2::IXMLDOMElementPtr pParent, vector<_bstr_t>vpath, struct dataAttribute *dataAttr, int mode)
{
	//配列の場合
	char a[8];
	int tnum = 0;

	MSXML2::IXMLDOMNodePtr pAttI = pParent->Getattributes()->getNamedItem("i");  //属性t取得
	if (pAttI == NULL)  //属性iがないもの
	{
		MSXML2::IXMLDOMNodePtr pAttT = pParent->Getattributes()->getNamedItem("t");  //属性t取得
		if (pAttT != NULL)  //属性tがある
		{
			//t属性のタイプと要素数を取得
			getAttTValue(pAttT, a, &tnum);

			if (strcmp(a, "S") == 0){  //文字列
				//通常の処理
				lastBranch(pParent, vpath, dataAttr, mode);
				return;
			}
		}
		//数字があったら
		if (tnum > 1)
		{
			//配列をset
			int st, ed;
			st = 0;
			ed = tnum - 1;
			//配列要素をset
			setArrayData(pParent, vpath, dataAttr, mode, st, ed);
		}
		else
		{
			//通常の処理
			lastBranch(pParent, vpath, dataAttr, mode);
		}
	}
	else
	{
		_bstr_t itext_b = pAttI->Gettext();
		TCHAR itext_c[16];
		_stprintf_s(itext_c, 16, _T("%s"), (LPCTSTR)itext_b);

		//i="1:3"などの場合
		TCHAR *ret;
		ret = _tcsstr(itext_c, _T(":"));
		if (ret != NULL)
		{
			
			MSXML2::IXMLDOMNodePtr pAttT = pParent->Getattributes()->getNamedItem("t");  //属性t取得
			if (pAttT != NULL)  //属性tがある
			{
				//t属性のタイプと要素数を取得
				getAttTValue(pAttT, a, &tnum);

				if (strcmp(a, "S") == 0){  //文字列
					//通常の処理
					lastBranch(pParent, vpath, dataAttr, mode);
					return;
				}
			}
			int st, ed;
			TCHAR *tmp, *token = NULL;
			tmp = _tcstok_s(itext_c, _T(":"), &token);
			st = _tstoi(tmp);
			tmp = _tcstok_s(NULL, L":", &token);
			ed = _tstoi(tmp);

			if (st > ed){
				int n = st;
				st = ed;
				ed = n;
			}
			if (st < 0){
				printf("Warning:%s のi属性にマイナスは指定できません。0にします。\n", (char*)vpath.at(vpath.size()-1));
				st = 0;
			}
			if (tnum < (ed - st+1)){
				printf("Warning:%s のi属性の指定要素数がt属性の要素数よりも多いです\n", (char*)vpath.at(vpath.size()-1));
				ed = tnum + st - 1;
			}
			//配列要素をset
			setArrayData(pParent, vpath, dataAttr, mode, st, ed);
		}
		else
		{
			//通常の処理
			lastBranch(pParent, vpath, dataAttr, mode);
		}
	}
}

//lastBranchのGET部分をループにした関数
void dataManage::lastBranchGetArray(MSXML2::IXMLDOMElementPtr pParent, vector<_bstr_t>vpath, 
									struct dataAttribute *dataAttr, int mode, int st, int ed)
{
	struct getMsg str_query;
	str_query.path = vpath;
	str_query.path_idx = 0;
	str_query.mode = mode;
	if (pParent != NULL) str_query.attNodePtr = pParent->Getattributes();

	MSXML2::IXMLDOMElementPtr pLeaf = NULL;
	MSXML2::IXMLDOMElementPtr pDatas = NULL;

	VARIANT_BOOL vbool = VARIANT_FALSE;
	VARIANT_BOOL iStart = VARIANT_FALSE;
	XmlMessage setData;
	XmlMessage getData;
	XmlMessage mainLinkData;

	BSTR bntext = NULL;
	TCHAR tmp[1024] = { 0 };

	switch (mode)
	{
	case XmlMessage::replyGetMsg: //getメッセージに対する応答
		if (getAttSendValue(str_query.attNodePtr)) //属性 sendがenabledならば
		{
			for (int j = st; j <= ed; j++)
			{    //要素iでループ
				TCHAR str[8];
				_stprintf_s(str, 8, _T("%d"), j);

				MSXML2::IXMLDOMNodePtr pI = str_query.attNodePtr->getNamedItem(L"i");
				if (pI == NULL){
					pParent->setAttribute(L"i", str);  //i属性追加
					str_query.attNodePtr = pParent->Getattributes();
					pI = str_query.attNodePtr->getNamedItem(L"i");
				}
				_bstr_t bstrI = str;
				pI->Puttext(bstrI);
				
				for (unsigned int i = 0; i < setList.data.size(); i++)
				{
					XmlMessage setData = setList.data.at(i);
					if (vbool = anaMessage(&setData, &str_query, (MSXML2::IXMLDOMElementPtr *)&pLeaf))
					{
						unsigned int dbID;
						//dbIDがあっているか確認
						dbID = setDBID(&setData);

						if (dataAttr->ID == dbID){
							break;//for文を抜ける
						}
						else{
							vbool = VARIANT_FALSE;
						}
					}
				}
				if (vbool)
				{
					if (pLeaf->hasChildNodes())
					{
						MSXML2::IXMLDOMNodeListPtr  pNodes = pLeaf->GetchildNodes();
						for (int iNode = 0; iNode < pNodes->Getlength(); iNode++)		//子ノードの数だけループ
						{
							MSXML2::IXMLDOMElementPtr pChild = pNodes->Getitem(iNode);  //子
							if (pChild != NULL)
							{
								//MSXML2::IXMLDOMNodePtr clone = pChild->cloneNode(VARIANT_TRUE);
								//nodesEncoding(clone, dataAttr->encoding);
								//pParent->appendChild(clone);
								appendDeepChild(pChild, dataAttr, pParent);
							}
							else if (iNode == 0)
							{
								BSTR dataType = NULL;
								
								/*t属性*/
								MSXML2::IXMLDOMNamedNodeMapPtr attNodePtr = pLeaf->Getattributes();
								MSXML2::IXMLDOMNodePtr pAttT = attNodePtr->getNamedItem("t");
								if (pAttT != NULL){
									/*request のt属性を書き換える*/
									MSXML2::IXMLDOMNodePtr pReqAttT = str_query.attNodePtr->getNamedItem("t");
									if (pReqAttT != NULL)
									{
										pReqAttT->Puttext(pAttT->Gettext());
									}
								}

								pAttT->get_text(&dataType);
								if (dataAttr->encoding == dataAttrEncoding::text)
								{
									Base64Data::convertBintoText(pLeaf->Gettext(), dataType, &bntext);
								}
								else
								{
									bntext = pLeaf->Gettext();  //値
								}
								_tcsncat_s(tmp, bntext, BASE64_BUFFER_SIZE);
								::SysFreeString(dataType);
							}
						}
					}
					else
					{
						/*t属性*/
						MSXML2::IXMLDOMNamedNodeMapPtr attNodePtr = pLeaf->Getattributes();
						MSXML2::IXMLDOMNodePtr pAttT = attNodePtr->getNamedItem("t");
						BSTR dataType = NULL;

						if (pAttT != NULL)
						{
							/*request のt属性を書き換える*/
							MSXML2::IXMLDOMNodePtr pReqAttT = str_query.attNodePtr->getNamedItem("t");
							if (pReqAttT != NULL)
							{
								pReqAttT->Puttext(pAttT->Gettext());
							}
						}

						pAttT->get_text(&dataType);
						if (dataAttr->encoding == dataAttrEncoding::text)
						{
							Base64Data::convertBintoText(pLeaf->Gettext(), dataType, &bntext);
						}
						else
						{
							bntext = pLeaf->Gettext();  //値
						}
						_tcsncat_s(tmp, bntext, BASE64_BUFFER_SIZE);
						::SysFreeString(dataType);

					}
					if (j != ed){
						_tcsncat_s(tmp, L" ", 1);
					}
				}
			}
			if (_tcscmp(tmp, L"") != 0){
				_bstr_t bstrt(tmp);
				TCHAR str[8];
				_stprintf_s(str, 8, _T("%d:%d"), st, ed);
				pParent->setAttribute(L"i", str);  //i属性追加
				pParent->put_text(bstrt.copy());	//xmlに反映
			}
			else{
				printf("%s 配列の要素数が正しくないか、データが存在しません。\n", (char*)str_query.path.at(str_query.path.size()-1));
			}
		}
		break;

	case XmlMessage::modifiedGet: //getメッセージ上書き
		lastBranch(pParent, vpath, dataAttr, mode);
		break;

	default:
		break;
	}
	if(bntext != NULL)	::SysFreeString(bntext);
}

//
//GET:子ノード以下の（孫、ひ孫）ノードを追加する
//      pChild　 ：追加元のポインタ（DB保存のデータpLeaf）
//      pParent　：要素ポインタ(追加される側）（GET文）
//
//     戻り値　　：VARIANT_TRUE  追加成功
//                 VARIANT_FALSE　失敗
VARIANT_BOOL dataManage::appendDeepChild(MSXML2::IXMLDOMElementPtr pChild, struct dataAttribute *dataAttr, MSXML2::IXMLDOMElementPtr pParent)
{
	//子ノードを追加
	MSXML2::IXMLDOMNodePtr clone = pChild->cloneNode(VARIANT_TRUE);
	nodesEncoding(clone, dataAttr->encoding);
	MSXML2::IXMLDOMElementPtr pParent2 = pParent->appendChild(clone);

	//孫、ひ孫のノードもコピー
	if (pChild->hasChildNodes())
	{		
		MSXML2::IXMLDOMNodeListPtr  pNodes2 = pChild->GetchildNodes();

		for (int iNode2 = 0; iNode2 < pNodes2->Getlength(); iNode2++)
		{
			MSXML2::IXMLDOMElementPtr pChild2 = pNodes2->Getitem(iNode2);
			if (pChild2 != NULL)
			{
				//pChildに子ノードがある場合、追加したpParent2の中身に不要データ(0.0e0)などが入ってるので削除
				if (iNode2 == 0){
					pParent2->put_text(L"");
				}

				appendDeepChild(pChild2, dataAttr, pParent2);
			}
		}
	}

	return VARIANT_TRUE;
}

#pragma region get
//
//
//  戻り値      : =S_OK       (0) ;正常終了
//              : =S_FALSE    (1) ;異常終了
//              : =ERR_TAG_NAME(3);タグ名のサイズが0
//			    : =DATA_GET_ERR   ;データ取得エラー
//			    : =ARRAY_SIZE_ERR ;バッファサイズよりもコピーサイズが大
//
//
// getメッセージによるデータ取得
//
//	clientID	:クライアントID
//	result		:XMLデータ
//
//  戻り値      : =S_OK              (0) ;正常終了
//              : =S_FALSE           (1) ;異常終了
//              : =GET_ERR_MSG_TYPE  (2) ;typeタグが不正
//              : =GET_ERR_NEW_XMLMSG(3) ;XmlMessageクラスの初期化に失敗
//              : =GET_ERR_NO_CID    (4) ;クライアントIDに対応するメッセージがない
//
unsigned int dataManage::getData(unsigned int clientID, BSTR *result)
{

	unsigned int ret = GET_ERR_NO_CID;

	if (!getList.data.empty()) //getメッセージリストが空でない？
	{
		vector<XmlMessage>::iterator get_list = getList.data.begin();

		for (unsigned int i = 0; i<getList.data.size(); i++)	//getメッセージ個数分ループ
		{

			if (get_list->getDataID() == clientID)		//ClientIDが一致？
			{
				BSTR bstrGetXML;
				get_list->pDoc->get_xml(&bstrGetXML);	//getメッセージリストからgetメッセージを取得

				HRESULT hr = S_FALSE;
				XmlMessage *msg = new XmlMessage(bstrGetXML, &hr);	//出力編集用のメッセージを初期化

				if (hr == S_OK)
				{
					msg->removeDisenable();

					//DBIDを取得
					unsigned int dbID;
					dbID = setDBID(msg);

					if ((ret = setRequestData(msg, dbID)) == 0)	//getメッセージの解析
					{
						msg->pDoc->get_xml(result); //XMLデータを取得
					}

				}
				else
				{
					ret = GET_ERR_NEW_XMLMSG;
				}

				::SysFreeString(bstrGetXML);
				delete msg;

				break;
			}

			++get_list;
		}
	}


	return ret;
}
//
//
//
//
//  戻り値      : =S_OK              (0) ;正常終了
//              : =S_FALSE           (1) ;異常終了
//              : =GET_ERR_MSG_TYPE  (2) ;typeタグが不正
//              : =GET_ERR_NEW_XMLMSG(3) ;XmlMessageクラスの初期化に失敗
//              : =GET_ERR_NO_CID    (4) ;クライアントIDに対応するメッセージがない
//
unsigned int dataManage::getData(unsigned int DATAID, BSTR request, BSTR path, BSTR *result, int *attTID)
{
	unsigned int ret = GET_ERR_NO_CID;

	HRESULT hr = S_FALSE;
	XmlMessage *msg = new XmlMessage(request, &hr);	//出力編集用のメッセージを初期化
	if (hr == S_OK)
	{
		if ((ret = setRequestData(msg, DATAID)) == 0)	//getメッセージの解析
		{
			BSTR getXml;
			msg->pDoc->get_xml(&getXml);					//XMLデータを取得
			::SysFreeString(getXml);
		}
	}
	else
	{
		ret = GET_ERR_NEW_XMLMSG;
	}

	MSXML2::IXMLDOMNodePtr pChild = msg->pDoc->selectSingleNode(path);
	MSXML2::IXMLDOMNamedNodeMapPtr attNodePtr = pChild->Getattributes();
	MSXML2::IXMLDOMNodePtr attT = attNodePtr->getNamedItem("t"); //T属性

	BSTR dataType = NULL;
	if (attT == NULL)
	{
		dataType = SysAllocString(L"R");	//デフォルトを設定
	}
	else
	{
		attT->get_text(&dataType);
		if (SysStringByteLen(dataType) <= 0)
		{
			dataType = SysAllocString(L"R");	//デフォルトを設定
		}
	}

	char* c = _com_util::ConvertBSTRToString(dataType);
	size_t c_size = 0;

	for (c_size = 0; c_size< strlen(c); c_size++)	//アルファベット部を抜き出す
	{
		if (!isalpha(c[c_size])) break;
	}

	map<int, string>::iterator it = dataTypeMap.begin();
	while (it != dataTypeMap.end())
	{
		if (c_size == strlen((it->second).c_str()))
		{
			if (strncmp((it->second).c_str(), c, strlen((it->second).c_str())) == 0) //文字列一致
			{
				*attTID = it->first;
				break;
			}
		}
		++it;
	}

	::SysFreeString(dataType);
	delete[] c;

	//
	*result = pChild->Gettext();
	delete msg;

	return ret;
}
//
// getメッセージによるデータ取得
//
//	clientID	:クライアントID
//  name        :message要素のname属性値
//	result		:XMLデータ
//
//  戻り値      : =S_OK              (0) ;正常終了
//              : =S_FALSE           (1) ;異常終了
//              : =GET_ERR_MSG_TYPE  (2) ;typeタグが不正
//              : =GET_ERR_NEW_XMLMSG(3) ;XmlMessageクラスの初期化に失敗
//              : =GET_ERR_NO_CID    (4) ;クライアントIDに対応するメッセージがない
//
unsigned int dataManage::getData(unsigned int clientID, BSTR name, BSTR *result)
{
	unsigned int ret = GET_ERR_NO_CID;

	if (!getList.data.empty()) //getメッセージリストが空でない？
	{
		vector<XmlMessage>::iterator get_list = getList.data.begin();

		for (unsigned int i = 0; i<getList.data.size(); i++)	//getメッセージ個数分ループ
		{
			BSTR name_list = getAttName(get_list->pDoc, 0);

			char* str1 = _com_util::ConvertBSTRToString(name);
			char* str2 = _com_util::ConvertBSTRToString(name_list);
			::SysFreeString(name_list);

			//ClientIDが一致？ && name属性が一致？
			if ((get_list->getDataID() == clientID) && (strncmp(str2, str1, BASE64_BUFFER_SIZE) == 0))
			{
				BSTR bstrGetXML;
				get_list->pDoc->get_xml(&bstrGetXML);	//getメッセージリストからgetメッセージを取得

				//Debug
				//printf("\ngetXML登録してあるもの\n");
				//wprintf(bstrGetXML);

				HRESULT hr = S_FALSE;
				XmlMessage *msg = new XmlMessage(bstrGetXML, &hr);	//出力編集用のメッセージを初期化

				if (hr == S_OK)
				{
					msg->removeDisenable();

					//DBIDを取得
					unsigned int dbID;
					dbID = setDBID(msg);

					if ((ret = setRequestData(msg, dbID)) == 0)	//getメッセージの解析
					{
						msg->pDoc->get_xml(result); //XMLデータを取得
					}
				}
				else
				{
					ret = GET_ERR_NEW_XMLMSG;
				}

				::SysFreeString(bstrGetXML);
				delete msg;
				delete[] str1;
				delete[] str2;

				break;
			}
			delete[] str1;
			delete[] str2;
			++get_list;
		}
	}

	return ret;
}

HRESULT dataManage::getElement(unsigned int clientID, vector<_bstr_t>vpath, LPCTSTR idx, LPTSTR result, int* attTID)
{

	if (vpath.size() <= 0)
	{
		printf("タグ名がNULLです。FILE = %s , LINE = %d\n", __FILE__, __LINE__);
		return ERR_TAG_NAME;
	}

	// XMLデータ保存クラス	
	HRESULT hr = S_FALSE;
	XmlData wrt = XmlData(&hr);
	if (FAILED(hr))
	{
		printf("Failed to instantiate an XML DOM.　FILE = %s , LINE = %d\n", __FILE__, __LINE__);
		return S_FALSE;
	}

	// メッセージタグ
	MessageTag msg = MessageTag(L"mainlink send");
	wrt.addMessageTag(&msg);

	//　カテゴリータグ
	IElementPtr pChild = wrt.addChild(msg.getMsgPtr(), L"Data"); // 第１引数に親を指定
	pChild->setAttribute("encoding", "base64");
	IElementPtr pParent = pChild;

	//  タグ
	vector<_bstr_t>::iterator it = vpath.begin();
	int max_idx = vpath.size() - 1; //リストサイズ

	_bstr_t path = L"/root/message/Data/";

	for (int i = 0; i < max_idx; i++)			//リストの構成要素の個数分ループ
	{
		pParent = pChild;
		pChild = wrt.addChild(pParent, vpath.at(i));
		path += (vpath.at(i) + L"/");
	}
	path += vpath.at(max_idx);

	pParent = pChild;
	ElementData child = ElementData(vpath.at(max_idx), NULL);
	if (idx != NULL) child.setAttribute(L"i", idx);
	child.setAttribute(L"t", NULL); //ダミーデータを入れる
	IElementPtr pElem = wrt.addChild(pParent, &child);

	hr = getElementData(&wrt, clientID, path, result, attTID);

	return hr;
}
//
//
//  戻り値      : =S_OK       (0) ;正常終了
//              : =S_FALSE    (1) ;異常終了
//              : =ERR_TAG_NAME(3);タグ名のサイズが0
//			    : =DATA_GET_ERR   ;データ取得エラー
//			    : =ARRAY_SIZE_ERR ;バッファサイズよりもコピーサイズが大
//
HRESULT dataManage::getElement(LPCTSTR type, unsigned int clientID, vector<_bstr_t>vpath, LPCTSTR idx, LPTSTR result, int* attTID)
{

	if (vpath.size() <= 0)
	{
		printf("タグ名がNULLです。FILE = %s , LINE = %d\n", __FILE__, __LINE__);
		return ERR_TAG_NAME;
	}

	// XMLデータ保存クラス	
	HRESULT hr = S_FALSE;
	XmlData wrt = XmlData(&hr);
	if (FAILED(hr))
	{
		printf("Failed to instantiate an XML DOM.　FILE = %s , LINE = %d\n", __FILE__, __LINE__);
		return S_FALSE;
	}

	// メッセージタグ
	MessageTag msg = MessageTag(type);
	wrt.addMessageTag(&msg);

	//　カテゴリータグ
	IElementPtr pChild = wrt.addChild(msg.getMsgPtr(), L"Data"); // 第１引数に親を指定
	pChild->setAttribute("encoding", "base64");
	IElementPtr pParent = pChild;

	//  タグ
	vector<_bstr_t>::iterator it = vpath.begin();
	int max_idx = vpath.size() - 1; //リストサイズ

	_bstr_t path = L"/root/message/Data/";

	for (int i = 0; i < max_idx; i++)			//リストの構成要素の個数分ループ
	{
		pParent = pChild;
		pChild = wrt.addChild(pParent, vpath.at(i));
		path += (vpath.at(i) + L"/");
	}
	path += vpath.at(max_idx);

	pParent = pChild;
	ElementData child = ElementData(vpath.at(max_idx), NULL);
	if (idx != NULL) child.setAttribute(L"i", idx);
	child.setAttribute(L"t", NULL); //ダミーデータを入れる
	IElementPtr pElem = wrt.addChild(pParent, &child);

	hr = getElementData(&wrt, clientID, path, result, attTID);

	return hr;
}
//
//
//  戻り値      : =S_OK        (0) ;正常終了
//              : =S_FALSE     (1) ;異常終了
//              : =ERR_TAG_NAME(3);タグ名のサイズが0
//
HRESULT dataManage::setElement(vector<_bstr_t>vpath, unsigned int array_size, unsigned int array_idx, LPCTSTR valtype, LPCTSTR pstr)
{

	if (vpath.size() <= 0)
	{
		printf("タグ名がNULLです。FILE = %s , LINE = %d\n", __FILE__, __LINE__);
		return ERR_TAG_NAME;
	}

	HRESULT hr;

	// XMLデータ保存クラス	
	XmlData wrt = XmlData(&hr);
	if (FAILED(hr))
	{
		printf("Failed to instantiate an XML DOM.　FILE = %s , LINE = %d\n", __FILE__, __LINE__);
		return S_FALSE;
	}

	// メッセージタグ
	MessageTag msg = MessageTag(L"set");
	wrt.addMessageTag(&msg);

	//　カテゴリータグ
	IElementPtr pChild = wrt.addChild(msg.getMsgPtr(), L"Data"); // 第１引数に親を指定
	IElementPtr pParent = pChild;

	//  タグ
	vector<_bstr_t>::iterator it = vpath.begin();
	int max_idx = vpath.size() - 1; //リストサイズ

	for (int i = 0; i < max_idx; i++)			//リストの構成要素の個数分ループ
	{
		pParent = pChild;
		pChild = wrt.addChild(pParent, vpath.at(i));
	}
	pParent = pChild;
	ElementData child = ElementData(vpath.at(max_idx), pstr);
	child.setAttribute(L"t", valtype);
	if (array_size>0)
	{
		TCHAR idx[BASE64_BUFFER_SIZE];
		_stprintf_s(idx, _T("%d"), array_idx);
		child.setAttribute(L"i", idx);
	}
	IElementPtr pElem = wrt.addChild(pParent, &child);

	BSTR bstrXML;
	unsigned int dataID = SET_MAINDB;
	wrt.getXML(&bstrXML);
	addSetMsgData(dataID, &bstrXML);
	::SysFreeString(bstrXML);

	return S_OK;
}

//
// メインDBより一要素の取得【double】
//    vpath     ：タグ情報
//    idx       ：属性i
//    value     ：値
// 
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, LPCTSTR idx, double *value)
{
	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];
	size_t outsize;

	int dataType = Base64Data::R;
	int attTID = -1;

	HRESULT hr = getElement(L"get", SET_MAINDB, vpath, idx, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	Base64Data::decode(val, test_decode, &outsize);
	*value = *((double*)test_decode);

	return hr;

}

//
// メインDBより一要素の取得【double】
//    vpath     ：タグ情報
//    value     ：値
// 
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, double *value)
{
	return getOneElement(vpath, NULL, value);
}
//
// メインDBより一要素の取得【int】
//    clientID  :クライアントID
//    vpath     ：タグ情報
//    idx       ：属性i
//    value     ：値
//
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, LPCTSTR idx, int *value)
{

	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];
	size_t outsize;

	int dataType = Base64Data::I;
	int attTID = -1;

	HRESULT hr = getElement(L"get", SET_MAINDB, vpath, idx, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	Base64Data::decode(val, test_decode, &outsize);
	*value = *((int*)test_decode);

	return hr;

}

//
// メインDBより一要素の取得【int】
//    vpath     ：タグ情報
//    value     ：値
//
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, int *value)
{
	return getOneElement(vpath, NULL, value);
}
//
// メインDBより一要素の取得【unsigned short】
//    vpath     ：タグ情報
//    idx       ：属性i
//    value     ：値
//
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, LPCTSTR idx, unsigned short *value)
{

	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];
	size_t outsize;

	int dataType = Base64Data::USI;
	int attTID = -1;

	HRESULT hr = getElement(L"get", SET_MAINDB, vpath, idx, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	Base64Data::decode(val, test_decode, &outsize);
	*value = *((unsigned short*)test_decode);

	return hr;

}
//
// メインDBより一要素の取得【unsigned short】
//    vpath     ：タグ情報
//    value     ：値
//
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, unsigned short *value)
{
	return getOneElement(vpath, NULL, value);
}

//
// メインDBより一要素の取得【符号無し8ビット整数型】
//    vpath     ：タグ情報
//    idx       ：属性i
//    value     ：値
//
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
//
HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, LPCTSTR idx, unsigned char *value)
{

	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];
	size_t outsize;

	int dataType = Base64Data::X;
	int attTID = -1;

	HRESULT hr = getElement(L"get", SET_MAINDB, vpath, idx, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	Base64Data::decode(val, test_decode, &outsize);
	*value = *((unsigned char*)test_decode);

	return hr;

}
//
// メインDBより一要素の取得【ブール代数型】
//    vpath     ：タグ情報
//    idx       ：属性i
//    value     ：値
//
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
//
HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, LPCTSTR idx, char value[1])
{

	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::B;
	int attTID = -1;

	HRESULT hr = getElement(L"get", SET_MAINDB, vpath, idx, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	Base64Data::decodeString(val, Base64Data::B, test_decode);
	value[0] = test_decode[0];

	return hr;

}
//
// メインDBより一要素の取得【符号無し8ビット整数型】
//    vpath     ：タグ情報
//    value     ：値
//
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, unsigned char *value)
{
	return getOneElement(vpath, NULL, value);
}
//
//ﾔｪﾋﾘ//ｻ�ﾈ｡[ﾋｫ]
//ｿﾍｻｧｶﾋID｣ｺﾎｯﾍﾐﾈﾋﾉ�ｷﾝﾖ､
// VPATH｣ｺｱ�ﾇｩﾐﾅﾏ｢
// IDX｣ｺﾎﾒﾊ�ﾐﾔ
//ﾖｵ｣ｺﾖｵ
//
//ｷｵｻﾘﾖｵ｣ｺ= S_OK｣ｨ0｣ｩ;ｳﾉｹｦﾍ�ｳﾉ
//｣ｺ= S_FALSE｣ｨ1｣ｩ;ﾒ�ｳ｣ﾖﾕﾖｹ
//｣ｺ= ERR_DATA_ATT_T｣ｨ5｣ｩ;ﾊ�ｾﾝﾀ獎ﾍｲｻﾆ･ﾅ�
//｣ｺ= ERR_TAG_NAME｣ｨ6｣ｩ;ﾋ�ﾊ�ｱ�ﾇｩﾃ�0ｵﾄｴ�ﾐ｡
//｣ｺ= ERR_DATA_GET｣ｨ7｣ｩ;ﾊ�ｾﾝｻ�ﾈ｡ﾎ�ｲ�
//｣ｺ= ERR_ARRAY_SIZE｣ｨ8｣ｩ;ｸｴﾓ｡ｴ�ﾐ｡ｴ�ﾓﾚｻｺｳ衂�ｵﾄｴ�ﾐ｡ﾔｽｴ�
HRESULT dataManage::getOneElement(unsigned int clientID, vector<_bstr_t>vpath, LPCTSTR idx, double *value)
{
	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];
	size_t outsize;

	int dataType = Base64Data::R;
	int attTID = -1;

	HRESULT hr = getElement(clientID, vpath, idx, val, &attTID);
	if (dataType != attTID)
	{
		printf("ﾊ�ｾﾝﾀ獎ﾍｲｻﾆ･ﾅ臀n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("ﾊ�ｾﾝｲｻﾄﾜｵﾃｵｽ｡｣\n");
		return ERR_DATA_GET;
	}

	Base64Data::decode(val, test_decode, &outsize);
	*value = *((double*)test_decode);

	return hr;

}
//
// 一要素の取得【double】
//    clientID  :クライアントID
//    vpath     ：タグ情報
//    value     ：値
//
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
HRESULT dataManage::getOneElement(unsigned int clientID, vector<_bstr_t>vpath, double *value)
{
	return getOneElement(clientID, vpath, NULL, value);
}
//
// 一要素の取得【int】
//    clientID  :クライアントID
//    vpath     ：タグ情報
//    idx       ：属性i
//    value     ：値
//
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
HRESULT dataManage::getOneElement(unsigned int clientID, vector<_bstr_t>vpath, LPCTSTR idx, int *value)
{

	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];
	size_t outsize;

	int dataType = Base64Data::I;
	int attTID = -1;

	HRESULT hr = getElement(clientID, vpath, idx, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	Base64Data::decode(val, test_decode, &outsize);
	*value = *((int*)test_decode);

	return hr;

}
//
// 一要素の取得【int】
//    clientID  :クライアントID
//    vpath     ：タグ情報
//    value     ：値
//
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
HRESULT dataManage::getOneElement(unsigned int clientID, vector<_bstr_t>vpath, int *value)
{
	return getOneElement(clientID, vpath, NULL, value);
}

//
// 一要素の取得【unsigned short】
//    clientID  :クライアントID
//    vpath     ：タグ情報
//    idx       ：属性i
//    value     ：値
//
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
HRESULT dataManage::getOneElement(unsigned int clientID, vector<_bstr_t>vpath, LPCTSTR idx, unsigned short *value)
{

	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];
	size_t outsize;

	int dataType = Base64Data::USI;
	int attTID = -1;

	HRESULT hr = getElement(clientID, vpath, idx, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	Base64Data::decode(val, test_decode, &outsize);
	*value = *((unsigned short*)test_decode);

	return hr;

}
//
// 一要素の取得【unsigned short】
//    clientID  :クライアントID
//    vpath     ：タグ情報
//    value     ：値
//
HRESULT dataManage::getOneElement(unsigned int clientID, vector<_bstr_t>vpath, unsigned short *value)
{
	return getOneElement(clientID, vpath, NULL, value);
}

//
// 一要素の取得【符号無し8ビット整数型】
//    clientID  :クライアントID
//    vpath     ：タグ情報
//    idx       ：属性i
//    value     ：値
//
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
//
HRESULT dataManage::getOneElement(unsigned int clientID, vector<_bstr_t>vpath, LPCTSTR idx, unsigned char *value)
{

	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];
	size_t outsize;

	int dataType = Base64Data::X;
	int attTID = -1;

	HRESULT hr = getElement(clientID, vpath, idx, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	Base64Data::decode(val, test_decode, &outsize);
	*value = *((unsigned char*)test_decode);

	return hr;

}

//
// 一要素の取得【符号無し8ビット整数型】
//    clientID  :クライアントID
//    vpath     ：タグ情報
//    value     ：値
//
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
HRESULT dataManage::getOneElement(unsigned int clientID, vector<_bstr_t>vpath, unsigned char *value)
{
	return getOneElement(clientID, vpath, NULL, value);
}

//
// 一要素の取得【ブール代数型】
//    clientID  :クライアントID
//    vpath     ：タグ情報
//    attr      ：属性(ELEMATTRIBUTES)
//    value     ：値
//
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
//
HRESULT dataManage::getOneElement(unsigned int clientID, vector<_bstr_t>vpath, ELEMATTRIBUTES attr,
	char value[1])
{

	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::B;
	int attTID = -1;

	HRESULT hr = getElement(L"mainlink send", clientID, vpath, attr, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	Base64Data::decodeString(val, Base64Data::B, test_decode);
	value[0] = test_decode[0];

	return hr;

}

//
// 一要素の取得【ブール代数型】
//    clientID  :クライアントID
//    vpath     ：タグ情報
//    idx       ：属性i
//    value     ：値
//
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
//
HRESULT dataManage::getOneElement(unsigned int clientID, vector<_bstr_t>vpath, LPCTSTR idx, char value[1])
{

	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::B;
	int attTID = -1;

	HRESULT hr = getElement(clientID, vpath, idx, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	Base64Data::decodeString(val, Base64Data::B, test_decode);
	value[0] = test_decode[0];

	return hr;

}

//
// メインDBより一要素の取得【double】
//    vpath     ：タグ情報
//    attr      ：属性(ELEMATTRIBUTES)
//    value     ：値
// 
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, double *value)
{
	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];
	size_t outsize;

	int dataType = Base64Data::R;
	int attTID = -1;

	HRESULT hr = getElement(L"get", SET_MAINDB, vpath, attr, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	Base64Data::decode(val, test_decode, &outsize);
	*value = *((double*)test_decode);

	return hr;

}

//
// メインDBより一要素の取得【int】
//    vpath     ：タグ情報
//    attr      ：属性(ELEMATTRIBUTES)
//    value     ：値
// 
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, int *value)
{
	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];
	size_t outsize;

	int dataType = Base64Data::I;
	int attTID = -1;

	HRESULT hr = getElement(L"get", SET_MAINDB, vpath, attr, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	Base64Data::decode(val, test_decode, &outsize);
	*value = *((int*)test_decode);

	return hr;

}
//
// メインDBより一要素の取得【unsigned short】
//    vpath     ：タグ情報
//    attr      ：属性(ELEMATTRIBUTES)
//    value     ：値
// 
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, unsigned short *value)
{
	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];
	size_t outsize;

	int dataType = Base64Data::USI;
	int attTID = -1;

	HRESULT hr = getElement(L"get", SET_MAINDB, vpath, attr, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	Base64Data::decode(val, test_decode, &outsize);
	*value = *((unsigned short*)test_decode);

	return hr;

}
//
// メインDBより一要素の取得【unsigned char】
//    vpath     ：タグ情報
//    attr      ：属性(ELEMATTRIBUTES)
//    value     ：値
// 
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, unsigned char *value)
{
	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];
	size_t outsize;

	int dataType = Base64Data::X;
	int attTID = -1;

	HRESULT hr = getElement(L"get", SET_MAINDB, vpath, attr, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	Base64Data::decode(val, test_decode, &outsize);
	*value = *((unsigned char*)test_decode);

	return hr;

}
//
// メインDBより一要素の取得【ブール代数型】
//    vpath     ：タグ情報
//    attr      ：属性(ELEMATTRIBUTES)
//    value     ：値    
// 
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, char value[1])
{
	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::B;
	int attTID = -1;

	HRESULT hr = getElement(L"get", SET_MAINDB, vpath, attr, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	Base64Data::decodeString(val, Base64Data::B, test_decode);
	value[0] = test_decode[0];

	return hr;

}
//
//
//  戻り値      : =S_OK       (0) ;正常終了
//              : =S_FALSE    (1) ;異常終了
//              : =ERR_TAG_NAME(3);タグ名のサイズが0
//			    : =DATA_GET_ERR   ;データ取得エラー
//			    : =ARRAY_SIZE_ERR ;バッファサイズよりもコピーサイズが大
//
HRESULT dataManage::getElement(LPCTSTR type, unsigned int clientID, vector<_bstr_t>vpath,
	ELEMATTRIBUTES attr, LPTSTR result, int* attTID)
{
	if (vpath.size() <= 0)
	{
		printf("タグ名がNULLです。FILE = %s , LINE = %d\n", __FILE__, __LINE__);
		return ERR_TAG_NAME;
	}

	// XMLデータ保存クラス	
	HRESULT hr = S_FALSE;
	XmlData wrt = XmlData(&hr);
	if (FAILED(hr))
	{
		printf("Failed to instantiate an XML DOM.　FILE = %s , LINE = %d\n", __FILE__, __LINE__);
		return S_FALSE;
	}

	// メッセージタグ
	MessageTag msg = MessageTag(type);
	wrt.addMessageTag(&msg);

	//　カテゴリータグ
	IElementPtr pChild = wrt.addChild(msg.getMsgPtr(), L"Data"); // 第１引数に親を指定
	pChild->setAttribute("encoding", "base64");
	IElementPtr pParent = pChild;

	//  タグ
	vector<_bstr_t>::iterator it = vpath.begin();
	int max_idx = vpath.size() - 1; //リストサイズ

	_bstr_t path = L"/root/message/Data/";

	for (int i = 0; i < max_idx; i++)			//リストの構成要素の個数分ループ
	{
		pParent = pChild;
		pChild = wrt.addChild(pParent, vpath.at(i));
		path += (vpath.at(i) + L"/");
	}
	path += vpath.at(max_idx);

	pParent = pChild;
	ElementData child = ElementData(vpath.at(max_idx), NULL);
	if ((attr.i) != _bstr_t(L"")) //NULLでなかったら
	{
		child.setAttribute(L"i", attr.i);
	}
	child.setAttribute(L"a", attr.a);
	child.setAttribute(L"c", attr.c);
	child.setAttribute(L"tm", attr.tm);

	child.setAttribute(L"t", NULL); //ダミーデータを入れる
	IElementPtr pElem = wrt.addChild(pParent, &child);

	hr = getElementData(&wrt, clientID, path, result, attTID);

	return hr;
}
//
//
//  戻り値      : =S_OK       (0) ;正常終了
//              : =S_FALSE    (1) ;異常終了
//              : =ERR_TAG_NAME(3);タグ名のサイズが0
//			    : =DATA_GET_ERR   ;データ取得エラー
//			    : =ARRAY_SIZE_ERR ;バッファサイズよりもコピーサイズが大
//
HRESULT dataManage::getElement(unsigned int dbID, vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, LPTSTR result, int* attTID)
{
	if (vpath.size() <= 0)
	{
		printf("タグ名がNULLです。FILE = %s , LINE = %d\n", __FILE__, __LINE__);
		return ERR_TAG_NAME;
	}

	// XMLデータ保存クラス	
	HRESULT hr = S_FALSE;
	XmlData wrt = XmlData(&hr);
	if (FAILED(hr))
	{
		printf("Failed to instantiate an XML DOM.　FILE = %s , LINE = %d\n", __FILE__, __LINE__);
		return S_FALSE;
	}

	//ルートポインタ
	IElementPtr pRoot = wrt.getRootPtr();
	_bstr_t path = L"/root/";

	//messageタグを追加
	IElementPtr pMsg = wrt.addChild(pRoot, vpath.at(0));  //Messageタグ
	pMsg->setAttribute(TYPE_KY, L"get");       //Message Typeを設定
	pMsg->setAttribute(L"a", msg_attr.a);  //Messageタグにa属性を設定
	path += (vpath.at(0) + L"/");

	//　カテゴリータグ
	IElementPtr pChild = wrt.addChild(pMsg, vpath.at(1)); // 第１引数に親を指定
	pChild->setAttribute("encoding", "base64");
	IElementPtr pParent = pChild;
	path += (vpath.at(1) + L"/");

	//  タグ
	vector<_bstr_t>::iterator it = vpath.begin();
	int max_idx = vpath.size() - 1; //リストサイズ

	for (int i = 2; i < max_idx; i++)			//リストの構成要素の個数分ループ
	{
		pParent = pChild;
		pChild = wrt.addChild(pParent, vpath.at(i));
		path += (vpath.at(i) + L"/");
	}
	path += vpath.at(max_idx);

	pParent = pChild;
	ElementData child = ElementData(vpath.at(max_idx), NULL);
	if ((attr.i) != _bstr_t(L"")) //NULLでなかったら
	{
		child.setAttribute(L"i", attr.i);
	}
	child.setAttribute(L"a" , attr.a);
	child.setAttribute(L"c" , attr.c);
	child.setAttribute(L"tm", attr.tm);

	child.setAttribute(L"t", NULL); //ダミーデータを入れる
	IElementPtr pElem = wrt.addChild(pParent, &child);

	//get
	hr = getElementData(&wrt, dbID, path, result, attTID);

	return hr;
}

//
//
//  戻り値      : =S_OK       (0) ;正常終了
//              : =S_FALSE    (1) ;異常終了
//              : =ERR_TAG_NAME(3);タグ名のサイズが0
//			    : =DATA_GET_ERR   ;データ取得エラー
//			    : =ARRAY_SIZE_ERR ;バッファサイズよりもコピーサイズが大
//
HRESULT dataManage::getElementData(XmlData *xml, unsigned int dbID, BSTR path, LPTSTR result, int* attTID)
{
	HRESULT hr = S_OK;
	BSTR bstrXML, bstrResult;
	xml->getXML(&bstrXML);

	getData(dbID, bstrXML, path, &bstrResult, attTID);
	TCHAR szFinal[BASE64_BUFFER_SIZE];
	_tcscpy_s(szFinal, BASE64_BUFFER_SIZE, bstrResult);

	if (_tcslen(szFinal) <= BASE64_BUFFER_SIZE)
	{
		_tcscpy_s(result, BASE64_BUFFER_SIZE, bstrResult);
	}
	else if (_tcslen(szFinal) == 0)
	{
		printf("データが取得できませんでした FILE = %s , LINE = %d\n", __FILE__, __LINE__);
		hr = ERR_DATA_GET;
	}
	else
	{
		printf("配列サイズがコピー元サイズよりも小です FILE = %s , LINE = %d\n", __FILE__, __LINE__);
		hr = ERR_ARRAY_SIZE;
	}

	::SysFreeString(bstrXML);
	::SysFreeString(bstrResult);

	return hr;
}

//
// メインDBより一要素の取得【double】
//    vpath     ：タグ情報 messageから指定
//    attr      ：属性(ELEMATTRIBUTES) messageから指定
//    value     ：値
// 
//  戻り値      : =S_OK          (0);正常終了
//              : =S_FALSE       (1);異常終了
//              : =ERR_DATA_ATT_T(5);データタイプの不整合
//              : =ERR_TAG_NAME  (6);タグ名のサイズが0
//			    : =ERR_DATA_GET  (7) ;データ取得エラー
//			    : =ERR_ARRAY_SIZE(8) ;バッファサイズよりもコピーサイズが大
HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, double *value)
{
	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];
	size_t outsize;

	int dataType = Base64Data::R;
	int attTID = -1;
	unsigned int dbID;

	//messageのa属性からDBを決定
	dbID = setDBID(msg_attr.a);

	HRESULT hr = getElement(dbID, vpath, attr, msg_attr, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	Base64Data::decode(val, test_decode, &outsize);
	*value = *((double*)test_decode);

	return hr;
}
//
// メインDBより一要素の取得【int】
//    vpath     ：タグ情報 messageから指定
//    attr      ：属性(ELEMATTRIBUTES) messageから指定
//    value     ：値
HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, int *value)
{
	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];
	size_t outsize;

	int dataType = Base64Data::I;
	int attTID = -1;
	unsigned int dbID;

	//messageのa属性からDBを決定
	dbID = setDBID(msg_attr.a);

	HRESULT hr = getElement(dbID, vpath, attr, msg_attr, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	Base64Data::decode(val, test_decode, &outsize);
	*value = *((int*)test_decode);

	return hr;
}
//
// メインDBより一要素の取得【unsigned short】
//    vpath     ：タグ情報 messageから指定
//    attr      ：属性(ELEMATTRIBUTES) messageから指定
//    value     ：値
HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, unsigned short *value)
{
	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];
	size_t outsize;

	int dataType = Base64Data::USI;
	int attTID = -1;
	unsigned int dbID;

	//messageのa属性からDBを決定
	dbID = setDBID(msg_attr.a);

	HRESULT hr = getElement(dbID, vpath, attr, msg_attr, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	Base64Data::decode(val, test_decode, &outsize);
	*value = *((unsigned short*)test_decode);

	return hr;
}

//
// メインDBより一要素の取得【unsigned char】
//    vpath     ：タグ情報 messageから指定
//    attr      ：属性(ELEMATTRIBUTES) messageから指定
//    value     ：値
HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, unsigned char *value)
{
	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];
	size_t outsize;

	int dataType = Base64Data::X;
	int attTID = -1;
	unsigned int dbID;

	//messageのa属性からDBを決定
	dbID = setDBID(msg_attr.a);

	HRESULT hr = getElement(dbID, vpath, attr, msg_attr, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	Base64Data::decode(val, test_decode, &outsize);
	*value = *((unsigned char*)test_decode);

	return hr;
}
//
// メインDBより一要素の取得【char】
//    vpath     ：タグ情報 messageから指定
//    attr      ：属性(ELEMATTRIBUTES) messageから指定
//    value     ：値
HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, char value[1])
{
	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::B;
	int attTID = -1;
	unsigned int dbID;

	//messageのa属性からDBを決定
	dbID = setDBID(msg_attr.a);

	HRESULT hr = getElement(dbID, vpath, attr, msg_attr, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	Base64Data::decodeString(val, Base64Data::B, test_decode);
	value[0] = test_decode[0];

	return hr;
}

//
// メインDBより一要素の取得【string】
//    vpath     ：タグ情報 messageから指定
//    attr      ：属性(ELEMATTRIBUTES) messageから指定
//    value     ：値
HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, LPTSTR value)
{
	TCHAR  val[BASE64_BUFFER_SIZE*10];

	int dataType = Base64Data::S;
	int attTID = -1;
	unsigned int dbID;

	//messageのa属性からDBを決定
	dbID = setDBID(msg_attr.a);

	HRESULT hr = getElement(dbID, vpath, attr, msg_attr, val, &attTID);
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	//Base64Data::decodeString(val, Base64Data::S, test_decode);
	_tcscpy_s(value, BASE64_BUFFER_SIZE * 10, val);

	return hr;
}

HRESULT dataManage::getOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, BSTR *value)
{
	TCHAR  val[BASE64_BUFFER_SIZE];
	char   test_decode[BASE64_BUFFER_SIZE];
	size_t outsize;

	int dataType = Base64Data::R;
	int attTID = -1;
	unsigned int dbID;

	//messageのa属性からDBを決定
	dbID = setDBID(msg_attr.a);

	HRESULT hr = getElement(dbID, vpath, attr, msg_attr, val, &attTID);
	
	if (dataType != attTID)
	{
		printf("データタイプの不整合\n");
		return ERR_DATA_ATT_T;
	}

	if (!_tcslen(val))
	{
		printf("データが取得できませんでした。\n");
		return ERR_DATA_GET;
	}

	//Base64Data::decode(val, test_decode, &outsize);
	*value = val;

	return hr;
}

#pragma endregion get

#pragma region set
//
// 一要素の更新【double】
//    vpath      :タグ情報
//    array_size：配列サイズ
//    array_idx ：配列インデックス
//    value     ：値
//
//  戻り値      : =S_OK             (0) ;正常終了
//              : =S_FALSE          (1) ;異常終了
//              : =ERR_TAG_NAME     (3);タグ名のサイズが0
//              : =ERR_BASE64_COVERT(6);base64変換エラー
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, unsigned int array_size, unsigned int array_idx, double value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::R;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("R%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("R"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, array_size, array_idx, valtype, pstr);
	return hr;
}

//
// 一要素の更新【float】
//    vpath      :タグ情報
//    array_size：配列サイズ
//    array_idx ：配列インデックス
//    value     ：値
//
//  戻り値      : =S_OK             (0) ;正常終了
//              : =S_FALSE          (1) ;異常終了
//              : =ERR_TAG_NAME     (3);タグ名のサイズが0
//              : =ERR_BASE64_COVERT(6);base64変換エラー
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, unsigned int array_size, unsigned int array_idx, float value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::SR;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("SR%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("SR"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, array_size, array_idx, valtype, pstr);
	return hr;
}

//
// 一要素の更新【long double】
//    vpath      :タグ情報
//    array_size：配列サイズ
//    array_idx ：配列インデックス
//    value     ：値
//
//  戻り値      : =S_OK             (0) ;正常終了
//              : =S_FALSE          (1) ;異常終了
//              : =ERR_TAG_NAME     (3);タグ名のサイズが0
//              : =ERR_BASE64_COVERT(6);base64変換エラー
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, unsigned int array_size, unsigned int array_idx, long double value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::LR;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("LR%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("LR"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, array_size, array_idx, valtype, pstr);
	return hr;
}

//
// 一要素の更新【int】
//    vpath      :タグ情報
//    array_size：配列サイズ
//    array_idx ：配列インデックス
//    value     ：値
//
//  戻り値      : =S_OK             (0) ;正常終了
//              : =S_FALSE          (1) ;異常終了
//              : =ERR_TAG_NAME     (3);タグ名のサイズが0
//              : =ERR_BASE64_COVERT(6);base64変換エラー
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, unsigned int array_size, unsigned int array_idx, int value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::I;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("I%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("I"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, array_size, array_idx, valtype, pstr);
	return hr;
}

//
// 一要素の更新【short】
//    vpath      :タグ情報
//    array_size：配列サイズ
//    array_idx ：配列インデックス
//    value     ：値
//
//  戻り値      : =S_OK             (0) ;正常終了
//              : =S_FALSE          (1) ;異常終了
//              : =ERR_TAG_NAME     (3);タグ名のサイズが0
//              : =ERR_BASE64_COVERT(6);base64変換エラー
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, unsigned int array_size, unsigned int array_idx, short value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::SI;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("SI%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("SI"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, array_size, array_idx, valtype, pstr);
	return hr;
}

//
// 一要素の更新【long long】
//    vpath      :タグ情報
//    array_size：配列サイズ
//    array_idx ：配列インデックス
//    value     ：値
//
//  戻り値      : =S_OK             (0) ;正常終了
//              : =S_FALSE          (1) ;異常終了
//              : =ERR_TAG_NAME     (3);タグ名のサイズが0
//              : =ERR_BASE64_COVERT(6);base64変換エラー
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, unsigned int array_size, unsigned int array_idx, long long value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::SI;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("LI%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("LI"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, array_size, array_idx, valtype, pstr);
	return hr;
}

//
// 一要素の更新【unsigned int】
//    vpath      :タグ情報
//    array_size：配列サイズ
//    array_idx ：配列インデックス
//    value     ：値
//
//  戻り値      : =S_OK             (0) ;正常終了
//              : =S_FALSE          (1) ;異常終了
//              : =ERR_TAG_NAME     (3);タグ名のサイズが0
//              : =ERR_BASE64_COVERT(6);base64変換エラー
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, unsigned int array_size, unsigned int array_idx, unsigned int value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::SI;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("UI%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("UI"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, array_size, array_idx, valtype, pstr);
	return hr;
}

//
// 一要素の更新【unsigned short int】
//    vpath      :タグ情報
//    array_size：配列サイズ
//    array_idx ：配列インデックス
//    value     ：値
//
//  戻り値      : =S_OK             (0) ;正常終了
//              : =S_FALSE          (1) ;異常終了
//              : =ERR_TAG_NAME     (3);タグ名のサイズが0
//              : =ERR_BASE64_COVERT(6);base64変換エラー
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, unsigned int array_size, unsigned int array_idx, unsigned short int value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::USI;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("USI%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("USI"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, array_size, array_idx, valtype, pstr);
	return hr;
}

//
// 一要素の更新【unsigned long long】
//    vpath      :タグ情報
//    array_size：配列サイズ
//    array_idx ：配列インデックス
//    value     ：値
//
//  戻り値      : =S_OK             (0) ;正常終了
//              : =S_FALSE          (1) ;異常終了
//              : =ERR_TAG_NAME     (3);タグ名のサイズが0
//              : =ERR_BASE64_COVERT(6);base64変換エラー
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, unsigned int array_size, unsigned int array_idx, unsigned long long value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::ULI;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("ULI%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("ULI"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, array_size, array_idx, valtype, pstr);
	return hr;
}

//
// 一要素の更新【符号なし8ビット整数型】
//    vpath      :タグ情報
//    array_size：配列サイズ
//    array_idx ：配列インデックス
//    value     ：値
//
//  戻り値      : =S_OK             (0) ;正常終了
//              : =S_FALSE          (1) ;異常終了
//              : =ERR_TAG_NAME     (3);タグ名のサイズが0
//              : =ERR_BASE64_COVERT(6);base64変換エラー
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, unsigned int array_size, unsigned int array_idx, unsigned char value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::X;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("X%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("X"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, array_size, array_idx, valtype, pstr);
	return hr;
}

//
//
//  戻り値      : =S_OK        (0) ;正常終了
//              : =S_FALSE     (1) ;異常終了
//              : =ERR_TAG_NAME(3);タグ名のサイズが0
//
HRESULT dataManage::setElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, unsigned int array_size, LPCTSTR valtype, LPCTSTR pstr)
{
	if (vpath.size() <= 0)
	{
		printf("タグ名がNULLです。FILE = %s , LINE = %d\n", __FILE__, __LINE__);
		return ERR_TAG_NAME;
	}

	HRESULT hr;

	// XMLデータ保存クラス	
	XmlData wrt = XmlData(&hr);
	if (FAILED(hr))
	{
		printf("Failed to instantiate an XML DOM.　FILE = %s , LINE = %d\n", __FILE__, __LINE__);
		return S_FALSE;
	}

	//ルートポインタ
	IElementPtr pRoot = wrt.getRootPtr();

	//messageタグを追加
	IElementPtr pMsg = wrt.addChild(pRoot, vpath.at(0));	//Messageタグ
	pMsg->setAttribute(TYPE_KY, msg_attr.type);				//Message Typeを設定
	if(msg_attr.name  != _bstr_t(L"")) pMsg->setAttribute(L"name", msg_attr.name);      //Message nameを設定
	if(msg_attr.cycle != _bstr_t(L"")) pMsg->setAttribute(L"cycle", msg_attr.cycle);    //Message cycleを設定
	if(msg_attr.a     != _bstr_t(L"")) pMsg->setAttribute(L"a", msg_attr.a);			//Messageタグにa属性を設定

	//　カテゴリータグ
	IElementPtr pChild = wrt.addChild(pMsg, vpath.at(1)); // 第１引数に親を指定
	IElementPtr pParent = pChild;

	//  タグ
	vector<_bstr_t>::iterator it = vpath.begin();
	int max_idx = vpath.size() - 1; //リストサイズ

	for (int i = 2; i < max_idx; i++)			//リストの構成要素の個数分ループ
	{
		pParent = pChild;
		pChild = wrt.addChild(pParent, vpath.at(i));
	}
	pParent = pChild;
	ElementData child = ElementData(vpath.at(max_idx), pstr);
	child.setAttribute(L"t", valtype);
	if (array_size>0)
	{
		child.setAttribute(L"i", attr.i);
	}
	if(attr.a  != _bstr_t(L"")) child.setAttribute(L"a" , attr.a);
	if(attr.c  != _bstr_t(L"")) child.setAttribute(L"c" , attr.c);
	if(attr.tm != _bstr_t(L"")) child.setAttribute(L"tm", attr.tm);
	IElementPtr pElem = wrt.addChild(pParent, &child);

	BSTR bstrXML;
	unsigned int dataID = SET_MAINDB;
	wrt.getXML(&bstrXML);
	addSetMsgData(dataID, &bstrXML);
	::SysFreeString(bstrXML);

	return S_OK;
}
////
////
////  戻り値      : =S_OK        (0) ;正常終了
////              : =S_FALSE     (1) ;異常終了
////              : =ERR_TAG_NAME(3);タグ名のサイズが0
////
//HRESULT dataManage::setElement(vector<_bstr_t>vpath, vector<ELEMATTRIBUTES>attr, MSGATTRIBUTES msg_attr, unsigned int array_size, LPCTSTR valtype, LPCTSTR pstr)
//{
//	if (vpath.size() <= 0)
//	{
//		printf("タグ名がNULLです。FILE = %s , LINE = %d\n", __FILE__, __LINE__);
//		return ERR_TAG_NAME;
//	}
//
//	HRESULT hr;
//
//	// XMLデータ保存クラス	
//	XmlData wrt = XmlData(&hr);
//	if (FAILED(hr))
//	{
//		printf("Failed to instantiate an XML DOM.　FILE = %s , LINE = %d\n", __FILE__, __LINE__);
//		return S_FALSE;
//	}
//
//	//ルートポインタ
//	IElementPtr pRoot = wrt.getRootPtr();
//
//	//messageタグを追加
////	IElementPtr pMsg = wrt.addChild(pRoot, vpath.at(0));  //Messageタグ
//	IElementPtr pMsg = wrt.addChild(pRoot, L"message");  //Messageタグ
//	pMsg->setAttribute(TYPE_KY, msg_attr.type);       //Message Typeを設定
//	pMsg->setAttribute(L"name", msg_attr.name);       //Message nameを設定
//	pMsg->setAttribute(L"cycle", msg_attr.cycle);       //Message cycleを設定
////	pMsg->setAttribute(L"a", attr.at(0).a);  //Messageタグにa属性を設定
//	pMsg->setAttribute(L"a", msg_attr.a);  //Messageタグにa属性を設定
//
//	//　カテゴリータグ
//	IElementPtr pChild = wrt.addChild(pMsg, vpath.at(0)); // 第１引数に親を指定
//	pChild->setAttribute(L"a", attr.at(0).a);  //タグにa属性を設定
//	IElementPtr pParent = pChild;
//
//	//  タグ
//	vector<_bstr_t>::iterator it = vpath.begin();
//	int max_idx = vpath.size() - 1; //リストサイズ
//
////	for (int i = 2; i < max_idx; i++)			//リストの構成要素の個数分ループ
//	for (int i = 1; i < max_idx; i++)			//リストの構成要素の個数分ループ
//	{
//		pParent = pChild;
//		pChild = wrt.addChild(pParent, vpath.at(i));
//		pChild->setAttribute(L"a", attr.at(i).a);  //タグにa属性を設定
//	}
//	pParent = pChild;
//	ElementData child = ElementData(vpath.at(max_idx), pstr);
//	child.setAttribute(L"t", valtype);
//	if (array_size>0)
//	{
//		TCHAR idx[BASE64_BUFFER_SIZE];
//		_stprintf_s(idx, _T("%d"), attr.at(max_idx).i);
//		child.setAttribute(L"i", idx);
//	}
//	child.setAttribute(L"a", attr.at(max_idx).a);
//	child.setAttribute(L"c", attr.at(max_idx).c);
//	IElementPtr pElem = wrt.addChild(pParent, &child);
//
//	BSTR bstrXML;
//	unsigned int dataID = SET_MAINDB;
//	wrt.getXML(&bstrXML);
//	addSetMsgData(dataID, &bstrXML);
//	::SysFreeString(bstrXML);
//
//	return S_OK;
//}
//
// 一要素の更新【double】
//    vpath      :タグ情報 messageから指定
//    attr      ：属性(ELEMATTRIBUTES) messageから指定
//    array_size：配列サイズ
//    value     ：値
//
//  戻り値      : =S_OK             (0) ;正常終了
//              : =S_FALSE          (1) ;異常終了
//              : =ERR_TAG_NAME     (3);タグ名のサイズが0
//              : =ERR_BASE64_COVERT(6);base64変換エラー
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, unsigned int array_size, double value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::R;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("R%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("R"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, attr, msg_attr, array_size, valtype, pstr);
	return hr;
}
//
// 一要素の更新【float】
//    vpath      :タグ情報 messageから指定
//    attr      ：属性(ELEMATTRIBUTES) messageから指定
//    array_size：配列サイズ
//    value     ：値
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, unsigned int array_size, float value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::SR;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("SR%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("SR"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, attr, msg_attr, array_size, valtype, pstr);
	return hr;
}
//
// 一要素の更新【long double】
//    vpath      :タグ情報 messageから指定
//    attr      ：属性(ELEMATTRIBUTES) messageから指定
//    array_size：配列サイズ
//    value     ：値
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, unsigned int array_size, long double value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::LR;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("LR%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("LR"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, attr, msg_attr, array_size, valtype, pstr);
	return hr;
}
//
// 一要素の更新【int】
//    vpath      :タグ情報 messageから指定
//    attr      ：属性(ELEMATTRIBUTES) messageから指定
//    array_size：配列サイズ
//    value     ：値
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, unsigned int array_size, int value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::I;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("I%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("I"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, attr, msg_attr, array_size, valtype, pstr);
	return hr;
}
//
// 一要素の更新【short】
//    vpath      :タグ情報 messageから指定
//    attr      ：属性(ELEMATTRIBUTES) messageから指定
//    array_size：配列サイズ
//    value     ：値
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, unsigned int array_size, short value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::SI;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("SI%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("SI"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, attr, msg_attr, array_size, valtype, pstr);
	return hr;
}
//
// 一要素の更新【long long】
//    vpath      :タグ情報 messageから指定
//    attr      ：属性(ELEMATTRIBUTES) messageから指定
//    array_size：配列サイズ
//    value     ：値
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, unsigned int array_size, long long value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::LI;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("LI%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("LI"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, attr, msg_attr, array_size, valtype, pstr);
	return hr;
}
//
// 一要素の更新【unsigned int】
//    vpath      :タグ情報 messageから指定
//    attr      ：属性(ELEMATTRIBUTES) messageから指定
//    array_size：配列サイズ
//    value     ：値
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, unsigned int array_size, unsigned int value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::UI;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("UI%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("UI"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, attr, msg_attr, array_size, valtype, pstr);
	return hr;
}
//
// 一要素の更新【unsigned short int】
//    vpath      :タグ情報 messageから指定
//    attr      ：属性(ELEMATTRIBUTES) messageから指定
//    array_size：配列サイズ
//    value     ：値
//(	GetXmlPath("Ctrl", "Rotor"), 
//::setAttributeACI(NULL, NULL, L"0"),
//setmsg_attr, 6, uw );
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, unsigned int array_size, unsigned short int value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::USI;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("USI%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("USI"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, attr, msg_attr, array_size, valtype, pstr);
	return hr;
}
//
// 一要素の更新【unsigned long long】
//    vpath      :タグ情報 messageから指定
//    attr      ：属性(ELEMATTRIBUTES) messageから指定
//    array_size：配列サイズ
//    value     ：値
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, unsigned int array_size, unsigned long long value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::ULI;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("ULI%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("ULI"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, attr, msg_attr, array_size, valtype, pstr);
	return hr;
}
//
// 一要素の更新【unsigned char】
//    vpath      :タグ情報 messageから指定
//    attr      ：属性(ELEMATTRIBUTES) messageから指定
//    array_size：配列サイズ
//    value     ：値
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, unsigned int array_size, unsigned char value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::X;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("X%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("X"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, attr, msg_attr, array_size, valtype, pstr);
	return hr;
}

//
// 一要素の更新【 char】
//    vpath      :タグ情報 messageから指定
//    attr      ：属性(ELEMATTRIBUTES) messageから指定
//    array_size：配列サイズ
//    value     ：値
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, unsigned int array_size, char value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::B;

	if (array_size > 0)	//属性t設定
	{
		_stprintf_s(valtype, _T("B%d"), array_size);
	}
	else
	{
		_tcscpy_s(valtype, _T("B"));
	}

	//　base64変換
	size_t outsize;
	TCHAR  pstr[BASE64_BUFFER_SIZE];
	Base64Data::encode(&value, dataType, pstr, &outsize);
	if (outsize == BASE64_BUFFER_SIZE || outsize >= BASE64_BUFFER_SIZE)
	{
		return ERR_BASE64_COVERT;	//変換FAIL
	}

	//　要素を追加
	HRESULT hr = setElement(vpath, attr, msg_attr, array_size, valtype, pstr);
	return hr;
}

//
// 一要素の更新【string】
//    vpath      :タグ情報 messageから指定
//    attr      ：属性(ELEMATTRIBUTES) messageから指定
//    array_size：配列サイズ
//    value     ：値
//
HRESULT dataManage::setOneElement(vector<_bstr_t>vpath, ELEMATTRIBUTES attr, MSGATTRIBUTES msg_attr, LPCTSTR value)
{
	TCHAR valtype[BASE64_BUFFER_SIZE];

	int dataType = Base64Data::S;

	_tcscpy_s(valtype, _T("S"));

	//　要素を追加
	HRESULT hr = setElement(vpath, attr, msg_attr, 0, valtype, value);
	return hr;
}
#pragma endregion set

//
// DBのIDを設定する
//    attr_a    ：messageタグのa属性の値
unsigned int dataManage::setDBID(BSTR attr_a)
{
	if (attr_a == NULL)
	{
		return SET_MAINDB;
	}
	else
	{
		//BSTR->string
		char* str = _com_util::ConvertBSTRToString(attr_a);
		unsigned int no = 0;
		map<unsigned int, string>::iterator it = dbIDMap.begin();
		while (it != dbIDMap.end())
		{
			if (strlen(str) == strlen((it->second).c_str())) //文字列一致
			{
				if (strcmp((it->second).c_str(), str) == 0)
				{
					delete[] str;
					return it->first;
				}
			}

			++it;
			++no;
		}
		//IDが登録されていないので、Mapに登録する
		dbIDMap.insert(make_pair(no, str));    //戻り値をみてからreturnしたほうがよいか？
		delete[] str;
		return no;
	}
}

//
// DBのIDを設定する
//    xml    ：xml message
unsigned int dataManage::setDBID(XmlMessage *xml)
{
	unsigned int dbID;

	IElementPtr pMsgElem = xml->pDoc->documentElement->GetchildNodes()->Getitem(0); //msgNoは0で固定してしまっている
	MSXML2::IXMLDOMNamedNodeMapPtr attNodePtr = pMsgElem->Getattributes();
	_bstr_t attA;  //messageタグのa属性
	VARIANT_BOOL bl = getAttA(attNodePtr, &attA);
	dbID = setDBID(attA);

	return dbID;
}

// 
//　setメッセージのクリア
//
//  　dataID ：データID
//  　msgID  ：メッセージID
//
//    戻り値    : =VARIANT_TRUE; clear
//              : =VARIANT_FALSE; clear
//
VARIANT_BOOL dataManage::clearSetMsg(unsigned int dataID, int msgID)
{
	VARIANT_BOOL result = VARIANT_FALSE;

	vector<XmlMessage>::iterator it = setList.data.begin();

	for (unsigned int i = 0; i<setList.data.size(); i++)
	{
		if (it->getDataID() == dataID)
		{
			MSXML2::IXMLDOMDocument2Ptr pXMLDom = it->pDoc;

			//ルート
			IElementPtr  pRoot = pXMLDom->documentElement;
			if (pRoot->hasChildNodes())
			{
				//message
				MSXML2::IXMLDOMNodeListPtr pMessage = pRoot->GetchildNodes();
				for (int iMsg = 0; iMsg < pMessage->Getlength(); iMsg++)
				{
					IElementPtr pMsgElem = pMessage->Getitem(iMsg);
					if (pMsgElem->hasChildNodes())
					{
						// msssageの子ノード
						MSXML2::IXMLDOMNodeListPtr pData = pMsgElem->GetchildNodes();
						int nData = pData->Getlength();
						for (int iData = 0; iData < nData; iData++)
						{
							IElementPtr pDataElem = pData->Getitem(iData);
							if (pDataElem->hasChildNodes())
							{
								MSXML2::IXMLDOMNodeListPtr pData2 = pDataElem->GetchildNodes();
								while (pData2->Getlength()>0)
								{
									IElementPtr pDataElem2 = pData2->Getitem(0);
									pDataElem->removeChild(pDataElem2);//クリア
								}
							}
						}
					}
				}
			}

			result = VARIANT_TRUE;
		}
		it++;
	}

	return result;
}

