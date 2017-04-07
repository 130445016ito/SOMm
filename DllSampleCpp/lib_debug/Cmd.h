///
/// @file  Cmd.h
/// @brief 送受信コマンド処理クラス
///

#pragma once

#include"Com.h"
#include"Table.h"
#include"Packet.h"

#include<map>
#include<queue>
#include<vector>

using namespace std;

namespace lp_wsm
{
	///
	/// @brief 送受信コマンド処理クラスです。
	///
	class Cmd : public Com
	{
	public:
		///
		/// @brief ステータス情報取得コマンドを送信します。
		///
		/// @param pid  プロダクトID
		/// @param smid 対象センサモジュールID
		///
		__declspec(dllexport) void GetStatus(unsigned char pid, unsigned char smid);

		///
		/// @brief 計測準備コマンドを送信します。
		///
		/// @param pid      プロダクトID
		/// @param smid     対象センサモジュールID
		/// @param filename ファイル名
		/// @param mode     計測モード
		/// @param comment  ファイルコメント
		///
		__declspec(dllexport) void PrepMeasure(unsigned char pid, unsigned char smid, const char *filename, unsigned char mode, const char *comment);

		///
		/// @brief 計測開始コマンドを送信します。
		///
		/// @param pid  プロダクトID
		/// @param smid 対象センサモジュールID
		/// @param YY   計測開始時間（年）
		/// @param MM   計測開始時間（月）
		/// @param DD   計測開始時間（日）
		/// @param hh   計測開始時間（時）
		/// @param mm   計測開始時間（分）
		/// @param mode 計測モード
		///
		__declspec(dllexport) void StartMeasure(unsigned char pid, unsigned char smid, unsigned char YY, unsigned char MM, unsigned char DD, unsigned char hh, unsigned char mm, unsigned char mode);

		///
		/// @brief 計測停止コマンドを送信します。
		///
		/// @param pid  プロダクトID
		/// @param smid 対象センサモジュールID
		///
		__declspec(dllexport) void StopMeasure(unsigned char pid, unsigned char smid);

		///
		/// @brief 同期コマンドを送信します。
		///
		/// @param pid     プロダクトID
		/// @param smid    対象センサモジュールID
		/// @param sync_no 同期番号
		///
		__declspec(dllexport) void Sync(unsigned char pid, unsigned char smid, unsigned char sync_no);

		///
		/// @brief 同期番号読み出しコマンドを送信します。
		///
		/// @param pid     プロダクトID
		/// @param smid    対象センサモジュールID
		/// @param file_no ファイル番号
		///
		__declspec(dllexport) void ReadSync(unsigned char pid, unsigned char smid, unsigned char file_no);

		///
		/// @brief ファイル情報取得コマンドを送信します。
		///
		/// @param pid  プロダクトID
		/// @param smid 対象センサモジュールID
		///
		__declspec(dllexport) void GetFileInfo(unsigned char pid, unsigned char smid);

		///
		/// @brief 最新ファイル情報取得コマンドを送信します。
		///
		/// @param pid  プロダクトID
		/// @param smid 対象センサモジュールID
		///
		__declspec(dllexport) void GetLastFileInfo(unsigned char pid, unsigned char smid);

		///
		/// @brief ファイル情報取得2コマンドを送信します。
		///
		/// @param pid      プロダクトID
		/// @param smid     対象センサモジュールID
		/// @param send_num 送信回数
		///
		__declspec(dllexport) void GetFileInfo2(unsigned char pid, unsigned char smid, unsigned char send_num);

		///
		/// @brief ファイルデータ取得コマンドを送信します。
		///
		/// @param pid       プロダクトID
		/// @param smid      対象センサモジュールID
		/// @param file_no   ファイル番号
		/// @param seq_start 開始シーケンス番号
		/// @param seq_num   シーケンス数
		///
		__declspec(dllexport) void ReadFile(unsigned char pid, unsigned char smid, unsigned char file_no, unsigned int seq_start = 0, unsigned int seq_num = 0xFFFFFFFF);

		///
		/// @brief ファイルデータ取得拡張コマンドを送信します。
		///
		/// @param pid       プロダクトID
		/// @param smid      対象センサモジュールID
		/// @param file_no   ファイル番号
		/// @param seq_start 開始シーケンス番号
		/// @param seq_num   シーケンス数
		/// @param send_num  多重送信回数
		///
		__declspec(dllexport) void ReadFileEx(unsigned char pid, unsigned char smid, unsigned char file_no, unsigned int seq_start = 0, unsigned int seq_num = 0xFFFFFFFF, unsigned char send_num = 1);

