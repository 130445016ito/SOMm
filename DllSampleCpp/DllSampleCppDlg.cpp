/////////////////////////////////////////////////////////////////////////////////////////

//メインの編集ファイル（ジャイロセンサの通信すべてのプログラム）
//追加して編集が必要と思われる箇所には番号をつけてある	ex（A-1）
/////////////////////////////////////////////////////////////////////////////////////////

// DllSampleCppDlg.cpp : 実装ファイル
//

#include "stdafx.h"
#include "DllSampleCpp.h"
#include "DllSampleCppDlg.h"
#include "afxdialogex.h"


/*+++++++++++++++++++++++++++++++++++追加（11/18）++++++++++++++++++++++++++++++++++++*/

#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


/*++++++++++++++++++++++++++++++++++++++++追加（11/18）++++++++++++++++++++++++++++++++++++*/

/*++++++++追加（12/16）++++++++++++++*/
#include <Windows.h>
#define sleep(n) Sleep(n*1000)

/*++++++++追加（12/16）+++++++++++++++*/

/*++++++++++追加（2016・6/15）+++++++++*/
#include <stdio.h>
#include <time.h>

/*+++++++++追加（2016・6/15）++++++++++*/



using namespace std;

void TestFunction(void);

// アプリケーションのバージョン情報に使われる CAboutDlg ダイアログ

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ダイアログ データ
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート

// 実装
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDllSampleCppDlg ダイアログ




CDllSampleCppDlg::CDllSampleCppDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDllSampleCppDlg::IDD, pParent)
	, mv_static_connection(_T("状態：切断"))
	, mv_static_status(_T(""))
	, m_EditRef(_T(""))
	, m_pScene(NULL)
	, m_pG_Scene(NULL)
	, m_nTimer(0)
	, accArr(NULL)
	, accArrDlg(NULL)
	, curAccArrDlg(NULL)
	, m_EditInp(_T(""))
{

	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	/////////////////////////////////////////////////////////////////////////////////
	/*
	//+++++++++++++++++++++++++++++++++++++++++<A-1>+++++++++++++++++++++++++++++++++++++++
	accArrDlg	もしくは	curAccArrDlg	の配列数を増やす場合，
	new doubleのあとの数字を増やす
	*/


		//時系列データのサンプル数
		numSample=40;//既存値＝40


	//コンストラクタ，ここでアロケートする(1/19)++++++++++++++++++++//
		// Allocate
		accArrDlg=new double*[5];
		for(ui i=0; i<5; i++) {
			accArrDlg[i] = new double[numSample];
		}

		curAccArrDlg=new double[5];
		//for(ui i=0; i<3; i++) {
		//	curAccArrDlg[i] = new double[20];
		//}
		for(ui i=0; i<5; i++)
		//	for(ui j=0; j<20; j++)
				curAccArrDlg[i]=0;
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++//



	//<A-1>


}

void CDllSampleCppDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_PORT, mc_combo_port);
	DDX_Control(pDX, IDC_SPIN_SMID, mc_spin_smid);
	DDX_Control(pDX, IDC_SPIN_PID, mc_spin_pid);
	DDX_Text(pDX, IDC_STATIC_CONNECTION, mv_static_connection);
	DDX_Text(pDX, IDC_STATIC_STATUS, mv_static_status);
	DDX_Control(pDX, IDC_PROGRESS_X, mc_progress_x);
	DDX_Control(pDX, IDC_PROGRESS_Y, mc_progress_y);
	DDX_Control(pDX, IDC_PROGRESS_Z, mc_progress_z);
	DDX_Text(pDX, IDC_EDIT1, m_EditRef);
	DDX_Control(pDX, IDC_GLVIEW, m_glView);

	DDX_Text(pDX, IDC_EDIT3, m_EditInp);
}


//////////////////////////////////////////////////////////////////////////////////
// メインスレッドへのメッセージPost関連
//////////////////////////////////////////////////////////////////////////////////

// メッセージマップ
BEGIN_MESSAGE_MAP(CDllSampleCppDlg, CDialogEx)
	// 独自メッセージ追加
	ON_MESSAGE(WM_USER_STAT_UPDATE, OnStatUpdate)
	ON_MESSAGE(WM_USER_ACC_UPDATE, OnAccUpdate)

	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_CONNECT, &CDllSampleCppDlg::OnBnClickedButtonConnect)
	ON_BN_CLICKED(IDC_BUTTON_STATUS, &CDllSampleCppDlg::OnBnClickedButtonStatus)
	ON_BN_CLICKED(IDC_BUTTON_DISCONNECT, &CDllSampleCppDlg::OnBnClickedButtonDisconnect)
	ON_BN_CLICKED(IDC_BUTTON_PWOFF, &CDllSampleCppDlg::OnBnClickedButtonPwoff)
	ON_BN_CLICKED(IDC_BUTTON_PREPARE, &CDllSampleCppDlg::OnBnClickedButtonPrepare)
	ON_BN_CLICKED(IDC_BUTTON_START, &CDllSampleCppDlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CDllSampleCppDlg::OnBnClickedButtonEnd)
	ON_BN_CLICKED(IDC_BUTTON1_yoko, &CDllSampleCppDlg::OnBnClickedButton1yoko)
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BUTTON_Test2, &CDllSampleCppDlg::OnBnClickedButtonTest2)
	ON_BN_CLICKED(IDC_BUTTON2_test3, &CDllSampleCppDlg::OnBnClickedButton2test3)
	ON_BN_CLICKED(IDC_BUTTON_fileStart, &CDllSampleCppDlg::OnBnClickedButtonfilestart)
	ON_BN_CLICKED(IDC_BUTTON_FileClose, &CDllSampleCppDlg::OnBnClickedButtonFileclose)
	ON_BN_CLICKED(IDC_BUTTON1, &CDllSampleCppDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_NANDEMOtestBUTTON, &CDllSampleCppDlg::OnBnClickedNandemotestbutton)
	ON_BN_CLICKED(IDC_BUTTON3, &CDllSampleCppDlg::OnBnClickedButton3)
	ON_EN_CHANGE(IDC_EDIT1, &CDllSampleCppDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CDllSampleCppDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON4, &CDllSampleCppDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CDllSampleCppDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CDllSampleCppDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CDllSampleCppDlg::OnBnClickedButton7)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON8, &CDllSampleCppDlg::OnBnClickedButton8)
	
END_MESSAGE_MAP()

// メインスレッドのウィンドウハンドル
HWND h_dlg;

// メインスレッドへの受け渡しデータクラス
CMsgData msg;
CEmgData msgemg;
//++++++++++| ファイルの入出力のため（どこからでも参照できるように）　|+++++++++++++++++
FileControl *fCon;
//+++++++++++| 計測中の値を格納するため｜  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
CDllSampleCppDlg myVar;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


// メッセージ処理（ステータス情報更新）
LRESULT CDllSampleCppDlg::OnStatUpdate(WPARAM wparam, LPARAM lparam)
{
	// ステータス情報表示更新
	mv_static_status = msg.status;
	UpdateData(FALSE);

	return 0;
}

