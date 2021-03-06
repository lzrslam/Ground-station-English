#include "stdafx.h"
#include <tchar.h>
#include <vector> 
#import  <msxml6.dll>  // MSXMLライブラリのインポート  
using namespace std; 
using namespace std::tr1;

#include "XmlMessage.h"
#include "XmlMsgAttribute.h"

//
// XML形式のストリングをロードする
//ｴ�ｿｪﾒｻｸ�xmlﾎﾄｼ�
HRESULT XmlMessage::loadXmlMsg(BSTR quary)
{
	VARIANT_BOOL isSuccess = VARIANT_FALSE;

	//Create the XmlDocument
	// ｴｴｽｨDOMDocumentｶﾔﾏ�
	HRESULT hr  = pDoc.CreateInstance( __uuidof(MSXML2::DOMDocument60) );
    if (FAILED(hr)) 
    {
		printf("Failed to instantiate an XML DOM.\n");
        return S_FALSE; 
    }
	pDoc->async = VARIANT_FALSE;	

	//Load the XML string
	//ｼﾓﾔﾘXMLﾎﾄﾗﾖｷ�ｴｮ
	HRESULT hr1  = pDoc->raw_loadXML(quary, &isSuccess);
    if (FAILED(hr1)) 
	{
		MSXML2::IXMLDOMParseErrorPtr pErr;
		BSTR bstrErr = NULL;
		pDoc->get_parseError(&pErr);
		pErr->get_reason(&bstrErr);
		printf("XML DOM loaded errror \n",bstrErr);
		::SysFreeString(bstrErr);

		return S_FALSE; 
	} 

	//Get the message node
	 
	INodeListPtr pMsgList = pDoc->getElementsByTagName("message");
	IElementPtr  pMsg;

    int numMessage = pMsgList->Getlength(); //number of the messages
	MsgType msg = msgTypeErr;

    for(int i=0; i< numMessage; i++)
	{
		pMsg =  pMsgList->Getitem(i);	    //pointer of the message node

		// Check the parent node is root
		if(_tcscmp(pMsg->GetparentNode()->GetnodeName() , ROOT_KEY) == 0)
		{
			
			_variant_t att_type = pMsg->getAttribute("type");//get the type attribute

			if(_tcscmp((_bstr_t)att_type, L"set") == 0)
			{
				msg = msgSet;
			}
			else if(_tcscmp((_bstr_t)att_type, L"get") == 0)
			{
				msg = msgGet;
			}
			else if (_tcscmp((_bstr_t)att_type, L"close") == 0)
			{
				msg = msgClose;
			}
			else if (_tcscmp((_bstr_t)att_type, L"mainlink send") == 0)
			{
				msg = msgMainLink;
			}
			else
			{
				msg = msgTypeErr;
			}
			
			list_msg.push_back(msg);  //set the list of list_msg

			_variant_t cycle = pMsg->getAttribute("cycle");//get the type attribute
			if(cycle.vt == VT_NULL) 
			{
				list_cycle.push_back(DEFAULT_CYCLE);  //set the list of list_cycle	
			}
			else
			{
				//TODO: cycleが数値なのか判定処理要る
				cycle.ChangeType(VT_I4);
				list_cycle.push_back(cycle.intVal);  //set the list of list_cycle	
			}

			_variant_t name = pMsg->getAttribute("name");//get the type attribute
			list_name.push_back(name.bstrVal);  //set the list of list_name

			_variant_t atta = pMsg->getAttribute("a");//get the type attribute
			list_a.push_back(atta.bstrVal);  //set the list of list_a
		}
	}

	return S_OK;
}


//
// メッセージタイプを設定
//
int XmlMessage::setMsgType(int msgNo, int msg_type)
{
	int size = list_msg.size();

	if( size == 0 || size <= msgNo )
	{
		printf("第2引数が範囲を超えています。。FILE = %s , LINE = %d\n",__FILE__,__LINE__);
		return S_FALSE;
	}
	else
	{
		list_msg.at(msgNo) = msg_type;
		return S_OK;
	}

}

//
// メッセージタイプを返す
//
int XmlMessage::getMsgType(int msgNo)
{
	int size = list_msg.size();

	if( size == 0 || size <= msgNo )
	{
		printf("message文のtypeが不適切です。 ");
		printf("message文が整形でない可能もあります。\n");
		return msgTypeErr;
	}
	else
	{
		return list_msg.at(msgNo);
	}

}

//
// a属性を返す
//
_bstr_t XmlMessage::getMsgAttA(int msgNo)
{

	int size = list_a.size();

	if( size == 0 || size <= msgNo )
	{
		return L"";
	}
	else
	{
		return list_a.at(msgNo);
	}

}
//
// IDを返す
//
unsigned int XmlMessage::getDataID()
{
	return dataID;
}

//
// name属性を返す
//
BSTR XmlMessage::getName(int Idx)
{
	int size = list_name.size();

	if( size == 0 || size <= Idx)
	{
		return NULL;
	}
	else
	{
		return list_name.at(Idx);
	}

}

//
// cycyle属性を返す
//
int XmlMessage::getCycle(int Idx)
{
	int size = list_cycle.size();

	if( size == 0 || size <= Idx)
	{
		return DEFAULT_CYCLE; //TODO:デフォルト50Hzを返すので良いか？
	}
	else
	{
		return list_cycle.at(Idx);
	}

}