		///
		/// @brief 最新ファイルデータ取得コマンドを送信します。
		///
		/// @param pid       プロダクトID
		/// @param smid      対象センサモジュールID
		/// @param seq_start 開始シーケンス番号
		/// @param seq_num   シーケンス数
		///
		__declspec(dllexport) void ReadLastFile(unsigned char pid, unsigned char smid, unsigned int seq_start = 0, unsigned int seq_num = 0xFFFFFFFF);

		///
		/// @brief ファイルデータ取得2コマンドを送信します。
		///
		/// @param pid      プロダクトID
		/// @param smid     対象センサモジュールID
		/// @param send_num 送信回数
		/// @param filename ファイル名
		///
		__declspec(dllexport) void ReadFile2(unsigned char pid, unsigned char smid, unsigned char send_num, const char *filename);

		///
		/// @brief ファイルコメント取得コマンドを送信します。
		///
		/// @param pid     プロダクトID
		/// @param smid    対象センサモジュールID
		/// @param file_no ファイル番号
		///
		__declspec(dllexport) void ReadComment(unsigned char pid, unsigned char smid, unsigned char file_no);

		///
		/// @brief ファイルコメント書き込みコマンドを送信します。
		///
		/// @param pid     プロダクトID
		/// @param smid    対象センサモジュールID
		/// @param file_no ファイル番号
		/// @param comment ファイルコメント
		///
		__declspec(dllexport) void WriteComment(unsigned char pid, unsigned char smid, unsigned char file_no, const char *comment);

		///
		/// @brief メモリ消去コマンドを送信します。
		///
		/// @param pid  プロダクトID
		/// @param smid 対象センサモジュールID
		///
		__declspec(dllexport) void EraseMemory(unsigned char pid, unsigned char smid);

		///
		/// @brief ID設定コマンドを送信します。
		///
		/// @param pid  プロダクトID
		/// @param smid 対象センサモジュールID
		/// @param id   ID（1～254を指定可能）
		///
		__declspec(dllexport) void SetId(unsigned char pid, unsigned char smid, unsigned char id);

		///
		/// @brief 無線チャンネル設定コマンドを送信します。
		///
		/// @param pid  プロダクトID
		/// @param smid 対象センサモジュールID
		/// @param ch   無線チャンネル
		///
		__declspec(dllexport) void SetCh(unsigned char pid, unsigned char smid, unsigned char ch);

		///
		/// @brief サンプリング周波数設定コマンドを送信します。
		///
		/// @param pid  プロダクトID
		/// @param smid 対象センサモジュールID
		/// @param freq サンプリング周波数
		///
		__declspec(dllexport) void SetFreq(unsigned char pid, unsigned char smid, unsigned short freq);

		///
		/// @brief 計測時間設定コマンドを送信します。
		///
		/// @param pid  プロダクトID
		/// @param smid 対象センサモジュールID
		/// @param hh   計測時間（時）
		/// @param mm   計測時間（分）
		/// @param ss   計測時間（秒）
		///
		__declspec(dllexport) void SetTime(unsigned char pid, unsigned char smid, unsigned char hh, unsigned char mm, unsigned char ss);

		///
		/// @brief 9軸ワイヤレスモーションセンサの地磁気ゲイン設定コマンドを送信します。
		///
		/// @param pid  プロダクトID
		/// @param smid 対象センサモジュールID
		/// @param gain 地磁気センサゲイン
		///
		__declspec(dllexport) void SetMagneticGain(unsigned char pid, unsigned char smid, unsigned char gain);

		///
		/// @brief センサ基板固有設定コマンドを送信します。
		///
		/// @param pid         プロダクトID
		/// @param smid        対象センサモジュールID
		/// @param target      対象センサ
		/// @param sub         サブ項目
		/// @param config      固有設定
		/// @param config_size 固有設定の有効バイト数
		///
		__declspec(dllexport) void SetUniqConfig(unsigned char pid, unsigned char smid, unsigned char target, unsigned short sub, unsigned char *config, unsigned char config_size);