// メッセージ処理（加速度データ更新）
LRESULT CDllSampleCppDlg::OnAccUpdate(WPARAM wparam, LPARAM lparam)
{
	// 加速度データ更新
	mc_progress_x.SetPos((int)(msg.acc[0] / 10.0 * 100));
	mc_progress_y.SetPos((int)(msg.acc[1] / 10.0 * 100));
	mc_progress_z.SetPos((int)(msg.acc[2] / 10.0 * 100));

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////
// メインスレッドへのメッセージPost関連ここまで
//////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////
// コールバック関数
//////////////////////////////////////////////////////////////////////////////////

// ステータス情報取得
void CDllSampleCppDlg::CbGetStatus(const char *port_name, unsigned char *buffer, int size)
{
	// 受信パケット解析（ステータス情報取得）
	DatGetStatus packet(buffer, size);

	// 表示テキスト設定
	CString str;
	str.Format("プロダクトID：%d", packet.pid);
	msg.status = str;
	str.Format("%s\nセンサモジュールID：%d", msg.status, packet.smid);
	msg.status = str;
	str.Format("%s\nサンプリング周波数：%d", msg.status, packet.freq);
	msg.status = str;
	str.Format("%s\n無線ch：%d", msg.status, packet.ch);
	msg.status = str;
	str.Format("%s\n測定時間：%dh : %dm : %ds", msg.status, packet.hh, packet.mm, packet.ss);
	msg.status = str;

	// メインスレッドにメッセージ送信
	::PostMessage(h_dlg, WM_USER_STAT_UPDATE, 0, 0);
}

// 計測準備
void CDllSampleCppDlg::CbPrepMeasure(const char *port_name, unsigned char *buffer, int size)
{
	// 表示テキスト設定
	CString str;
	msg.status = "計測準備コマンドを送信しました";

	// メインスレッドにメッセージ送信
	::PostMessage(h_dlg, WM_USER_STAT_UPDATE, 0, 0);
}

// 計測開始
void CDllSampleCppDlg::CbStartMeasure(const char *port_name, unsigned char *buffer, int size)
{
	// 受信パケット解析
	DatStartMeasure packet(buffer, size);


	/*
	++++++++++++++++++++++++++++++++++++++++++<A-2>++++++++++++++++++++++++++++++++++++++++++
	AD変換のプログラム
	変更するなら感度のみ
	*/
	// 加速度データ解析/////////↓AD変換↓////////////////////////
	WmsData data(packet.data[0], packet.pid);
	const double bit_scale = 65535;
	const double acc_0 = 1.65;
	const double s_acc = 0.057; //1Gあたりの感度を38.5mV/G(30G)に一次変更(9/22)(s_acc=0.385)　//元データは，s_acc = 0.057　感度は大きいほうが精度が高いかも
	const double ang_0 = 1.5;
	const double s_ang = 0.0008; //センサー感度を3.624mV/dps(300dps)に一次変更(9/22)(s_ang = 0.003624)　//元データは，s_ang = 0.0008
	
	for(int i=0; i<3; i++){
		msg.acc[i] = (3.3 * data.acc[i] / bit_scale - acc_0) / s_acc;
		msg.ang[i] = (3.3 * data.ang[i] / bit_scale - ang_0) / s_ang;
	}



	//筋電データ解析（AD変換）(10/25)
	EmgData dataemg(packet.data[0]);
	for(int i=0; i<2; i++){
		//msgemg.emg[i] = (dataemg.emg[i] / 4095 * 3.3) / ( 6.8 / 11.5 );
		//msgemg.iemg[i] = (dataemg.iemg[i] / 4095 * 3.3) / ( 6.8 / 11.5 );
		///上記の計算式だと不安定だったため下記に変更し簡単にした(11/2)///
		msgemg.emg[i] = dataemg.emg[i] * ( 379.5 / 278460 );
		msgemg.iemg[i] = dataemg.iemg[i] * ( 379.5 / 278460 );
	}

	
	/*
	msg.ang[0]=data.ang[0];
	msg.ang[1]=data.ang[1];
	msg.ang[2]=data.ang[2];
	*/

	
	///////////////////↑ここまでAD変換↑//////////////////////////////
	//<A-2>

	///全波整流（筋電計データ処理）1/17///
	for(int i=0;i<2;i++){
		if(msgemg.emg[i]<0){
			msgemg.emg[i] = msgemg.emg[i] * (-1);
		}
		if(msgemg.iemg[i]<0){
			msgemg.iemg[i] = msgemg.iemg[i] * (-1);
		}
	}

	/*+++++++++++++++++++++++++++++++++++↓追加↓（11/18）++++++++++++++++++++++++++++++++++++*/

	/*

	+++++++++++++++++++++++++++++++++++++++++<A-3>+++++++++++++++++++++++++++++++++++++++++++++
	補正プログラム（加速度，角速度）
	Y = α X + βで補正
	詳しくはワード”プログラム解説”で
	*/
	////////////////////////////////////////////////////////////////////
	//////////////////////////補正プログラム////////////////////////////
	////////	Y = α X + β    α:傾き　β:バイアス	////////////////
	////////////////////////////////////////////////////////////////////
	
	
	//　補正係数の定義 （加速度）
	double acc_a_x, acc_a_y, acc_a_z;	//	a:傾き
	double acc_bias_x, acc_bias_y, acc_bias_z;	//	bias:バイアス

		//////////////↓ID=1の補正式↓////////////

	/*
	
	//補正係数入力
	acc_a_x=1.0;			////////////////////////////////////////	
	acc_a_y=1.0;			////////////////////////////////////////
	acc_a_z=1.0;			////////	ここに値を入力　　//////////
	acc_bias_x=-1.6;		////////////////////////////////////////
	acc_bias_y=-0.7;		////////////////////////////////////////
	acc_bias_z=-0.0;		////////////////////////////////////////


	msg.acc[0] = msg.acc[0]*acc_a_x+acc_bias_x;		//////////
	msg.acc[1] = msg.acc[1]*acc_a_y+acc_bias_y;		//補正式//
	msg.acc[2] = msg.acc[2]*acc_a_z+acc_bias_z;		//////////


	//  補正係数の定義　（角速度）
	double ang_a_x, ang_a_y, ang_a_z;	//	a:傾き
	double ang_bias_x,ang_bias_y,ang_bias_z;	//	bias:バイアス


	//補正係数入力
	ang_a_x=1.0;				////////////////////////////////////////
	ang_a_y=1.0;				////////////////////////////////////////
	ang_a_z=1.0;				//////// 	ここに値を入力　　//////////
	ang_bias_x=330;				////////////////////////////////////////
	ang_bias_y=340;				////////////////////////////////////////
	ang_bias_z=350;				////////////////////////////////////////


	msg.ang[0] = msg.ang[0]*ang_a_x+ang_bias_x;		//////////
	msg.ang[1] = msg.ang[1]*ang_a_y+ang_bias_y;		//補正式//
	msg.ang[2] = msg.ang[2]*ang_a_z+ang_bias_z;		//////////


	//}else{
	*/
		//////////////↓ID=2の補正式↓////////////

	

		
		//補正係数入力(加速度)
	
	acc_a_x=2.1476;			////////////////////////////////////////	
	acc_a_y=2.1891;			////////////////////////////////////////
	acc_a_z=2.1311;			////////	ここに値を入力　　//////////
	acc_bias_x=-1.5705;		////////////////////////////////////////
	acc_bias_y=-0.6965;		////////////////////////////////////////
	acc_bias_z=-0.6287;		////////////////////////////////////////

	
	msg.acc[0] = (msg.acc[0]+acc_bias_x)*acc_a_x;		//////////
	msg.acc[1] = (msg.acc[1]+acc_bias_y)*acc_a_y;		//補正式//
	msg.acc[2] = (msg.acc[2]+acc_bias_z)*acc_a_z;		//////////
	



	
	//  補正係数の定義　（角速度）
	double ang_a_x, ang_a_y, ang_a_z;	//	a:傾き
	double ang_bias_x,ang_bias_y,ang_bias_z;	//	bias:バイアス

	
	//補正係数入力
	ang_a_x=4.09;				///////////////////////////////////////
	ang_a_y=1.0;				///////////////////////////////////////
	ang_a_z=1.0;				/////////	ここに値を入力　　/////////
	ang_bias_x=337;				///////////////////////////////////////
	ang_bias_y=0;				///////////////////////////////////////
	ang_bias_z=0;				///////////////////////////////////////


	msg.ang[0] = (msg.ang[0]+ang_bias_x)*ang_a_x;		//////////
	msg.ang[1] = (msg.ang[1]+ang_bias_y)*ang_a_y;		//補正式//
	msg.ang[2] = (msg.ang[2]+ang_bias_z)*ang_a_z;		//////////
	//}
	
	/////////////////////////////////////////////////////////////////////
	//////////////////////	補正プログラム終わり  ///////////////////////
	/////////////////////////////////////////////////////////////////////

	//sleep(0.01); //補正テストのため一次追加①

	//<A-3>
	
	/*+++++++++++++++++++++++++++++++++++　↑ここまで追加↑（11/18）++++++++++++++++++++++++++++++++++++*/
	
	
	//static int iii=0;	//テスト（12/16）
	static int count=0, count2=0;
	//iii++;

	
	////ローパスフィルタ///////
	const double r=0.8;
	const double rr=1-r;
	if(count>1){
		msgemg.emg[0] = r*msgemg.emg[0] + rr*myVar.accArrDlg[0][count-1];
		//msgemg.emg[1] = r*msgemg.emg[1] + rr*myVar.accArrDlg[1][count-1];
		msgemg.iemg[0] = r*msgemg.iemg[0] + rr*myVar.accArrDlg[1][count-1];
		//msgemg.iemg[1] = r*msgemg.iemg[1] + rr*myVar.accArrDlg[1][count-1];
		msg.acc[0] = r*msg.acc[0] + rr*myVar.accArrDlg[2][count-1];
		msg.acc[1] = r*msg.acc[1] + rr*myVar.accArrDlg[3][count-1];
		msg.acc[2] = r*msg.acc[2] + rr*myVar.accArrDlg[4][count-1];
	}



	/////////////////*センサ別でデータ保管（10/21）*////////////
	 if(packet.smid==1){
		myVar.accArrDlg[0][count] = msgemg.emg[0];
		//myVar.accArrDlg[1][count] = msgemg.emg[1];
		myVar.accArrDlg[1][count] = msgemg.iemg[0];
		//myVar.accArrDlg[3][count] = msgemg.iemg[1];
	 }
	 /*else if(packet.smid==2){
		myVar.accArrDlg[4][count] = msgemg.emg[0];
		myVar.accArrDlg[5][count] = msgemg.emg[1];
		myVar.accArrDlg[6][count] = msgemg.iemg[0];
		myVar.accArrDlg[7][count] = msgemg.iemg[1];
	 }*/
	 else if(packet.smid==4){
		myVar.accArrDlg[2][count] = msg.acc[0];
		myVar.accArrDlg[3][count] = msg.acc[1];
		myVar.accArrDlg[4][count] = msg.acc[2];
		//myVar.accArrDlg[0][count] = msg.ang[0];
		//myVar.accArrDlg[1][count] = msg.ang[1];
		//myVar.accArrDlg[2][count] = msg.ang[2];
	 }
	/* else if(packet.smid==5){
		myVar.accArrDlg[3][count] = msg.acc[0];
		myVar.accArrDlg[4][count] = msg.acc[1];
		myVar.accArrDlg[5][count] = msg.acc[2];
		//myVar.accArrDlg[0][count] = msg.ang[0];
		//myVar.accArrDlg[1][count] = msg.ang[1];
		//myVar.accArrDlg[2][count] = msg.ang[2];
	 }
	*/


	 else{
		//サンプル数+2で固定する
		//printf("サンプリング終了\n");
		count=myVar.numSample+2;
		count2=myVar.numSample+2;
	}

	count2++;
	if(count2%2==1)//偶数のとき
		count++;

	//++++++++++++++++++++++++++|current acc|+++++++++++++++++++++++++++
	/*
	static int countSeq=0, countSeq2=0;
	if(countSeq<20){
		myVar.curAccArrDlg[0][count] = msg.acc[0];
		myVar.curAccArrDlg[1][count] = msg.acc[1];
		myVar.curAccArrDlg[2][count] = msg.acc[2];
		//myVar.angArrDlg[3][count] = msg.ang[0];
		//myVar.angArrDlg[4][count] = msg.ang[1];
		//myVar.angArrDlg[5][count] = msg.ang[2];

	}else{
		countSeq=0;
		countSeq2=0;
	}
	

	countSeq2++;
	if(countSeq2%2==1)//偶数のとき？
		countSeq++;
		*/
	//static long int countSeq;
	//if(countSeq%50==1){//偶数のとき？
	
	if(packet.smid==1){
		myVar.curAccArrDlg[0] = msgemg.emg[0];
		//myVar.curAccArrDlg[1] = msgemg.emg[1];
		myVar.curAccArrDlg[1] = msgemg.iemg[0];
		//myVar.curAccArrDlg[3] = msgemg.iemg[1];
		//myVar.curAccArrDlg[0] = msg.ang[0];
		//myVar.curAccArrDlg[1] = msg.ang[1];
		//myVar.curAccArrDlg[2] = msg.ang[2];
	//}
			}
	else if(packet.smid==4){
		myVar.curAccArrDlg[2] = msg.acc[0];
		myVar.curAccArrDlg[3] = msg.acc[1];
		myVar.curAccArrDlg[4] = msg.acc[2];
		//myVar.curAccArrDlg[3] = msg.ang[0];
		//myVar.curAccArrDlg[4] = msg.ang[1];
		//myVar.curAccArrDlg[5] = msg.ang[2];
	//}
		}
	//countSeq++;

	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

	/*
	++++++++++++++++++++++++++++++++++++++++<A-4>++++++++++++++++++++++++++++++++++++++
	ここでデータの表示（coutでコマンドプロンプトに，msg.status.Formatでアプリケーション左下に，fprintfにエクセルファイルに表示）
	*/


	// 表示テキスト設定
	///一時コメントアウト11/7///
	/*CString str;
	msg.status.Format("加速度x=%f\n　　 　　y=%f\n　　 　　z=%f\n\n角速度x=%f\n　　 　　y=%f\n　 　　　z=%f\n" , msg.acc[0], msg.acc[1], msg.acc[2] ,msg.ang[0], msg.ang[1], msg.ang[2]);
	msgemg.status.Format("nama=%f\n   AD変換=%f\n ",dataemg.emg[1],msgemg.emg[1]);
	*/
	//+++++++++++++++++++++++++++++++++++++++++++ ↓追加↓（11/18）+++++++++++++++++++++++++++++++++++++++++++
	
	//データが確認できたのでコメントアウト11/2
	//筋電データ出力
    ////出力を一時コメントアウト
	/*
	if(packet.smid==1){
		cout << " ID=1_AD(emg[0]_iemg[0])=" << msgemg.emg[0] <<"_"<< msgemg.iemg[0] << endl;
		cout << " AD(emg[1]_iemg[1])=" << msgemg.emg[1] <<"_"<< msgemg.iemg[1] << endl;
			}
	else if(packet.smid==2){
		cout << " ID=2_AD(emg[0]_iemg[0])=" << msgemg.emg[0] <<"_"<< msgemg.iemg[0] << endl;
		cout << " AD(emg[1]_iemg[1])=" << msgemg.emg[1] <<"_"<< msgemg.iemg[1] << endl;
			}
	else if(packet.smid==3){
		cout << " ID=3_AD(emg[0]_iemg[0])=" << msgemg.emg[0] <<"_"<< msgemg.iemg[0] << endl;
		cout << " AD(emg[1]_iemg[1])=" << msgemg.emg[1] <<"_"<< msgemg.iemg[1] << endl;
			}
	else if(packet.smid==11){
		cout << " ID=11_AD(emg[0]_iemg[0])=" << msgemg.emg[0] <<"_"<< msgemg.iemg[0] << endl;
		cout << " AD(emg[1]_iemg[1])=" << msgemg.emg[1] <<"_"<< msgemg.iemg[1] << endl;
			}
	
	//ジャイロ出力
	
	else if(packet.smid==4){
		cout<< "ID=4 : 加速度(x,y,z)=" <<msg.acc[0] << "_"  << msg.acc[1] << "_"  << msg.acc[2] <<endl;
		//cout<< "       角速度(x,y,z)=" <<msg.ang[0] << "_"  << msg.ang[1] << "_"  << msg.ang[2] <<"\n\n";
		//cout<<"================================================"<<endl;
		//fprintf(fCon->output,"%f\t%f\t%f\t%f\t%f\t%f\n",msg.acc[0],msg.acc[1],msg.acc[2],msg.ang[0],msg.ang[1],msg.ang[2]);
				}
	else if(packet.smid==5){
		cout<< "ID=5 : 加速度(x,y,z)=" <<msg.acc[0] << "_"  << msg.acc[1] << "_"  << msg.acc[2] <<endl;
		//cout<< "       角速度(x,y,z)=" <<msg.ang[0] << "_"  << msg.ang[1] << "_"  << msg.ang[2] <<"\n\n";
		//cout<<"================================================"<<endl;
		//fprintf(fCon->output,"%f\t%f\t%f\t%f\t%f\t%f\n",msg.acc[0],msg.acc[1],msg.acc[2],msg.ang[0],msg.ang[1],msg.ang[2]);
				}
	else if(packet.smid==6){
		cout<< "ID=6 : 加速度(x,y,z)=" <<msg.acc[0] << "_"  << msg.acc[1] << "_"  << msg.acc[2] <<endl;
		//cout<< "       角速度(x,y,z)=" <<msg.ang[0] << "_"  << msg.ang[1] << "_"  << msg.ang[2] <<"\n\n";
		//cout<<"================================================"<<endl;
		//fprintf(fCon->output,"%f\t%f\t%f\t%f\t%f\t%f\n",msg.acc[0],msg.acc[1],msg.acc[2],msg.ang[0],msg.ang[1],msg.ang[2]);
				}
	else if(packet.smid==7){
		cout<< "ID=7 : 加速度(x,y,z)=" <<msg.acc[0] << "_"  << msg.acc[1] << "_"  << msg.acc[2] <<endl;
		//cout<< "       角速度(x,y,z)=" <<msg.ang[0] << "_"  << msg.ang[1] << "_"  << msg.ang[2] <<"\n\n";
		//cout<<"================================================"<<endl;
		//fprintf(fCon->output,"%f\t%f\t%f\t%f\t%f\t%f\n",msg.acc[0],msg.acc[1],msg.acc[2],msg.ang[0],msg.ang[1],msg.ang[2]);
				}
	else if(packet.smid==8){
		cout<< "ID=8 : 加速度(x,y,z)=" <<msg.acc[0] << "_"  << msg.acc[1] << "_"  << msg.acc[2] <<endl;
		//cout<< "       角速度(x,y,z)=" <<msg.ang[0] << "_"  << msg.ang[1] << "_"  << msg.ang[2] <<"\n\n";
		//cout<<"================================================"<<endl;
		//fprintf(fCon->output,"%f\t%f\t%f\t%f\t%f\t%f\n",msg.acc[0],msg.acc[1],msg.acc[2],msg.ang[0],msg.ang[1],msg.ang[2]);
				}
	else if(packet.smid==9){
		cout<< "ID=9 : 加速度(x,y,z)=" <<msg.acc[0] << "_"  << msg.acc[1] << "_"  << msg.acc[2] <<endl;
		//cout<< "       角速度(x,y,z)=" <<msg.ang[0] << "_"  << msg.ang[1] << "_"  << msg.ang[2] <<"\n\n";
		//cout<<"================================================"<<endl;
		//fprintf(fCon->output,"%f\t%f\t%f\t%f\t%f\t%f\n",msg.acc[0],msg.acc[1],msg.acc[2],msg.ang[0],msg.ang[1],msg.ang[2]);
				}
	else if(packet.smid==10){	
		cout<< "ID=10 : 加速度(x,y,z)=" << msg.acc[0] << "_" << msg.acc[1] << "_" << msg.acc[2]  << endl;		
		//cout<< "       角速度(x,y,z)=" <<msg.ang[0] << "_" << msg.ang[1] << "_" << msg.ang[2] <<"\n";
		//cout<<"----------------------------"<<endl;
	//	fprintf(fCon->output,"%f\t%f\t%f\t%f\t%f\t%f\t",msg.acc[0],msg.acc[1],msg.acc[2],msg.ang[0],msg.ang[1],msg.ang[2]);
		}
		
*/
	//+++++++++++++++++++++++++++++++++++++++++++ ↑ここまで↑（11/18）+++++++++++++++++++++++++++++++++
	
	//int i;
	//for(i=0;i<21;i++)/*
	//cout<<"[0][i]"<<m_pScene->accArrDlg[0][1]<<endl;
	

	//fprintf(fCon->output,"%f\t%f\t%f\t%f\t%f\t%f\n",msg.acc[0],msg.acc[1],msg.acc[2],msg.ang[0],msg.ang[1],msg.ang[2]);
	//sleep(0.25); //補正テストのため一次追加②

	
	//<A-4>


	// メインスレッドにメッセージ送信
	::PostMessage(h_dlg, WM_USER_STAT_UPDATE, 0, 0);
	::PostMessage(h_dlg, WM_USER_ACC_UPDATE, 0, 0);
	
}

// 計測停止
void CDllSampleCppDlg::CbStopMeasure(const char *port_name, unsigned char *buffer, int size)
{
    
	// 表示テキスト設定
	CString str;
	msg.status = "計測を停止しました";

	// 加速度データ0リセット
	msg.acc[0] = 0;
	msg.acc[1] = 0;
	msg.acc[2] = 0;

	//筋電データ0リセット1/25
	msgemg.emg[0]=0;
	msgemg.emg[1]=0;
	msgemg.iemg[0]=0;
	msgemg.iemg[1]=0;


	// メインスレッドにメッセージ送信
	::PostMessage(h_dlg, WM_USER_STAT_UPDATE, 0, 0);
	::PostMessage(h_dlg, WM_USER_ACC_UPDATE, 0, 0);
}

// 電源OFF
void CDllSampleCppDlg::CbPwOff(const char *port_name, unsigned char *buffer, int size)
{
	// 表示テキスト設定
	CString str;
	msg.status = "電源を切りました";

	// メインスレッドにメッセージ送信
	::PostMessage(h_dlg, WM_USER_STAT_UPDATE, 0, 0);
}

//////////////////////////////////////////////////////////////////////////////////
// コールバック関数ここまで
//////////////////////////////////////////////////////////////////////////////////




// CDllSampleCppDlg メッセージ ハンドラー

BOOL CDllSampleCppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "バージョン情報..." メニューをシステム メニューに追加します。

	// IDM_ABOUTBOX は、システム コマンドの範囲内になければなりません。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// このダイアログのアイコンを設定します。アプリケーションのメイン ウィンドウがダイアログでない場合、
	//  Framework は、この設定を自動的に行います。
	SetIcon(m_hIcon, TRUE);			// 大きいアイコンの設定
	SetIcon(m_hIcon, FALSE);		// 小さいアイコンの設定


	//////////////////////////////////////////////////////////////////////////////////
	// 追加初期化処理
	//////////////////////////////////////////////////////////////////////////////////

	// ポート名一覧取得
	vector<PortName> pn = Cmd::GetPorts();


	for(int i=0; i<(int)pn.size(); i++)
	{
		mc_combo_port.InsertString(-1, CString(pn[i].name));
	}

	// プロダクトIDの初期化
	mc_spin_pid.SetRange(1, 255);
	//mc_spin_pid.SetPos(1);//テストのため一時ID変更（255→17）
	mc_spin_pid.SetPos(255);//テストのため一時ID変更（255→17）

	// センサモジュールIDの初期化
	mc_spin_smid.SetRange(1, 255);
	//mc_spin_smid.SetPos(2);//テストのため一時ID変更（2→17）
	mc_spin_smid.SetPos(255);//テストのため一時ID変更（2→17）

	// コールバック関数登録
	cmd.SetCmdCallback(DAT_GET_STATUS, CbGetStatus);
	cmd.SetCmdCallback(ACK_PREP_MEASURE, CbPrepMeasure);
	cmd.SetCmdCallback(DAT_START_MEASURE, CbStartMeasure);
	cmd.SetCmdCallback(ACK_STOP_MEASURE, CbStopMeasure);
	cmd.SetCmdCallback(ACK_PW_OFF, CbPwOff);

	// メインスレッドのウィンドウハンドル保存
	h_dlg = this->GetSafeHwnd();

	//////////////////////////////////////////////////////////////////////////////////
	// 追加初期化処理ここまで
	//////////////////////////////////////////////////////////////////////////////////



	//OpenGLの初期化処理-----------------------
	m_pDC = new CClientDC(&m_glView);
	if (SetUpPixelFormat(m_pDC->m_hDC) != FALSE) {
    m_GLRC = wglCreateContext(m_pDC->m_hDC);
    wglMakeCurrent(m_pDC->m_hDC, m_GLRC);
    CRect rc;
    m_glView.GetClientRect(&rc);
    GLint width = rc.Width();
    GLint height = rc.Height();
    GLdouble aspect = (GLdouble)width / (GLdouble)height;

    // OpenGL の初期設定
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-aspect, aspect, -1.0, 1.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); 
  }
	//シーンの生成
    m_pScene = new Scene;
	m_pG_Scene = new G_Scene;


	//ファイルコントロールの生成
	fCon= new FileControl;

	//ファイル読み込みのエディットボックスの初期文字
	SetDlgItemText(IDC_EDIT1,"");
	SetDlgItemText(IDC_EDIT3,"");

	//------------------------------------------





	return TRUE;  // フォーカスをコントロールに設定した場合を除き、TRUE を返します。
}

void CDllSampleCppDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ダイアログに最小化ボタンを追加する場合、アイコンを描画するための
//  下のコードが必要です。ドキュメント/ビュー モデルを使う MFC アプリケーションの場合、
//  これは、Framework によって自動的に設定されます。

void CDllSampleCppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 描画のデバイス コンテキスト

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// クライアントの四角形領域内の中央
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// アイコンの描画
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();

		//OpenGLによる描画---------------------------
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// ここでシーンを描く
		if(!m_pScene->curFlag){
			m_pScene->draw();
		}else{
			m_pScene->draw();
			m_pScene->CurDraw();
		}

		//+++++++++++++++++++++++++
		if(m_pG_Scene->startFlag)
			m_pG_Scene->G_Draw();
		//+++++++++++++++++++++++++

		SwapBuffers(m_pDC->m_hDC);
		//-------------------------------------------


	}
}

// ユーザーが最小化したウィンドウをドラッグしているときに表示するカーソルを取得するために、
//  システムがこの関数を呼び出します。
HCURSOR CDllSampleCppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//////////////////////////////////////////////////////////////////////////////////
// 作成したボタンの処理
//////////////////////////////////////////////////////////////////////////////////

// COMポート接続ボタン
void CDllSampleCppDlg::OnBnClickedButtonConnect()
{
	UpdateData(TRUE);

	// COMポート名取得
	CString str;
	mc_combo_port.GetLBText(mc_combo_port.GetCurSel(), str);

	// 接続成功or失敗
	if(cmd.Open(str))
	{
		mv_static_connection = "状態：接続";
	}
	else
	{
		mv_static_connection = "接続に失敗しました";
	}
	UpdateData(FALSE);
}

