///
/// @file  Com.h
/// @brief COMポート操作関連クラス
///

#pragma once

#include<windows.h>
#include<setupapi.h>
#include<string>
#include<vector>

#include"Packet.h"

#pragma comment(lib, "setupapi.lib")

using namespace std;

namespace lp_wsm
{
	///
	/// @brief ポート名保持用構造体です。
	///
	struct PortName
	{
		char name[32];      ///< ポート名
		char friendly[256]; ///< ポートのフレンドリーネーム

		///
		/// デフォルトコンストラクタです。
		///
		PortName();
	};

	///
	/// @brief COMポート操作クラスです。
	///
	class Com
	{
	public:
		///
		/// @brief 使用可能なComポート一覧を取得します。
		///
		/// @return 利用可能なポート名の配列
		///
		__declspec(dllexport) static vector<PortName> GetPorts();
		
		///
		/// @brief デフォルトコンストラクタです。
		///
		__declspec(dllexport) Com();

		///
		/// @brief デストラクタです。
		///
		__declspec(dllexport) ~Com();

		///
		/// @brief COMポートをオープンします。
		///
		/// @param port_name オープンするポート名
		/// @return オープンできたかどうか
		///
		__declspec(dllexport) bool Open(const char *port_name);

		///
		/// @brief 開いているCOMポートをクローズします。
		///
		/// @return クローズできたかどうか
		///
		__declspec(dllexport) bool Close();

		///
		/// @brief データを送信します。
		///
		/// @param buffer 送信するデータの配列
		/// @param bytes 配列の長さ
		/// @return 送信できたかどうか
		///
		__declspec(dllexport) bool Write(unsigned char * buffer, unsigned long bytes);

		///
		/// @brief パケット受信時のコールバック関数を指定します。
		///
		/// @param func 登録するコールバック関数
		///
		__declspec(dllexport) void SetCallback(void (*func)(const char*, unsigned char*, int));

	protected:
		///
		/// @brief COMポート名です。
		///
		string port_name;

	private:
		__declspec(dllexport) static DWORD WINAPI ThreadFunc(LPVOID lpParameter);
		__declspec(dllexport) DWORD Read();

		/// COMポート
		HANDLE myHComPort;

		/// イベント待ちスレッド
		HANDLE myHThread;
		DWORD  myThreadId;

		/// パケット受信時のコールバック関数
		void (*callback)(const char*, unsigned char*, int);

		/// パケット待ち（何もしない）
		__declspec(dllexport) virtual void WaitPacket(unsigned char *buffer, int size);
	};
}