		///
		/// @brief ワイヤレス筋電センサのゲイン設定コマンドを送信します。
		///
		/// @param pid  プロダクトID
		/// @param smid 対象センサモジュールID
		/// @param gain ゲイン設定値
		///
		__declspec(dllexport) void SetMyoGain(unsigned char pid, unsigned char smid, unsigned char gain);

		///
		/// @brief 外部接続機器固有設定書き込みコマンドを送信します。
		///
		/// @param pid         プロダクトID
		/// @param smid        対象センサモジュールID
		/// @param target      対象機器
		/// @param sub         サブ項目
		/// @param config      固有設定
		/// @param config_size 固有設定の有効バイト数
		///
		__declspec(dllexport) void SetExDevice(unsigned char pid, unsigned char smid, unsigned char target, unsigned short sub, unsigned char *config, unsigned char config_size);

		///
		/// @brief 外部接続機器固有設定読み込みコマンドを送信します。
		///
		/// @param pid         プロダクトID
		/// @param smid        対象センサモジュールID
		/// @param target      対象機器
		/// @param sub         サブ項目
		///
		__declspec(dllexport) void GetExDevice(unsigned char pid, unsigned char smid, unsigned char target, unsigned short sub);

		///
		/// @brief 補正値キー登録コマンドを送信します。
		///
		/// @param pid       プロダクトID
		/// @param smid      対象センサモジュールID
		/// @param data      データ
		/// @param data_size データサイズ
		///
		__declspec(dllexport) void SetOffset(unsigned char pid, unsigned char smid, unsigned char *data, unsigned char data_size);

		///
		/// @brief 設定初期化コマンドを送信します。
		///
		/// @param pid  プロダクトID
		/// @param smid 対象センサモジュールID
		///
		__declspec(dllexport) void ResetConfig(unsigned char pid, unsigned char smid);

		///
		/// @brief シリアル番号取得コマンドを送信します。
		///
		/// @param pid  プロダクトID
		/// @param smid 対象センサモジュールID
		///
		__declspec(dllexport) void GetSerial(unsigned char pid, unsigned char smid);

		///
		/// @brief ファームウェアバージョン取得コマンドを送信します。
		///
		/// @param pid  プロダクトID
		/// @param smid 対象センサモジュールID
		///
		__declspec(dllexport) void GetFwVer(unsigned char pid, unsigned char smid);

		///
		/// @brief ハードウェアバージョン取得コマンドを送信します。
		///
		/// @param pid  プロダクトID
		/// @param smid 対象センサモジュールID
		///
		__declspec(dllexport) void GetHwVer(unsigned char pid, unsigned char smid);

		///
		/// @brief 電源OFFコマンドを送信します。
		///
		/// @param pid  プロダクトID
		/// @param smid 対象センサモジュールID
		///
		__declspec(dllexport) void PwOff(unsigned char pid, unsigned char smid);

		///
		/// @brief パケット受信時のコールバック関数を登録します。
		///
		/// @param code 応答コード
		/// @param func コールバック関数
		///
		__declspec(dllexport) void SetCmdCallback(unsigned char code, void (*func)(const char *port_name, unsigned char *packet, int size));

	private:
		/// コールバック関数オブジェクト
		class CCallback
		{
		public:
			CCallback();
			CCallback(void (*func)(const char *port_name, unsigned char *packet, int size));
			void operator()(const char *port_name, unsigned char *packet, int size);
			void SetFunc(void (*func)(const char *port_name, unsigned char *packet, int size));

		private:
			void (*func)(const char *port_name, unsigned char *packet, int size);
			static void dummy(const char *port_name, unsigned char *packet, int size);
		};

		/// コールバック関数テーブル
		map<unsigned char, CCallback> cb;

		/// パケット待ち用
		queue<unsigned char> rcv_buffer;	// 受信済みバッファ
		vector<unsigned char> rcv_packet;	// 受信済みパケット

		/// パケット切り出し
		__declspec(dllexport) void WaitPacket(unsigned char* buffer, int size);

		/// BCC計算
		unsigned char GetBcc(unsigned char* command, int size);
		bool CheckBcc(unsigned char* command, int size);

		/// コマンドパケットのヘッダ(コマンド番号まで)を計算
		void SetHeader(unsigned char *command, unsigned char size, unsigned char pid, unsigned char smid, unsigned char command_no);

		/// コマンドパケットのフッタ(BCCとフッタ)を計算
		void SetFooter(unsigned char *command, int size);
	};
}