// COMポート切断ボタン
void CDllSampleCppDlg::OnBnClickedButtonDisconnect()
{
	UpdateData(TRUE);

	// 切断成功or失敗
	if(cmd.Close())
	{
		mv_static_connection = "状態：切断";
	}
	else
	{
		mv_static_connection = "切断に失敗しました";
	}
	UpdateData(FALSE);
}

// ステータス情報取得ボタン
void CDllSampleCppDlg::OnBnClickedButtonStatus()
{
	// プロダクトID，センサモジュールID取得
	unsigned char pid = mc_spin_pid.GetPos();
	unsigned char smid = mc_spin_smid.GetPos();

	// コマンド送信
	cmd.GetStatus(pid, smid);
}

// 電源OFFボタン
void CDllSampleCppDlg::OnBnClickedButtonPwoff()
{
	// プロダクトID，センサモジュールID取得
	unsigned char pid = mc_spin_pid.GetPos();
	unsigned char smid = mc_spin_smid.GetPos();

	// コマンド送信
	cmd.PwOff(pid, smid);
}
/*
+++++++++++++++++++++++++++++++++++++++++<A-5>++++++++++++++++++++++++++++++++++++++++++++++++
計測モードをここで与える
計測モード：接続台数の変更，サンプリング周波数の変更など．詳しくはpdf"【DLL】wSensor_CmdInterface_rev3_8_0_CPPDLL"の9ページあたり
*/
// 計測準備ボタン		重要！++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void CDllSampleCppDlg::OnBnClickedButtonPrepare()
{
	// プロダクトID，センサモジュールID取得
	unsigned char pid = mc_spin_pid.GetPos();
	unsigned char smid = mc_spin_smid.GetPos();

	// コマンド送信（計測準備、ファイル保存なし）
	cmd.PrepMeasure(pid, smid, "", 69 , "");		//計測モードを10進数で与える（計測モード：pdf"【DLL】wSensor_CmdInterface_rev3_8_0_CPPDLL"の9ページあたり）
}
//<A-5>
// 計測開始ボタン		重要！++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void CDllSampleCppDlg::OnBnClickedButtonStart()
{
	//sleep(1);
	// プロダクトID，センサモジュールID取得
	unsigned char pid = mc_spin_pid.GetPos();
	unsigned char smid = mc_spin_smid.GetPos();

	// 現在時刻取得
	CTime c_time = CTime::GetCurrentTime();
	unsigned char YY = c_time.GetYear() - 2000;
	unsigned char MM = c_time.GetMonth();
	unsigned char DD = c_time.GetDay();
	unsigned char hh = c_time.GetHour();
	unsigned char mm = c_time.GetMinute();
	



	//////////////////////////////////****追加*****/////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////


	//ここでaccArrを確保（ページ1を参照）
	// Allocate
		/*accArr=new double*[3];
		for(ui i=0; i<3; i++) {
			accArr[i] = new double[20];
			
		}
		*//////////////////////////////////////////////////////////↓
		//m_pScene->accScene[0] = msg.acc[0];
		//m_pScene->accScene[1] = msg.acc[1];
		//m_pScene->accScene[2] = msg.acc[2];
		
		//accArr[1] = &msg.acc[1];
		//accArr[2] = &msg.acc[2];
		
		

		//m_pScene->accScene[0] = msg.acc[0];
		//m_pScene->accScene[0] = 12345;

		//msg.acc[0]=12345;

		//sleep(1);
		cout<<"サンプリング開始"<<endl;
		
		//測定時の時間を確認するため追加
/*	clock_t start,end;

	start = clock();

	cout<<"start="<<start<<endl;*/

		/////////////////////////////////////****追加*****///////////////////
		////////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////

	/*
	++++++++++++++++++++++++++++++++++++++++<A-5>+++++++++++++++++++++++++++++++
	すぐ上と同様に計測モードをここで与える
	*/
	// コマンド送信（計測開始、ファイル保存なし）
	cmd.StartMeasure(pid, smid, YY, MM, DD, hh, mm, 69);//計測モードを10進数で与える（計測モード：pdf"【DLL】wSensor_CmdInterface_rev3_8_0_CPPDLL"の9ページあたり）
	
	//cout<<"m_pScene"<<m_pScene->accScene[0]<<endl;
	//<A-5>

}

