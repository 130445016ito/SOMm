///
/// @file  Packet.h
/// @brief 受信パケット解析用構造体群
///

#pragma once

#include"Table.h"

namespace lp_wsm
{
	///
	/// @brief 受信パケットの基本構造体です。
	///
	struct Packet
	{
		unsigned char smid; ///< センサモジュールID
		unsigned char pid;  ///< プロダクトID
		unsigned char code; ///< 応答コード

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// 引数はコールバック関数の引数をそのまま利用してください。
		///
		/// @param buffer 受信パケットのバッファ
		/// @param size   バッファのサイズ
		///
		Packet(unsigned char *buffer, int size);
		///
		/// @brief デフォルトコンストラクタです。
		///
		Packet();
	};

	///
	/// @brief ACKパケット構造体です。
	///
	struct Ack : Packet
	{
		unsigned char status; ///< ACKステータス

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// 引数はコールバック関数の引数をそのまま利用してください。
		///
		/// @param buffer 受信パケットのバッファ
		/// @param size   バッファのサイズ
		///
		__declspec(dllexport) Ack(unsigned char *buffer, int size);
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) Ack();
	};

	///
	/// @brief ステータス情報取得のデータパケット構造体です。
	///
	struct DatGetStatus : Packet
	{
		unsigned char hh;                ///< 計測時間(h)
		unsigned char mm;                ///< 計測時間(m)
		unsigned char ss;                ///< 計測時間(s)
		unsigned short freq;             ///< サンプリング周波数
		unsigned char ch;                ///< 無線チャンネル
		unsigned char serial_no[5];      ///< シリアル番号
		unsigned char hw_ver[5];         ///< ハードウェアバージョン
		unsigned char uniq_config[15];   ///< センサモジュール固有設定
		unsigned char default_calib[16]; ///< デフォルトキャリブレーションキー
		unsigned char user_calib[16];    ///< ユーザーキャリブレーションキー
		unsigned int  mem_addr;          ///< メモリアドレス
		unsigned char num_files;         ///< メモリ内ファイル数
		unsigned char battery;           ///< バッテリ値
		unsigned char comm_path;         ///< 通信経路(RF[0x00] or UART[0x01])
		unsigned char cpu_temp;          ///< CPU温度

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// 引数はコールバック関数の引数をそのまま利用してください。
		///
		/// @param buffer 受信パケットのバッファ
		/// @param size   バッファのサイズ
		///
		__declspec(dllexport) DatGetStatus(unsigned char *buffer, int size);
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) DatGetStatus();
	};

	///
	/// @brief 計測開始のデータパケット構造体です。
	///
	struct DatStartMeasure : Packet
	{
		unsigned char  battery;     ///< バッテリ電圧
		unsigned short seq;         ///< シーケンス番号
		unsigned char  data[5][18]; ///< 計測データ

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// 引数はコールバック関数の引数をそのまま利用してください。
		///
		/// @param buffer 受信パケットのバッファ
		/// @param size   バッファのサイズ
		///
		__declspec(dllexport) DatStartMeasure(unsigned char *buffer, int size);
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) DatStartMeasure();
	};

	///
	/// @brief 9軸ワイヤレスモーションセンサ（小型、防水、GPS+9軸）の計測データ構造体です。
	///
	struct WmsData
	{
		short          mag[3]; ///< 地磁気
		unsigned short acc[3]; ///< 加速度
		unsigned short ang[3]; ///< 角速度

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// @param data 計測データパケットの計測データ部（1サンプリング）
		/// @param pid  プロダクトID<br>
		///             （5G/300dps仕様の場合は指定してください）
		///
		__declspec(dllexport) WmsData(unsigned char data[18], unsigned char pid = 0x00);
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) WmsData();
	};

	///
	/// @brief ワイヤレスEMGロガーの計測データ構造体です。
	///
	struct EmgData
	{
		short acc[3];  ///< 加速度
		short emg[2];  ///< EMG
		short iemg[2]; ///< IEMG

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// @param data 計測データパケットの計測データ部（1サンプリング）
		///
		__declspec(dllexport) EmgData(unsigned char data[18]);
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) EmgData();
	};

	///
	/// @brief ワイヤレスECGロガーの計測データ構造体です。
	///
	struct EcgData
	{
		int ecg; ///< 心電（上位3バイト）

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// @param data 計測データパケットの計測データ部（1サンプリング）
		///
		__declspec(dllexport) EcgData(unsigned char data[18]);
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) EcgData();
	};

	///
	/// @brief ワイヤレスGSRロガーの計測データ構造体です。
	///
	struct GsrData
	{
		int eda_v; ///< 皮膚電位（電位法計測、上位3バイト）
		int eda_c; ///< 皮膚電位（電流法計測、上位3バイト）

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// @param data 計測データパケットの計測データ部（1サンプリング）
		///
		__declspec(dllexport) GsrData(unsigned char data[18]);
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) GsrData();
	};

	///
	/// @brief ワイヤレス6chロガーの計測データ構造体です。
	///
	struct W6chData
	{
		short          acc[3];          ///< 加速度
		unsigned short analog_input[6]; ///< アナログ入力1～6

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// @param data 計測データパケットの計測データ部（1サンプリング）
		///
		__declspec(dllexport) W6chData(unsigned char data[18]);
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) W6chData();
	};

	///
	/// @brief ワイヤレス筋電センサの計測データ構造体です。
	///
	struct MyoData
	{
		short          eda;    ///< 皮膚電位（電位法計測）
		unsigned short acc[3]; ///< 加速度

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// @param data 計測データパケットの計測データ部（1サンプリング）
		///
		__declspec(dllexport) MyoData(unsigned char data[18]);
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) MyoData();
	};

	///
	/// @brief GPSセンサの計測データ構造体です。
	///
	struct GpsData
	{
		bool          type_gps;		///< 受信パケットがGPSデータかどうか
		unsigned char gps_length;   ///< GPSセンテンス長
		char          nmea[90];     ///< NMEA形式文字列
		char          name[8];		///< "$GPGGA"
		double        m1;           ///< UTC時刻
		double        m2;           ///< 緯度
		char          c1;           ///< 緯度方向(N or S)
		double        m3;           ///< 経度
		char          c2;           ///< 経度方向(E or W)
		int           d1;           ///< 0=未測位,1=測位中,2=RTCMまたはSBASdifferential測位中
		int           d2;           ///< 補足衛星数
		double        f1;           ///< 水平測位誤差
		double        f2;           ///< 海抜高度
		char          M1;           ///< 海抜高度の単位
		double        f3;           ///< ジオイド高度
		char          M2;           ///< ジオイド高度の単位
		int           d3;           ///< DGPS補正データの取得後の経過時間
		int           d4;           ///< DGPS基地局ID
		unsigned char cc;           ///< チェックサム

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// @param data 計測データパケットの計測データ部（1サンプリング）
		///
		__declspec(dllexport) GpsData(unsigned char (*data)[18]);
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) GpsData();

		///
		/// @brief 受信パケットがGPSデータかどうかを取得します。
		///
		/// @param  data 受信パケットのデータ部<br>
		/// @return 受信パケットがGPSデータであればtrue
		///
		__declspec(dllexport) static bool isGpsData(unsigned char (*data)[18]);
	};

	///
	/// @brief 同期番号呼び出しのデータパケット構造体です。
	///
	struct DatReadSync : Packet
	{
		unsigned char file_no;       ///< ファイル番号
		unsigned char packet_no;     ///< パケットシーケンス
		unsigned char packet_num;    ///< パケットシーケンス最終(最大7)
		unsigned char seq_num;       ///< パケット内の有効シーケンス(最大16)
		unsigned char sync_no[16];   ///< 同期番号
		unsigned int  sample_no[16]; ///< 同期番号のサンプリング数

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// 引数はコールバック関数の引数をそのまま利用してください。
		///
		/// @param buffer 受信パケットのバッファ
		/// @param size   バッファのサイズ
		///
		__declspec(dllexport) DatReadSync(unsigned char *buffer, int size);
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) DatReadSync();
	};

	///
	/// @brief ファイル情報取得のデータパケット構造体です。
	///
	struct DatGetFileInfo : Packet
	{
		unsigned char  file_no;         ///< ファイル番号
		unsigned char  file_num;        ///< 全ファイル数
		unsigned short freq;            ///< 計測時サンプリング周波数
		unsigned char  YY;              ///< 計測開始時刻(Y)
		unsigned char  MM;              ///< 計測開始時刻(M)
		unsigned char  DD;              ///< 計測開始時刻(D)
		unsigned char  hh;              ///< 計測開始時刻(h)
		unsigned char  mm;              ///< 計測開始時刻(m)
		unsigned int   sample_num;      ///< サンプリング数
		unsigned char  calib[16];       ///< 計測時キャリブレーションキー
		unsigned char  uniq_config[15]; ///< 計測時センサモジュール固有設定

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// 引数はコールバック関数の引数をそのまま利用してください。
		///
		/// @param buffer 受信パケットのバッファ
		/// @param size   バッファのサイズ
		///
		__declspec(dllexport) DatGetFileInfo(unsigned char *buffer, int size);
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) DatGetFileInfo();
	};

	///
	/// @brief ファイル情報取得2のデータパケット構造体です。
	///
	struct DatGetFileInfo2 : Packet
	{
		unsigned char  file_no;         ///< ファイル番号
		unsigned char  file_num;        ///< 全ファイル数
		char           file_name[14];   ///< ファイル名
		unsigned short freq;            ///< 計測サンプリング周波数
		unsigned char  YY;              ///< 計測開始時刻(Y)
		unsigned char  MM;              ///< 計測開始時刻(M)
		unsigned char  DD;              ///< 計測開始時刻(D)
		unsigned char  hh;              ///< 計測開始時刻(h)
		unsigned char  mm;              ///< 計測開始時刻(m)
		unsigned int   sample_num;      ///< サンプリング数
		unsigned char  calib[16];       ///< 計測時キャリブレーションキー
		unsigned char  uniq_config[15]; ///< 計測時センサモジュール固有設定

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// 引数はコールバック関数の引数をそのまま利用してください。
		///
		/// @param buffer 受信パケットのバッファ
		/// @param size   バッファのサイズ
		///
		__declspec(dllexport) DatGetFileInfo2(unsigned char *buffer, int size);
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) DatGetFileInfo2();
	};

	///
	/// @brief ファイルデータ取得のデータパケット構造体です。
	///
	struct DatReadFile : Packet
	{
		unsigned int  packet_no;   ///< パケット番号
		unsigned char size;        ///< ファイルデータの格納数(1～4)
		unsigned char data[4][18]; ///< ファイルデータ

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// 引数はコールバック関数の引数をそのまま利用してください。
		///
		/// @param buffer 受信パケットのバッファ
		/// @param size   バッファのサイズ
		///
		__declspec(dllexport) DatReadFile(unsigned char *buffer, int size);
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) DatReadFile();
	};

	///
	/// @brief ファイルデータ取得2のデータパケット構造体です。
	///
	struct DatReadFile2 : Packet
	{
		unsigned int packet_no;  ///< パケット番号
		unsigned int packet_num; ///< パケット総数
		unsigned char size;      ///< 有効データ
		unsigned char data[86];  ///< データ

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// 引数はコールバック関数の引数をそのまま利用してください。
		///
		/// @param buffer 受信パケットのバッファ
		/// @param size   バッファのサイズ
		///
		__declspec(dllexport) DatReadFile2(unsigned char *buffer, int size);
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) DatReadFile2();
	};

	///
	/// @brief ファイルコメント取得のデータパケット構造体です。
	///
	struct DatReadComment : Packet
	{
		char          comment[65]; ///< コメントデータ
		unsigned char file_no;     ///< ファイル番号

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// 引数はコールバック関数の引数をそのまま利用してください。
		///
		/// @param buffer 受信パケットのバッファ
		/// @param size   バッファのサイズ
		///
		__declspec(dllexport) DatReadComment(unsigned char *buffer, int size);
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) DatReadComment();
	};

	///
	/// @brief ファイルコメント書き込みのデータパケット構造体です。
	///
	struct DatWriteComment : Packet
	{
		char          comment[65]; ///< 成功した書き込みデータ
		unsigned char file_no;     ///< ファイル番号

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// 引数はコールバック関数の引数をそのまま利用してください。
		///
		/// @param buffer 受信パケットのバッファ
		/// @param size   バッファのサイズ
		///
		__declspec(dllexport) DatWriteComment(unsigned char *buffer, int size);
		///
		/// デフォルトコンストラクタです。
		///
		__declspec(dllexport) DatWriteComment();
	};

	///
	/// @brief 外部接続機器固有設定読み込みのデータパケット構造体です。
	///
	struct DatGetExDevice : Packet
	{
		unsigned char target;      ///< 対象機器
		unsigned short sub;        ///< サブ項目
		unsigned char config_size; ///< 有効バイト数
		unsigned char config[64];  ///< 固有設定

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// 引数はコールバック関数の引数をそのまま利用してください。
		///
		/// @param buffer 受信パケットのバッファ
		/// @param size   バッファのサイズ
		///
		__declspec(dllexport) DatGetExDevice(unsigned char *buffer, int size);
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) DatGetExDevice();
	};

	///
	/// @brief シリアル番号取得のデータパケット構造体です。
	///
	struct DatGetSerial : Packet
	{
		unsigned char serial_no[5]; ///< シリアル番号

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// 引数はコールバック関数の引数をそのまま利用してください。
		///
		/// @param buffer 受信パケットのバッファ
		/// @param size   バッファのサイズ
		///
		__declspec(dllexport) DatGetSerial(unsigned char *buffer, int size);
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) DatGetSerial();
	};

	///
	/// @brief ファームウェアバージョン取得のデータパケット構造体です。
	///
	struct DatGetFwVer : Packet
	{
		unsigned char fw_ver[5]; ///< ファームウェア番号

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// 引数はコールバック関数の引数をそのまま利用してください。
		///
		/// @param buffer 受信パケットのバッファ
		/// @param size   バッファのサイズ
		///
		__declspec(dllexport) DatGetFwVer(unsigned char *buffer, int size);
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) DatGetFwVer();
	};

	///
	/// @brief ハードウェアバージョン取得のデータパケット構造体です。
	///
	struct DatGetHwVer : Packet
	{
		unsigned char hw_ver[5]; ///< ハードウェアバージョン番号

		///
		///	@brief 自動的にメンバを求めるコンストラクタです。
		///
		/// 引数はコールバック関数の引数をそのまま利用してください。
		///
		/// @param buffer 受信パケットのバッファ
		/// @param size   バッファのサイズ
		///
		__declspec(dllexport) DatGetHwVer(unsigned char *buffer, int size);
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) DatGetHwVer();
	};
}
