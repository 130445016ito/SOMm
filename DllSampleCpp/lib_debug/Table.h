///
/// @file  Table.h
/// @brief 定数値群
///

#pragma once

namespace lp_wsm
{
	///
	/// @brief プロダクトIDの定数値です。
	///
	enum EProductId : unsigned char
	{
		PID_WMS_50_1500  = 0x01, ///< 9ワイヤレスモーションセンサ(50G/1500dps)
		PID_EMG          = 0x02, ///< ワイヤレスEMGロガー
		PID_WMS_5_300    = 0x03, ///< 9ワイヤレスモーションセンサ(5G/300dps)
		//rsv             = 0x04,
		PID_WMS_HS       = 0x05, ///< 9ワイヤレスモーションセンサ(HighSpeed仕様)
		//rsv             = 0x06,
		//rsv             = 0x07,
		//rsv             = 0x08,
		PID_WMS2_50_1500 = 0x09, ///< 9軸ワイヤレスモーションセンサ2(50G/1500dps)
		PID_WMS2_5_30    = 0x0A, ///< 9軸ワイヤレスモーションセンサ2(5G/30dps)
		PID_WMS2_5_1500  = 0x0B, ///< 9軸ワイヤレスモーションセンサ2(5G/1500dps)
		PID_WMS2_16_1500 = 0x0C, ///< 9軸ワイヤレスモーションセンサ2(16G/1500dps)
		PID_SWMS_50_1500 = 0x0D, ///< 小型9軸ワイヤレスモーションセンサ(50G/1500dps)
		PID_SWMS_5_300   = 0x0E, ///< 小型9軸ワイヤレスモーションセンサ(5G/300dps)
		PID_SWMS_5_1500  = 0x0F, ///< 小型9軸ワイヤレスモーションセンサ(5G/1500dps)
		PID_SWMS_16_1500 = 0x10, ///< 小型9軸ワイヤレスモーションセンサ(16G/1500dps)
		PID_SWMS_HS      = 0x11, ///< 小型9軸ワイヤレスモーションセンサ(HighSpeed仕様)
		PID_ECG          = 0x12, ///< ワイヤレスECGロガー
		PID_GSR          = 0x13, ///< ワイヤレスGSRロガー
		PID_DL           = 0x14, ///< 超小型6軸データロガー
		PID_EEG          = 0x15, ///< ワイヤレスEEGロガー
		PID_WIFI_CVT     = 0x16, ///< WiFiコンバータ
		//rsv             = 0x17,
		//rsv             = 0x18,
		//rsv             = 0x19,
		PID_MYO_DRY      = 0x1A, ///< ワイヤレス筋電センサ(乾式)
		PID_MYO_WMS_DRY  = 0x1B, ///< ワイヤレス筋電センサ(乾式, 加速度)
		PID_MYO_WET      = 0x1C, ///< ワイヤレス筋電センサ(湿式)
		PID_MYO_WMS_WET  = 0x1D, ///< ワイヤレス筋電センサ(湿式, 加速度)
		PID_GPS          = 0x1E, ///< GPS+9軸ワイヤレスモーションセンサ
		PID_WP_16_1500   = 0x1F, ///< 防水型9軸ワイヤレスモーションセンサ(16g/1500dps)
		PID_WP_5_1500    = 0x20, ///< 防水型9軸ワイヤレスモーションセンサ(5G/1500dps)
		PID_W6CH         = 0xFA, ///< ワイヤレス6chロガー
		PID_ALL          = 0xFF, ///< 全機種一括制御
	};