// 計測停止ボタン
void CDllSampleCppDlg::OnBnClickedButtonEnd()
{
	/*
	clock_t start,end;
	end = clock();

	cout << "start=" << start<<"___end="<< end << endl;
	*/
	// プロダクトID，センサモジュールID取得
	unsigned char pid = mc_spin_pid.GetPos();
	unsigned char smid = mc_spin_smid.GetPos();

	for(int i=0; i<100; i++)
	{
		// コマンド送信（計測停止）
		cmd.StopMeasure(pid, smid);

		Sleep(3);
	}
}

//////////////////////////////////////////////////////////////////////////////////
// 作成したボタンの処理ここまで
//////////////////////////////////////////////////////////////////////////////////

/*
++++++++++++++++++++++++++++++++++++++++<A-6>+++++++++++++++++++++++++++++++++++++
↓のプログラムが”ループ開始”ボタンを押下した時の処理
ジャイロの生データを正規化した後，自己組織化のアルゴリズムに受け渡す（≒自己組織化の実行）．
*/

void CDllSampleCppDlg::OnBnClickedButton1yoko()//ジコソシキカスタート(学習開始ボタン)
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。


	//ここで，SOMを行い，ループごとにInvalidate(FALSE);	UpdateWindow();を呼び出す？
	//Invalidate()が呼ばれるとOnPaint()が呼ばれる．
	//変数の追加で，おそらくRV[][][]を動的に確保した後，Paint()内でm_pScene->temp[][][]にRV[][][]を代入？
	//代入（Paint()内）には，m_pScene->***()関数を用いて代入する必要あり？
	//RV[][][]はPaint()内で使える．
	//RVの型はトリプルポインタで宣言した後，メモリを動的確保．
		

	//↓自己組織化のプログラムの呼び出し（≒実行）

	//srand((ui)time(NULL));
	srand(1);

	
	m_pScene->init_reference();
	for(ui i=0; i<m_pScene->numLearn; i++){
		m_pScene->Som2d(myVar.numSample);
		if(i%50==0){
			Invalidate(FALSE);	// Call onPaint()
			UpdateWindow();		// Redraw Window?
		}

	}
	