//
// name属性が同じものがあるか判定
//
VARIANT_BOOL XmlMessage::hasSameName(BSTR name, unsigned int *listIdx)
{

	int size = list_name.size();

	if(!list_name.empty()) //if list has elements then do
	{
		vector<_bstr_t>::iterator it = list_name.begin(); 

		for(int i=0; i < size; i++)
		{
			if(SysStringLen(list_name.at(i))>0 && SysStringLen(name)>0)
			{
				if(wcscmp(list_name.at(i), name)==0)
				{
					*listIdx = i;
					return VARIANT_TRUE;	//TRUE
				}
			}
			else if(SysStringLen(list_name.at(i))==0 && SysStringLen(name)==0)
			{
				*listIdx = i;
				return VARIANT_TRUE;	//TRUE

			}
			++it;
		}
	}
	return VARIANT_FALSE;	
}

//
// 
//

VARIANT_BOOL XmlMessage::removeEachDisenable(const MSXML2::IXMLDOMNodePtr pParent)
{

	int remove = 0;	//削除回数
	int num = -1;

	_bstr_t name = pParent->parentNode->GetnodeName(); //親ノードの名前

	if(pParent->hasChildNodes())
	{
		INodeListPtr pNodes = pParent->GetchildNodes();

		num = pNodes->Getlength();
		for(int iNode = 0 ; iNode < num; iNode++)	//子ノードの数だけループ
		{
			//pParentの親がmessageの場合、タグ自体はremoveしないで子ノードをremove
			INamedNodeMapPtr attPtrP = pParent->Getattributes();
			if (_tcscmp(name, L"message") == 0 && !getAttSendValue(attPtrP))
			{
				IElementPtr pChild = pNodes->Getitem(iNode - remove);  //子ノードを削除
				pParent->removeChild(pChild);
				remove++;
			}
			else{
				IElementPtr pChild = pNodes->Getitem(iNode - remove);

				if (pChild != NULL)
				{
					INamedNodeMapPtr attPtr = pChild->Getattributes();
					if (!getAttSendValue(attPtr)) //属性 sendがdisabledならば
					{						
						//removeする
						IElementPtr x = pParent->removeChild(pChild);
						remove++;
					}
					else//enabledならば
					{
						BOOL flg = FALSE;
						if (pChild->GetchildNodes()->Getitem(0)){
							flg = TRUE;
						}

						removeEachDisenable(pChild);	//次の下位ノードを調査

						if (!pChild->GetchildNodes()->Getitem(0) && flg == TRUE){  //pChildの子ノードが1つも無い＆removeする前は子ノードがあった場合
							pParent->removeChild(pChild);
							remove++;
						}
					}
				}
			}
		}
	}
	
	if (_tcscmp(name, L"message") == 0) //messageタグの子ノードの場合
	{
		MSXML2::IXMLDOMNamedNodeMapPtr attNodePtr = pParent->Getattributes();
		if (!getAttSendValue(attNodePtr))  //disable
		{
			//そのまま　send属性は消さない
		}
		else{
			//子ノードが元はあったが全てremoveされた場合ー＞disable
			if (remove > 0 && !pParent->GetchildNodes()->Getitem(0))
			{
				if (attNodePtr->length >0)	//属性がある？
				{
					MSXML2::IXMLDOMNodePtr pSend = attNodePtr->getNamedItem(L"send");
					if (pSend != NULL) // 属性sendはある？
					{
						pSend->put_text(L"disabled");
					}
				}
				//無いので属性を追加する
				MSXML2::IXMLDOMAttributePtr att = pDoc->createAttribute(L"send");
				att->put_text(L"disabled");
				attNodePtr->setNamedItem(att);
			}
			//子ノードが元からない場合ー＞enable
			//そのまま
		}
	}
	else
	{
		INamedNodeMapPtr attPtr = pParent->Getattributes();
		attPtr->removeNamedItem("send");
	}


	return VARIANT_TRUE; // not found
	
}

//
//  
//
void XmlMessage::removeDisenable()
{

	IElementPtr  pRoot   = pDoc->documentElement;//setメッセージのルートポインタ

	//Debug
	//printf("\n remove前\n");
	//printf(pDoc->Getxml());

	if(pRoot->hasChildNodes())	//ルート直下に子ノードがある？
	{
		INodeListPtr pMessage = pRoot->GetchildNodes();
		int msgNum = pMessage->Getlength();	

		for(int iMsg = 0; iMsg < msgNum; iMsg++)		    //messageの数だけループ
		{
			IElementPtr pMsgElem = pMessage->Getitem(iMsg);	//message要素

			if(pMsgElem->hasChildNodes())				    //message直下に子ノードがある？
			{
				INodeListPtr pNodes = pMsgElem->GetchildNodes();
				for(int iNode = 0; iNode < pNodes->Getlength(); iNode++)//ノードの数だけループ
				{
					INodePtr pChild = pNodes->Getitem(iNode);//子ノード
					removeEachDisenable(pChild);
				}
			}	
		}

		//Debug
		//printf("\n remove後\n");
		//printf(pDoc->Getxml());
	}
}
