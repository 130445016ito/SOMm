
// DllSampleCppDlg.h : ヘッダー ファイル
//

#pragma once

///////////////////////////////////////
// インクルード，リンク関連
///////////////////////////////////////

// ヘッダファイルインクルード
#include"Cmd.h"


// 自作OpenGLをインクルード
#include "Scene.h"

// スレッド使用のため
#include <process.h>

// 時間計測
#include <time.h>



// ライブラリのリンク
#pragma comment(lib, "LpWsmDll.lib")

// 名前空間使用宣言
using namespace lp_wsm;

// 独自メッセージIDの定義
#define WM_USER_STAT_UPDATE (WM_USER + 1)
#define WM_USER_ACC_UPDATE (WM_USER + 2)

///////////////////////////////////////
// インクルード，リンク関連ここまで
///////////////////////////////////////

#include "afxwin.h"
#include "afxcmn.h"

// CDllSampleCppDlg ダイアログ
class CDllSampleCppDlg : public CDialogEx
{
// コンストラクション
public:
	CDllSampleCppDlg(CWnd* pParent = NULL);	// 標準コンストラクター

// ダイアログ データ
	enum { IDD = IDD_DLLSAMPLECPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV サポート

// 実装
protected:
	HICON m_hIcon;

	// 生成された、メッセージ割り当て関数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonConnect();
private:
	CComboBox mc_combo_port;
public:
	afx_msg void OnBnClickedButtonStatus();
	afx_msg void OnBnClickedButtonDisconnect();
	afx_msg void OnBnClickedButtonPwoff();
	CSpinButtonCtrl mc_spin_smid;
	CSpinButtonCtrl mc_spin_pid;
	CString mv_static_connection;
	CString mv_static_status;


	//FILE *output;
		

///////////////////////////////////////
// 使用クラス，コールバック関数宣言
///////////////////////////////////////

private:
	Cmd cmd;
	afx_msg LRESULT OnStatUpdate(WPARAM wparam, LPARAM lparam);
	afx_msg LRESULT OnAccUpdate(WPARAM wparam, LPARAM lparam);
	static void CbGetStatus(const char *port_name, unsigned char *buffer, int size);
	static void CbPrepMeasure(const char *port_name, unsigned char *buffer, int size);
	static void CbStartMeasure(const char *port_name, unsigned char *buffer, int size);
	static void CbStopMeasure(const char *port_name, unsigned char *buffer, int size);
	static void CbPwOff(const char *port_name, unsigned char *buffer, int size);

///////////////////////////////////////
// 使用クラス，コールバック関数宣言ここまで
///////////////////////////////////////

public:
	afx_msg void OnBnClickedButtonPrepare();
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonEnd();
	CProgressCtrl mc_progress_x;
	CProgressCtrl mc_progress_y;
	CProgressCtrl mc_progress_z;
	afx_msg void OnBnClickedButton1yoko();
	CString m_EditRef;
private:
	CStatic m_glView;
	CDC *m_pDC;
	HGLRC m_GLRC;
	bool SetUpPixelFormat(HDC hdc);
public:
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
private:
	Scene *m_pScene;
private:
	G_Scene *m_pG_Scene;
public:
	afx_msg void OnBnClickedButtonTest2();
	afx_msg void OnBnClickedButton2test3();
	afx_msg void OnBnClickedButtonfilestart();
	afx_msg void OnBnClickedButtonFileclose();
	double **accArr;
	double **accArrDlg;
	double *curAccArrDlg;//2月9日追加
	int numSample;

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedNandemotestbutton();

//　_beginthreadの第一引数は，関数のポインタを渡す．
//　ただし，クラスのメンバ関数を渡すときは，static関数でないとだめ．
//　staticメンバ関数はインスタンス作成しなくとも，プログラム開始とともに初期化されるため．
//　そのため，staticで関数を作り，無理やりキャストして用いる．
//　本当のスレッド関数は，ProjectionRoop(void)．
	static unsigned int WINAPI ThreadStart(void*);	
	unsigned int ProjectionRoop(void);
	afx_msg void OnBnClickedButton3();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	CString m_EditInp;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	unsigned int m_nTimer;
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnBnClickedButtonOutput();
	afx_msg void OnDropdownButton8(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnStnClickedGlview();
};

///////////////////////////////////////
// メインスレッドへの送信データクラス
///////////////////////////////////////
class CMsgData
{
public:
	CString status;
	double acc[3];
	double ang[3];
	double acc1[3];
	double ang1[3];
	
};

class CEmgData{
public:
	CString status;
	double emg[2];
	double iemg[2];

};