//	int kkkk;
//	kkkk=m_pScene->TasTest2();
	
	CString    strData;
	strData.Format("ループ終了　繰り返し数-> %d",m_pScene->numLearn);
	AfxMessageBox(strData);
	
	
}
//<A-6>

bool CDllSampleCppDlg::SetUpPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd = {
    sizeof(PIXELFORMATDESCRIPTOR),  // PFDのサイズ
    1,                              // バージョン
    PFD_DRAW_TO_WINDOW |            // ウィンドウに描画する
    PFD_SUPPORT_OPENGL |            // OpenGLを使う
    PFD_DOUBLEBUFFER,               // ダブルバッファリングする
    PFD_TYPE_RGBA,                  // RGBAモード
    24,                             // カラーバッファは24ビット
    0, 0, 0, 0, 0, 0,               //  (各チャンネルのビット数は指定しない)
    0, 0,                           // アルファバッファは使わない
    0, 0, 0, 0, 0,                  // アキュムレーションバッファは使わない
    32,                             // デプスバッファは32ビット
    0,                              // ステンシルバッファは使わない
    0,                              // 補助バッファは使わない
    PFD_MAIN_PLANE,                 // メインレイヤー
    0,                              //  (予約)
    0, 0, 0                         // レイヤーマスクは無視する
  };
  int pf = ChoosePixelFormat(hdc, &pfd);
  if (pf != 0) return SetPixelFormat(hdc, pf, &pfd);
  return FALSE; 


	return false;
}


void CDllSampleCppDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: ここにメッセージ ハンドラー コードを追加します。
	// 自作OpenGLの削除------------
	delete m_pScene;
	//------------------------------

	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(m_GLRC);
	delete m_pDC;
}


void CDllSampleCppDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: ここにメッセージ ハンドラー コードを追加します。

	//OpenGL-----------------------
	if (wglGetCurrentContext() != NULL) {
    CRect rc;
    m_glView.GetClientRect(&rc);
    GLint width = rc.Width();
    GLint height = rc.Height();
    GLdouble aspect = (GLdouble)width / (GLdouble)height;
    // OpenGLの初期設定
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-aspect, aspect, -1.0, 1.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
	}
	//------------------------------

}


void CDllSampleCppDlg::OnBnClickedButtonTest2()//”button1”ボタンを押下した時の処理
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	m_pScene->init_reference();
	Invalidate(FALSE);	// Call onPaint()
	UpdateWindow();		// Redraw Window?
	
	int kkkk;
	//m_pScene->init_reference();
	//kkkk=m_pScene->TasTest();
	CString    strData;
	strData.Format("ニューロン数=%d\n繰り返し数=%d",m_pScene->numNeuro,m_pScene->numLearn);
	AfxMessageBox(strData);

}


void CDllSampleCppDlg::OnBnClickedButton2test3()//写像終了ボタン
{
	OnBnClickedButtonEnd();	//　計測終了関数
	m_pScene->curFlag=false;
	
}
void TestFunction(void)
{




	CString    strData;
	strData.Format("第二のボタン！");
	AfxMessageBox(strData);
}


void CDllSampleCppDlg::OnBnClickedButtonfilestart()//”fileopen”ボタンを押下した時の処理
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	//fCon->output=fopen("../accdata/acc3.xls","w");
	//fprintf(fCon->output,"acc[0]\tacc[1]\tacc[2]\tang[0]\tang[1]\tang[2]\n");
	//fCon->output=fopen("../refVec/refVec.xls","w");
}


void CDllSampleCppDlg::OnBnClickedButtonFileclose()//”fileclose”ボタンを押下した時の処理
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	fclose(fCon->output);
}

unsigned int CDllSampleCppDlg::ProjectionRoop(void){
		
    while(m_pScene->curFlag){
		
		for(ui i=0; i<6; i++){
			myVar.curAccArrDlg[i]=myVar.curAccArrDlg[i]-m_pScene->min;		// curは最初のaccのmin，maxを用いて正規化
			myVar.curAccArrDlg[i]=myVar.curAccArrDlg[i]/m_pScene->max;		// curは最初のaccのmin，maxを用いて正規化
		}
		
		m_pScene->UseSOM(myVar.curAccArrDlg);

		Invalidate(FALSE);		// Call onPaint()
		//UpdateWindow();		// Redraw Window?

		//sleepを入れないと，OnPaintが高速で呼び出され，次の勝利ノードを探す前にdraw内の座標変換式（pos=*dim）に引っかかる．
		//一定時間更新の意味も含めて用いた方が良い．
		//sleep(0.05);//とりあえずの最高速，まだまだ可能だと思われる
		sleep(0.08);


	}

	//_beginthreadex()を使ったら必要，_beginthread()なら不要．
	_endthread();

	return 0;
}

unsigned int WINAPI CDllSampleCppDlg::ThreadStart(void *obj){

	//　無理やりstaticメンバ関数から標準関数へキャストし，スレッド関数を呼び出す．
	return reinterpret_cast<CDllSampleCppDlg*>(obj)->ProjectionRoop();

}