	///
	/// @brief コマンド番号の定数値です。
	///
	enum ECommandNo : unsigned char
	{
		CMD_GET_STATUS         = 0x05, ///< ステータス情報取得
		CMD_PREP_MEASURE       = 0x1F, ///< 計測準備
		CMD_START_MEASURE      = 0x02, ///< 計測開始
		CMD_STOP_MEASURE       = 0x04, ///< 計測停止
		CMD_SYNC               = 0x20, ///< 同期
		CMD_READ_SYNC          = 0x48, ///< 同期番号読み出し
		CMD_GET_FILE_INFO      = 0x07, ///< ファイル情報取得
		CMD_GET_LAST_FILE_INFO = 0x44, ///< 最新ファイル情報取得
		CMD_GET_FILE_INFO_2    = 0x21, ///< ファイル情報取得2
		CMD_READ_FILE          = 0x09, ///< ファイルデータ取得
		CMD_READ_FILE_EX       = 0x25, ///< ファイルデータ取得拡張
		CMD_READ_LAST_FILE     = 0x46, ///< 最新ファイルデータ取得
		CMD_READ_FILE_2        = 0x23, ///< ファイルデータ取得2
		CMD_READ_COMMENT       = 0x1D, ///< ファイルコメント取得
		CMD_WRITE_COMMENT      = 0x1C, ///< ファイルコメント書き込み
		CMD_ERASE_MEMORY       = 0x12, ///< メモリ消去
		CMD_SET_ID             = 0x01, ///< ID設定
		CMD_SET_CH             = 0x0E, ///< 無線チャンネル設定
		CMD_SET_FREQ           = 0x0B, ///< サンプリング周波数設定
		CMD_SET_TIME           = 0x0C, ///< 計測時間設定
		CMD_SET_MAG_GAIN       = 0x0D, ///< 地磁気ゲイン設定
		CMD_SET_UNIQ_CONFIG    = 0x27, ///< センサ基板固有設定
		CMD_SET_EX_DEVICE      = 0x30, ///< 外部接続機器固有設定書き込み
		CMD_GET_EX_DEVICE      = 0x31, ///< 外部接続機器固有設定読み込み
		CMD_SET_OFFSET         = 0x1A, ///< 補正値キー登録
		CMD_RESET_CONFIG       = 0x11, ///< 設定初期化
		CMD_GET_SERIAL         = 0x14, ///< シリアル番号取得
		CMD_GET_FW_VER         = 0x13, ///< ファームウェアバージョン取得
		CMD_GET_HW_VER         = 0x16, ///< ハードウェアバージョン取得
		CMD_PW_OFF             = 0x28, ///< 電源OFF
	};

	///
	/// @brief 応答コードを表す定数値です。
	///
	enum EReplyCode : unsigned char
	{
		ACK_GET_STATUS      = 0x85, ///< ACKパケット：ステータス情報取得
		ACK_PREP_MEASURE    = 0x9F, ///< ACKパケット：計測準備
		ACK_START_MEASURE   = 0x82, ///< ACKパケット：計測開始
		ACK_STOP_MEASURE    = 0x84, ///< ACKパケット：計測停止
		ACK_READ_SYNC       = 0xC8, ///< ACKパケット：同期
		ACK_GET_FILE_INFO   = 0x87, ///< ACKパケット：ファイル情報取得
		ACK_GET_FILE_INFO_2 = 0xA1, ///< ACKパケット：ファイル情報取得2
		ACK_READ_FILE       = 0x89, ///< ACKパケット：ファイルデータ取得
		ACK_READ_FILE_2     = 0xA3, ///< ACKパケット：ファイルデータ取得2
		ACK_ERASE_MEMORY    = 0x92, ///< ACKパケット：メモリ消去
		ACK_SET_ID          = 0x81, ///< ACKパケット：ID設定
		ACK_SET_CH          = 0x8E, ///< ACKパケット：無線チャンネル設定
		ACK_SET_FREQ        = 0x8B, ///< ACKパケット：サンプリング周波数設定
		ACK_SET_TIME        = 0x8C, ///< ACKパケット：計測時間設定
		ACK_SET_UNIQ_CONFIG = 0x8D, ///< ACKパケット：センサ基板固有設定
		ACK_SET_EX_DEVICE   = 0xB0, ///< ACKパケット：外部接続機器固有設定書き込み
		ACK_GET_EX_DEVICE   = 0xB1, ///< ACKパケット：外部接続機器固有設定読み込み
		ACK_SET_OFFSET      = 0x9A, ///< ACKパケット：補正値キー登録
		ACK_RESET_CONFIG    = 0x91, ///< ACKパケット：設定初期化
		ACK_PW_OFF          = 0xA8, ///< ACKパケット：電源OFF

		DAT_GET_STATUS      = 0x86, ///< データパケット：ステータス情報取得
		DAT_START_MEASURE   = 0x83, ///< データパケット：計測開始
		DAT_READ_SYNC       = 0xC9, ///< データパケット：同期
		DAT_GET_FILE_INFO   = 0x88, ///< データパケット：ファイル情報取得
		DAT_GET_FILE_INFO_2 = 0xA2, ///< データパケット：ファイル情報取得2
		DAT_READ_FILE       = 0x8A, ///< データパケット：ファイルデータ取得
		DAT_READ_FILE_2     = 0xA4, ///< データパケット：ファイルデータ取得2
		DAT_READ_COMMENT    = 0x9D, ///< データパケット：ファイルコメント取得
		DAT_WRITE_COMMENT   = 0x9C, ///< データパケット：ファイルコメント書き込み
		DAT_GET_SERIAL      = 0x94, ///< データパケット：シリアル番号取得
		DAT_GET_FW_VER      = 0x93, ///< データパケット：ファームウェアバージョン取得
		DAT_GET_HW_VER      = 0x96, ///< データパケット：ハードウェアバージョン取得
	};
}
