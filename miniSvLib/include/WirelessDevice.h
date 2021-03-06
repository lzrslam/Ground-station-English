///
/// @file       WirelessDevice.h
///
/// @brief      無線デバイスクラスの基本定義
///
///             無線デバイスクラスの役割：
///             上位のオブジェクトに対し、無線デバイス毎に定義されるコマンド等を意識せず相手とデータ交換可能
///             にするインターフェースを提供する。
///               送信：
///                   送信データ列を無線デバイス専用のフォーマットに変換し、シリアル通信クラスにデータを渡す
///               受信：
///                   無線デバイス専用のヘッダ・フッタが付いたデータ列からヘッダ・フッタを除去する
///
///             ・エラー検出はサポートしない（今後見直すかも。無線デバイスクラス側でヘッダ、チェックサムをつけるほうが効率的）
///             ・再送はサポートしない
///             ・やむを得ない場合はH/W依存のコードで実装してもよいが、H/W毎に実装が必要になるため非推奨
///
/// @author     iwakura
///
/// 関係図：
///
/// ┌────────────┐　　　　　　　　　　　　┌────────────┐
/// │上位オブジェクト　　　　│　　　　　　　　　　　　│上位オブジェクト　　　　│
/// │役割：データ列の生成　　│　　　　　　　　　　　　│役割：データ列の生成　　│
/// └────────────┘　　　　　　　　　　　　└────────────┘
/// 　　　　　↓　　↑　　　　　　　　　　　　　　　　　　　　　　↓　　↑　Send, Receive, Flush
/// ┌────────────┐　　　　　　　　　　　　┌────────────┐
/// │無線デバイスクラス　　　│　　　　　　　　　　　　│無線デバイスクラス　　　│《無線装置に依存するコマンド部を吸収》
/// └────────────┘　　　　　　　　　　　　└────────────┘
/// 　　　　　↓　　↑　　　　　　　　　　　　　　　　　　　　　　↓　　↑　Write, Read
/// ┌────────────┐　　　　　　　　　　　　┌────────────┐
/// │シリアル通信Ｉ／Ｆ　　　│　　　　　　　　　　　　│シリアル通信Ｉ／Ｆ　　　│《計算機に依存する部分を吸収》
/// └────────────┘　　　　　　　　　　　　└────────────┘
/// 　　　　　↓　　↑　　　　　　　　　　　　　　　　　　　　　　↓　　↑　レジスタ制御(MCU)／API(PC)
/// ┌────────────┐　　　　　　　　　　　　┌────────────┐
/// │ＵＡＲＴ（ＭＣＵ／ＰＣ）│　　　　　　　　　　　　│ＵＡＲＴ（ＭＣＵ／ＰＣ）│
/// └────────────┘　　　　　　　　　　　　└────────────┘
/// 　　　　　↓　　↑　　　　　　　　　　　　　　　　　　　　　　↓　　↑　TX, RX (物理線）
/// ┌────────────┐　　　　　　　　　　　　┌────────────┐
/// │無線デバイス　　　　　　│←──（無線区間）──→│無線デバイス　　　　　　│
/// └────────────┘　　　　　　　　　　　　└────────────┘
///

#ifndef INCLUDED_WIRELESSDEVICE_H
#define INCLUDED_WIRELESSDEVICE_H

#include "Common/StandardDef.h"

struct TimingInfo
{
	float MaxCommunicationTime;     // オブジェクトに最大長のデータ列を入力してから無線区間が開放されるまでの時間
	float MinCommunicationTime;     // オブジェクトに空のデータ列を入力してから無線区間が開放されるまでの時間
	float CommunicationTimePerByte; // 1バイトにつき延長される通信時間
};