void CDllSampleCppDlg::OnBnClickedButton1()//”写像開始”ボタンを押下した時の処理
{

	m_pScene->curFlag=true;

	// 新たなThreadでループ開始，スレッド関数は，static関数（ThreadStart()）をかましてから始める．_beginthreadでも_beginthreadexでも可．
	//_beginthread( &CDllSampleCppDlg::ThreadStart, 0, this );
	_beginthreadex( NULL, 0, &CDllSampleCppDlg::ThreadStart, this, 0, NULL );
	
	
}




void CDllSampleCppDlg::OnBnClickedButton3()// 参照ベクトルの保存
{

	// ファイル選択ダイアログで選択したファイル名をm_EditRef（エディットボックスの変数）に代入．
	CString         filter("All Files (*.*)|*.*");
	CFileDialog     selDlg(FALSE, "xls", NULL, OFN_OVERWRITEPROMPT, filter);

	if (selDlg.DoModal() == IDOK)	UpdateData(FALSE);


	unsigned int i,j,k;

	//ファイル選択をキャンセルした場合など
	fCon->output=fopen(selDlg.GetPathName(),"w");
	if(NULL==fCon->output){
		UpdateData();
		return;
	}

	for (i=0; i<m_pScene->numNeuro; i++)
		for (j=0; j<m_pScene->numNeuro; j++)
			for (k=0; k<m_pScene->numInpDim; k++)
				fprintf(fCon->output,"%f\t",m_pScene->refVec[i][j][k]);
	fprintf(fCon->output,"\nmin(preNorm)\t%f\nmax(preNorm)\t%f",m_pScene->min,m_pScene->max);
	fclose(fCon->output);

	m_pScene->curFlag=true;

}


void CDllSampleCppDlg::OnEnChangeEdit1()
{
	// TODO:  これが RICHEDIT コントロールの場合、このコントロールが
	// この通知を送信するには、CDialogEx::OnInitDialog() 関数をオーバーライドし、
	// CRichEditCtrl().SetEventMask() を
	// OR 状態の ENM_CHANGE フラグをマスクに入れて呼び出す必要があります。

	// TODO:  ここにコントロール通知ハンドラー コードを追加してください。
}


void CDllSampleCppDlg::OnEnChangeEdit2()
{
	// TODO:  これが RICHEDIT コントロールの場合、このコントロールが
	// この通知を送信するには、CDialogEx::OnInitDialog() 関数をオーバーライドし、
	// CRichEditCtrl().SetEventMask() を
	// OR 状態の ENM_CHANGE フラグをマスクに入れて呼び出す必要があります。

	// TODO:  ここにコントロール通知ハンドラー コードを追加してください。
}


void CDllSampleCppDlg::OnBnClickedButton4()//参照ベクトルファイル読み込みのボタン
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	// ファイル選択ダイアログで選択したファイル名をm_EditRef（エディットボックスの変数）に代入．
	CString         filter("All Files (*.*)|*.*");
	CFileDialog     selDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, filter);
	
	if (selDlg.DoModal() == IDOK){
		m_EditRef = selDlg.GetFileName();
		UpdateData(FALSE);
	}


	//選択したファイルから参照ベクトルを代入後，更新．
	unsigned int i,j,k,temp;
	char str[100];

	fCon->output=fopen(selDlg.GetPathName(),"r");

	//ファイル選択をキャンセルした場合など
	if(NULL==fCon->output){
		UpdateData();
		return;
	}
		
	for (i=0; i<m_pScene->numNeuro; i++)
		for (j=0; j<m_pScene->numNeuro; j++)
			for (k=0; k<m_pScene->numInpDim; k++)
				temp=fscanf(fCon->output,"%lf",&m_pScene->refVec[i][j][k]);
	temp=fscanf(fCon->output,"%s %lf %s %lf",str,&m_pScene->min,str,&m_pScene->max);
	fclose(fCon->output);
	
	Invalidate(FALSE);	// Call onPaint()
	UpdateWindow();		// Redraw Window?

    
    return;
}


void CDllSampleCppDlg::OnBnClickedButton5()//訓練サンプルの保存
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	// ファイル選択ダイアログで選択したファイル名をm_EditRef（エディットボックスの変数）に代入．
	CString         filter("All Files (*.*)|*.*");
	CFileDialog     selDlg(FALSE, "xls", NULL, OFN_OVERWRITEPROMPT, filter);

	if (selDlg.DoModal() == IDOK)	UpdateData(FALSE);


	unsigned int i,j,k;

	fCon->output=fopen(selDlg.GetPathName(),"w");

	//ファイル選択をキャンセルした場合など
	if(NULL==fCon->output){	
		UpdateData();
		return;
	}

	for (i=0; i<myVar.numSample; i++){
		fprintf(fCon->output,"X%d\t",i);
		for (k=0; k<m_pScene->numInpDim; k++){
			fprintf(fCon->output,"%f\t",m_pScene->subAccArrDlg[k][i]);
		}
		fprintf(fCon->output,"\n");
	}
	fclose(fCon->output);


	
}


void CDllSampleCppDlg::OnBnClickedButton6()//訓練サンプル読み込みボタン
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	// ファイル選択ダイアログで選択したファイル名をm_EditRef（エディットボックスの変数）に代入．
	CString         filter("All Files (*.*)|*.*");
	CFileDialog     selDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, filter);
	
	if (selDlg.DoModal() == IDOK){
		m_EditInp = selDlg.GetFileName();
		UpdateData(FALSE);
	}


	//選択したファイルから入力ベクトルを代入後，更新．
	unsigned int i,j,k,temp;
	char str[100];

	fCon->output=fopen(selDlg.GetPathName(),"r");

	//ファイル選択をキャンセルした場合など
	if(NULL==fCon->output){
		UpdateData();
		return;
	}

	for (i=0; i<myVar.numSample; i++){
		temp=fscanf(fCon->output,"%s",str);
		for (k=0; k<m_pScene->numInpDim; k++){
			temp=fscanf(fCon->output,"%lf",&m_pScene->subAccArrDlg[k][i]);
		}
	}
	fclose(fCon->output);

	
	Invalidate(FALSE);	// Call onPaint()
	UpdateWindow();		// Redraw Window?

    
    return;


}


void CDllSampleCppDlg::OnBnClickedButton7()//フィルタ処理（正規化処理）
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。

	
	
	//++++++++++++++++++++++++++　ここから編集　+++++++++++++++++++++
	
	//myVal.accArrDlgを正規化(0～1)に
	
	//正規化テスト
	/*
	double box[5];
	box[0]=-56;
	box[1]=32;
	box[2]=3;
	box[3]=4;
	box[4]=5;
	*/

	/*
	int i;
	cout<<"～初期値～"<<endl;
	/*
	cout<<"box[1]="<<box[1]<<endl;
	cout<<"box[2]="<<box[2]<<endl;
	cout<<"box[3]="<<box[3]<<endl;
	cout<<"box[4]="<<box[4]<<endl;
	


	*/

	/*
	+++++++++++++++++++++++++++++++++++++++<A-6>++++++++++++++++++++++++++++++++++
	正規化のプログラム
	自己組織化のアルゴリズムに受け渡す際，データを”0～1”の値に正規化しなければならない
	最小値が負の値の場合，それをデータ全体に加えた後，最大値で割ることで正規化
	最小値が正の値の場合，データ全体を最大値で割ることで正規化
	*/

	//最大値(max)と最小値(min)をさがす
	int abc,aaa;
	//double min,max;



	cout<<"myVar="<<endl;
	for(aaa=0;aaa<myVar.numSample;aaa++){
		for(abc=0;abc<5;abc++){
		
			cout<<myVar.accArrDlg[abc][aaa]<<"\t\t";
		}
		cout<<endl;
	}

	
	m_pScene->min = myVar.accArrDlg[0][0];

	//最小値をさがす
	for(abc=0;abc<5;abc++){
		for(aaa=0;aaa<myVar.numSample;aaa++){

			//if(myVar.accArrDlg[abc][aaa]>max)
			//	max = myVar.accArrDlg[abc][aaa];
			if(myVar.accArrDlg[abc][aaa]<m_pScene->min)
				m_pScene->min = myVar.accArrDlg[abc][aaa];
		}
	}


	cout<<"～①minとmaxをさがす～"<<endl;
	//cout<<"最大値・・・"<<max<<endl;
	cout<<"最小値・・・"<<m_pScene->min<<endl<<endl;


	//全ての値に最小値を加え，0以上にする

	if(m_pScene->min<0){

		for(abc=0;abc<5;abc++){
			myVar.curAccArrDlg[abc]=myVar.curAccArrDlg[abc]-m_pScene->min;		// curは最初のaccのmin，maxを用いて正規化
			for(aaa=0;aaa<myVar.numSample;aaa++){
				myVar.accArrDlg[abc][aaa]=myVar.accArrDlg[abc][aaa]-m_pScene->min;
				//myVar.curAccArrDlg[abc][aaa]=myVar.curAccArrDlg[abc][aaa]-m_pScene->min;		// curは最初のaccのmin，maxを用いて正規化
			}
		}
		
	}



	//最大値をさがす
	m_pScene->max = myVar.accArrDlg[0][0];
	for(abc=0;abc<5;abc++){
		for(aaa=0;aaa<myVar.numSample;aaa++){

			if(myVar.accArrDlg[abc][aaa]>m_pScene->max)
				m_pScene->max = myVar.accArrDlg[abc][aaa];
			//if(myVar.accArrDlg[abc][aaa]<min)
			//	min = myVar.accArrDlg[abc][aaa];
		}
	}
	cout<<"最大値・・・"<<m_pScene->max<<endl;
	/*
	cout<<"box[0]="<<box[0]<<endl;
	cout<<"box[1]="<<box[1]<<endl;
	cout<<"box[2]="<<box[2]<<endl;
	cout<<"box[3]="<<box[3]<<endl;
	cout<<"box[4]="<<box[4]<<endl;
	
	min = max = box[0];

	for(abc=0;abc<5;abc++){
		if(box[abc]>max)
			max = box[abc];
		if(box[abc]<min)
			min = box[abc];
	}
	
	cout<<"～②minを全値に加える～"<<endl;
	cout<<"最大値・・・"<<max<<endl;
	cout<<"最小値・・・"<<min<<endl<<endl;
	*/
	for(abc=0;abc<5;abc++){
		myVar.curAccArrDlg[abc]=myVar.curAccArrDlg[abc]/m_pScene->max;			// curは最初のaccのmin，maxを用いて正規化
		for(aaa=0;aaa<myVar.numSample;aaa++){
			myVar.accArrDlg[abc][aaa]=myVar.accArrDlg[abc][aaa]/m_pScene->max;
			//myVar.curAccArrDlg[abc][aaa]=myVar.curAccArrDlg[abc][aaa]/m_pScene->max;			// curは最初のaccのmin，maxを用いて正規化
		}
	}

	/*
	cout<<"～③全値をmaxで割る(0～1に正規化)～"<<endl;
	cout<<"box[0]="<<box[0]<<endl;
	cout<<"box[1]="<<box[1]<<endl;
	cout<<"box[2]="<<box[2]<<endl;
	cout<<"box[3]="<<box[3]<<endl;
	cout<<"box[4]="<<box[4]<<endl;
	*/
	

	cout<<endl;
	cout<<"myVarの正規化="<<endl;
	for(aaa=0;aaa<myVar.numSample;aaa++){
		for(abc=0;abc<5;abc++){
		
			cout<<myVar.accArrDlg[abc][aaa]<<"\t\t";
		}
		cout<<endl;
	}

	//<A-6>
	
	///////////////////////////////////////m_pSceneのaccArrに代入

	int i=0,j=0;
	for(i=0;i<5;i++)
		for(j=0;j<myVar.numSample;j++){
			m_pScene->subAccArrDlg[i][j]=myVar.accArrDlg[i][j];
			//m_pScene->subCurAccArrDlg[i][j]=myVar.curAccArrDlg[i][j];
		}
		//	m_pScene->subangArrDlg[i][j]=myVar.angArrDlg[i][j];

	//cout<<"[0][1]"<<m_pScene->subaccArrDlg[0][1]<<endl;


	//++++++++++++++++++++++++++　ここまで編集　+++++++++++++++++++++
}





//↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
//++++++++++++++++++++++++++++++++++++G+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++↓

void CDllSampleCppDlg::OnBnClickedNandemotestbutton()//ボタン2
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	
	//onPaint()でG_Sceneを呼ぶ
	//if(m_pG_Scene->startCount==1){
	//Initialize++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		for(ui i=0; i<m_pG_Scene->numHorisphe; i++)
			for(ui j=0; j<m_pG_Scene->numVertsphe; j++)
				m_pG_Scene->G_Grid_Init(i,j);			// Initialize (ELIMINATE)
		m_pG_Scene->score=0;
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		m_pG_Scene->startFlag=!m_pG_Scene->startFlag;

		//タイマーの設定
		m_nTimer = SetTimer(1, 600, 0);

		m_pG_Scene->G_Init();

		Invalidate(FALSE);	// Call onPaint()
		UpdateWindow();		// Redraw Window?
	//}


}


void CDllSampleCppDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ここにメッセージ ハンドラー コードを追加するか、既定の処理を呼び出します。
	if(m_pG_Scene->endFlag)
		KillTimer(1);
	else
		m_pG_Scene->G_NextStep();
	
	Invalidate(FALSE);
	UpdateWindow();
	
	CDialogEx::OnTimer(nIDEvent);
}


BOOL CDllSampleCppDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ここに特定なコードを追加するか、もしくは基本クラスを呼び出してください。
	
	//push key && already push "ButtonG"
	if(pMsg->message == WM_KEYDOWN && m_pG_Scene->startFlag){
		switch(pMsg->wParam){
			case VK_TAB:{
				CString str="tabが押された";
				AfxMessageBox(str);
				return true;
						}
			case VK_LEFT:{
				m_pG_Scene->G_Trans('l');
				Invalidate(FALSE);
				UpdateWindow();
				return true;
					 }
	 		case VK_RIGHT:{				
				m_pG_Scene->G_Trans('r');
				Invalidate(FALSE);
				UpdateWindow();
				return true;
					}
			case VK_UP:{
				m_pG_Scene->G_Trans('u');
				Invalidate(FALSE);
				UpdateWindow();
				return true;
					}
			case VK_DOWN:{
				m_pG_Scene->G_Trans('d');
				Invalidate(FALSE);
				UpdateWindow();
				return true;
					}
			case VK_SPACE:{
				m_pG_Scene->G_Trans('0');
				Invalidate(FALSE);
				UpdateWindow();
				return true;
					}
		}
		}else{
			return false;
	}  

	//return CDialogEx::PreTranslateMessage(pMsg);
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void CDllSampleCppDlg::OnBnClickedButton8()//(計測したデータをエクセルに出力する)
{
	
	
	static int i=0;
	//エクセル出力
	
	static int a=0;
	FILE *file;
	file = fopen("test.csv","w");
	for(i<0;i<numSample;i++){
		fprintf(file,"%f\t,%f\t,%f\n",myVar.accArrDlg[4][i],myVar.accArrDlg[5][i],myVar.accArrDlg[6][i]);
	}
	
	fclose(file);
	
	//cout出力
	/*
	cout<<"___データ出力___"<<endl;
	for(i<0;i<numSample;i++){
		cout<<"accx="<<myVar.accArrDlg[4][i]<<"__accy="<<myVar.accArrDlg[5][i]<<"__accz="<<myVar.accArrDlg[6][i]<<endl;
	}*/

	// TODO: ここにコントロール通知ハンドラー コードを追加します。
}