class WirelessDevice
{
public:
	/*
	// 未実装
	enum COMMAND
	{
		GET_VERSION             = 0x01, // デバイスのバージョン情報を取得する  戻り値：char[32] ex."1.001"
		GET_PRODUCTNAME         = 0x02, // 製品名／シリーズ名を取得する　　　　戻り値：char[32] ex."FEP Series"
		GET_MANUFACTURER        = 0x03, // メーカー名を取得する　　　　　　　　戻り値：char[32] ex."Futaba"
		GET_SERIALNUMBER        = 0x04, // 個体番号を取得する　　　　　　　　　戻り値：char[32] ex."121100034"
		GET_BAND_FREQUENCY      = 0x05, // 周波数帯域を取得する                戻り値：uint32   ex."920MHz"
		GET_CHANNELS            = 0x06, // チャンネル番号を取得する　　　　　　戻り値：char[32] ex."24,26,28"
		GET_OWN_ADDRESS         = 0x07, // 自身のアドレスを取得する 　　       戻り値：char[32] ex."5A"
		GET_DESTINATION_ADDRESS = 0x08, // 相方のアドレスを取得する　　　　　　戻り値：char[32] ex."5B"
	};
	*/
	
protected:

	_UBYTE m_PortNo;

public:

	///
	/// @brief  コンストラクタ
	///
	/// @param[in] PortNo  シリアル通信のポート番号
	///
	WirelessDevice(_UBYTE PortNo) : m_PortNo(PortNo) {}

	///
	/// @brief  デストラクタ
	///
	virtual ~WirelessDevice() {}

	///
	/// @brief  オブジェクトを初期化します
	///         本関数を実行しても、IsReady()が false を返し続ける間は通信ができません
	///
	/// @param[in] Baudrate  ボーレート
	///                      0を指定すると自動選択される
	/// @return  C_OK     - 成功
	///          C_FAIL等 - 失敗
	///
	virtual CRESULT Initialize(_UDWORD Baudrate = 0) = 0;

	///
	/// @brief  オブジェクトの内部状態の更新を行います
	///         周期的に本関数を実行してください 
	///         デバイスに初期設定が必要な場合は、本関数内部で初期設定を行います
	///         オブジェクトのビジー状態の解除は本関数を実行することで行われます
	///
	/// @return  なし
	///
	virtual void Update() = 0;

	///
	/// @brief  オブジェクトが利用可能になっているか調べます
	///
	/// @return  true  - 通信可能
	///          false - 初期設定中のため、通信不可能
	///
	virtual bool IsReady() = 0;

	/// 送信がビジー状態か調べる関数（仮）
	virtual bool IsTxBusy() = 0;

	///
	/// @brief  連続データの送信を開始するため、オブジェクトにこれから Send されるデータの量を通知します
	///         バッファが足りないなどの理由により、指定したバイト数を届けられない場合はエラーを返します
	///         オブジェクトは無線デバイスが規定するヘッダを送出する場合があります
	///
	/// @param[in] TotalLength  SendBegin() 〜 SendEnd() までにオブジェクトに送られるデータ量
	///
	/// @return  C_OK          - 送信可能
	///          C_OUTOFBUFFER - 指定したサイズのデータがバッファに収まりません。Flush()を実行してから、
	///                          Update()を実行し、送信可能になるまで待機してください。
	///          C_BUSY        - 一時的に送信ができない状態にあります。Update()を実行し、送信可能になる
	///                          まで待機してください。
	///          C_FAIL等      - 送信不可能
	///
	virtual CRESULT SendBegin(size_t TotalLength) = 0;
	
	///
	/// @brief  1バイト送信します
	///         SendBegin() と SendEnd() の間で関数を呼んでください
	///         エスケープ処理等によりバッファが足りなくなった場合、エラーを返すことがあります
	///         エラーが返ってきたら再度 SendBegin が呼ばれるまで送信できません
	///
	/// @param[in] data  送信
	///
	/// @return  C_OK     - 送信成功
	///          C_FAIL等 - 送信失敗
	///
	virtual CRESULT Send(_UBYTE data) = 0;
	
	///
	/// @brief  複数バイト送信します
	///         SendBegin() と SendEnd() の間で関数を呼んでください
	///         エスケープ処理等によりバッファが足りなくなった場合、エラーを返すことがあります
	///         エラーが返ってきたら再度 SendBegin が呼ばれるまで送信できません
	///
	/// @param[in] pData   データ配列のポインタ
	/// @param[in] length  データ配列のサイズ
	///
	/// @return  C_OK     - 送信成功
	///          C_FAIL等 - 送信失敗
	///
	virtual CRESULT Send(const void* pData, size_t length) = 0;

	///
	/// @brief  連続データの送信を完了します
	///         Send()で一連のデータを送ったあとに呼んでください
	///         エスケープ処理等によりバッファが足りなくなった場合、エラーを返すことがあります
	///         オブジェクトは無線デバイスが規定するフッタを送出する場合があります
	///
	/// @param[in] data  送信
	///
	/// @return  C_OK     - 送信成功
	///          C_FAIL等 - 送信失敗
	///
	virtual CRESULT SendEnd() = 0;

	///
	/// @brief  デバイスの送信バッファまたはオブジェクトの送信バッファにあるデータ列を転送するためのトリガを送出します
	///         SendBegin() 〜 SendEnd() を繰り返したあとに一度、本関数を実行してください
	///         デバイスがサポートしていなければ C_UNSUPPORTED が返ります
	///         オブジェクトはSend()系の関数で内部バッファにデータを格納し、Flush()のタイミングでバースト送出する場合があります
	///
	/// @return  C_OK          - トリガ送出成功
	///          C_UNSUPPORTED - デバイスはトリガをサポートしていません
	///          C_FAIL等      - トリガ送出失敗
	///
	virtual CRESULT Flush() = 0;

	///
	/// @brief  1バイトデータを取得します
	///         基本的に無線デバイスが規定するコマンドおよびその応答は出力されません
	///         取得できるデータが存在しない場合はエラーが返ります
	///         無線デバイスが受信に呼応してバックグラウンドで通信を行う場合、関数実行後にオブジェクトが一時的に送信ビジー状態になる場合があります
	///
	/// @param[out] pData  取得したデータの格納先
	///
	/// @return  C_OK     - 取得成功
	///          C_FAIL等 - 取得失敗
	///
	virtual CRESULT Receive(_UBYTE* pData) = 0;

	///
	/// @brief  1バイトデータが取得可能か調べます
	///         基本的に無線デバイスが規定するコマンドおよびその応答は出力されません
	///         取得できるデータが存在しない場合は false が返ります
	///         無線デバイスが受信に呼応してバックグラウンドで通信を行う場合、関数実行後にオブジェクトが一時的に送信ビジー状態になる場合があります
	///
	/// @return  true  - 取得可能
	///          false - 取得不可能
	///
	virtual bool IsDataReceived() = 0;
	
	///
	/// @brief  パケットデータとして処理されなかったデータをオブジェクトに処理させます
	///         デバイス依存のデータは極力オブジェクトが吸収しますが、デバイスの仕様上不可能な場合があります。
	///         その場合は上位でゴミデータとして検出し、そのゴミデータを本関数に入力してください。
	///         オブジェクトは内部で受信強度データ等の意味のあるデータへのデコードを行います。
	///
	/// @return  なし
	///
	virtual void ProcessUnusedCharacter(_UBYTE c) = 0;
	
	///
	/// @brief  最新の電界強度データを取得します
	///         デバイスがサポートしていなければ C_UNSUPPORTED が返ります
	///
	/// @param[out] pRssi  dBm単位の電界強度からマイナス符号を取った値（-100dBm → 値=100）
	///
	/// @return C_OK          - 取得成功
	///         C_NODATA      - 電界強度データはまだ取得されていません
	///         C_UNSUPPORTED - デバイスは電界強度データの取得をサポートしていません
	///
	virtual CRESULT GetRssi(_UBYTE* pRssi) const = 0;

	///
	/// @brief  指定したバイト数のパケット往復に要する時間をミリ秒単位で取得します
	///         受信から送信に至るまでの遅れは含まれません
	///         受信側が一定周期で受信データを監視する実装の場合、実際の往復時間は関数が返す値に監視の間隔が上乗せされたものとなります。
	///         無線デバイスの状態によって、関数が返す値は変動することがあります。
	///         
	/// @param[in] TxBytes  送信バイト数　省略すると送信可能な最大値で計算されます。
	/// @param[in] RxBytes  受信バイト数（受信側が送信したバイト数）省略すると送信可能な最大値で計算されます。
	///
	/// @return  往復に要する時間
	///
	virtual _UWORD GetRoundTripTime(size_t TxBytes = (size_t)-1, size_t RxBytes = (size_t)-1) const = 0;
};


#endif 