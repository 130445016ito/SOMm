/////////////////////////////////////////////////////////////////////////////////////////

//���C���̕ҏW�t�@�C���i�W���C���Z���T�̒ʐM���ׂẴv���O�����j
//�ǉ����ĕҏW���K�v�Ǝv����ӏ��ɂ͔ԍ������Ă���	ex�iA-1�j
/////////////////////////////////////////////////////////////////////////////////////////

// DllSampleCppDlg.cpp : �����t�@�C��
//

#include "stdafx.h"
#include "DllSampleCpp.h"
#include "DllSampleCppDlg.h"
#include "afxdialogex.h"


/*+++++++++++++++++++++++++++++++++++�ǉ��i11/18�j++++++++++++++++++++++++++++++++++++*/

#include <iostream>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


/*++++++++++++++++++++++++++++++++++++++++�ǉ��i11/18�j++++++++++++++++++++++++++++++++++++*/

/*++++++++�ǉ��i12/16�j++++++++++++++*/
#include <Windows.h>
#define sleep(n) Sleep(n*1000)

/*++++++++�ǉ��i12/16�j+++++++++++++++*/

/*++++++++++�ǉ��i2016�E6/15�j+++++++++*/
#include <stdio.h>
#include <time.h>

/*+++++++++�ǉ��i2016�E6/15�j++++++++++*/



using namespace std;

void TestFunction(void);

// �A�v���P�[�V�����̃o�[�W�������Ɏg���� CAboutDlg �_�C�A���O

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �_�C�A���O �f�[�^
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g

// ����
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


// CDllSampleCppDlg �_�C�A���O




CDllSampleCppDlg::CDllSampleCppDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDllSampleCppDlg::IDD, pParent)
	, mv_static_connection(_T("��ԁF�ؒf"))
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
	accArrDlg	��������	curAccArrDlg	�̔z�񐔂𑝂₷�ꍇ�C
	new double�̂��Ƃ̐����𑝂₷
	*/


		//���n��f�[�^�̃T���v����
		numSample=40;//�����l��40


	//�R���X�g���N�^�C�����ŃA���P�[�g����(1/19)++++++++++++++++++++//
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
// ���C���X���b�h�ւ̃��b�Z�[�WPost�֘A
//////////////////////////////////////////////////////////////////////////////////

// ���b�Z�[�W�}�b�v
BEGIN_MESSAGE_MAP(CDllSampleCppDlg, CDialogEx)
	// �Ǝ����b�Z�[�W�ǉ�
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

// ���C���X���b�h�̃E�B���h�E�n���h��
HWND h_dlg;

// ���C���X���b�h�ւ̎󂯓n���f�[�^�N���X
CMsgData msg;
CEmgData msgemg;
//++++++++++| �t�@�C���̓��o�͂̂��߁i�ǂ�����ł��Q�Ƃł���悤�Ɂj�@|+++++++++++++++++
FileControl *fCon;
//+++++++++++| �v�����̒l���i�[���邽�߁b  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
CDllSampleCppDlg myVar;
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++


// ���b�Z�[�W�����i�X�e�[�^�X���X�V�j
LRESULT CDllSampleCppDlg::OnStatUpdate(WPARAM wparam, LPARAM lparam)
{
	// �X�e�[�^�X���\���X�V
	mv_static_status = msg.status;
	UpdateData(FALSE);

	return 0;
}

// ���b�Z�[�W�����i�����x�f�[�^�X�V�j
LRESULT CDllSampleCppDlg::OnAccUpdate(WPARAM wparam, LPARAM lparam)
{
	// �����x�f�[�^�X�V
	mc_progress_x.SetPos((int)(msg.acc[0] / 10.0 * 100));
	mc_progress_y.SetPos((int)(msg.acc[1] / 10.0 * 100));
	mc_progress_z.SetPos((int)(msg.acc[2] / 10.0 * 100));

	return 0;
}

//////////////////////////////////////////////////////////////////////////////////
// ���C���X���b�h�ւ̃��b�Z�[�WPost�֘A�����܂�
//////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////
// �R�[���o�b�N�֐�
//////////////////////////////////////////////////////////////////////////////////

// �X�e�[�^�X���擾
void CDllSampleCppDlg::CbGetStatus(const char *port_name, unsigned char *buffer, int size)
{
	// ��M�p�P�b�g��́i�X�e�[�^�X���擾�j
	DatGetStatus packet(buffer, size);

	// �\���e�L�X�g�ݒ�
	CString str;
	str.Format("�v���_�N�gID�F%d", packet.pid);
	msg.status = str;
	str.Format("%s\n�Z���T���W���[��ID�F%d", msg.status, packet.smid);
	msg.status = str;
	str.Format("%s\n�T���v�����O���g���F%d", msg.status, packet.freq);
	msg.status = str;
	str.Format("%s\n����ch�F%d", msg.status, packet.ch);
	msg.status = str;
	str.Format("%s\n���莞�ԁF%dh : %dm : %ds", msg.status, packet.hh, packet.mm, packet.ss);
	msg.status = str;

	// ���C���X���b�h�Ƀ��b�Z�[�W���M
	::PostMessage(h_dlg, WM_USER_STAT_UPDATE, 0, 0);
}

// �v������
void CDllSampleCppDlg::CbPrepMeasure(const char *port_name, unsigned char *buffer, int size)
{
	// �\���e�L�X�g�ݒ�
	CString str;
	msg.status = "�v�������R�}���h�𑗐M���܂���";

	// ���C���X���b�h�Ƀ��b�Z�[�W���M
	::PostMessage(h_dlg, WM_USER_STAT_UPDATE, 0, 0);
}

// �v���J�n
void CDllSampleCppDlg::CbStartMeasure(const char *port_name, unsigned char *buffer, int size)
{
	// ��M�p�P�b�g���
	DatStartMeasure packet(buffer, size);


	/*
	++++++++++++++++++++++++++++++++++++++++++<A-2>++++++++++++++++++++++++++++++++++++++++++
	AD�ϊ��̃v���O����
	�ύX����Ȃ犴�x�̂�
	*/
	// �����x�f�[�^���/////////��AD�ϊ���////////////////////////
	WmsData data(packet.data[0], packet.pid);
	//�Z���T���̒�`��.h�Q��
	for(int i=0; i<3; i++){
		msg.acc[i] = (data.acc[i] * acc_1) - acc_2;
		msg.ang[i] =( data.ang[i] * ang_1) - ang_2;
	}



	//�ؓd�f�[�^��́iAD�ϊ��j(10/25)
	EmgData dataemg(packet.data[0]);
	for(int i=0; i<2; i++){
		//msgemg.emg[i] = (dataemg.emg[i] / 4095 * 3.3) / ( 6.8 / 11.5 );
		//msgemg.iemg[i] = (dataemg.iemg[i] / 4095 * 3.3) / ( 6.8 / 11.5 );
		///��L�̌v�Z�����ƕs���肾�������߉��L�ɕύX���ȒP�ɂ���(11/2)///
		///msgemg.emg[i] = dataemg.emg[i] * ( 379.5 / 278460 );
		///msgemg.iemg[i] = dataemg.iemg[i] * ( 379.5 / 278460 );
		msgemg.emg[i] = dataemg.emg[i] *  0.0013628528334411 ;
		msgemg.iemg[i] = dataemg.iemg[i] *  0.0013628528334411 ;
	}

	
	/*
	msg.ang[0]=data.ang[0];
	msg.ang[1]=data.ang[1];
	msg.ang[2]=data.ang[2];
	*/

	
	///////////////////�������܂�AD�ϊ���//////////////////////////////
	//<A-2>

	///�S�g�����i�ؓd�v�f�[�^�����j1/17///
	for(int i=0;i<2;i++){
		if(msgemg.emg[i]<0){
			msgemg.emg[i] *= (-1);
		}
		if(msgemg.iemg[i]<0){
			msgemg.iemg[i] *= (-1);
		}
	}

	/*+++++++++++++++++++++++++++++++++++���ǉ����i11/18�j++++++++++++++++++++++++++++++++++++*/

	/*

	+++++++++++++++++++++++++++++++++++++++++<A-3>+++++++++++++++++++++++++++++++++++++++++++++
	�␳�v���O�����i�����x�C�p���x�j
	Y = �� X + ���ŕ␳
	�ڂ����̓��[�h�h�v���O��������h��
	*/
	////////////////////////////////////////////////////////////////////
	//////////////////////////�␳�v���O����////////////////////////////
	////////	Y = �� X + ��    ��:�X���@��:�o�C�A�X	////////////////
	////////////////////////////////////////////////////////////////////
	
	
	//�@�␳�W���̒�` �i�����x�j ������.h�ɒ�`

	//double acc_a_x, acc_a_y, acc_a_z;	//	a:�X��
	//double acc_bias_x, acc_bias_y, acc_bias_z;	//	bias:�o�C�A�X

		//////////////��ID=1�̕␳����////////////

	/*
	
	//�␳�W������
	acc_a_x=1.0;			////////////////////////////////////////	
	acc_a_y=1.0;			////////////////////////////////////////
	acc_a_z=1.0;			////////	�����ɒl����́@�@//////////
	acc_bias_x=-1.6;		////////////////////////////////////////
	acc_bias_y=-0.7;		////////////////////////////////////////
	acc_bias_z=-0.0;		////////////////////////////////////////


	msg.acc[0] = msg.acc[0]*acc_a_x+acc_bias_x;		//////////
	msg.acc[1] = msg.acc[1]*acc_a_y+acc_bias_y;		//�␳��//
	msg.acc[2] = msg.acc[2]*acc_a_z+acc_bias_z;		//////////


	//  �␳�W���̒�`�@�i�p���x�j
	double ang_a_x, ang_a_y, ang_a_z;	//	a:�X��
	double ang_bias_x,ang_bias_y,ang_bias_z;	//	bias:�o�C�A�X


	//�␳�W������
	ang_a_x=1.0;				////////////////////////////////////////
	ang_a_y=1.0;				////////////////////////////////////////
	ang_a_z=1.0;				//////// 	�����ɒl����́@�@//////////
	ang_bias_x=330;				////////////////////////////////////////
	ang_bias_y=340;				////////////////////////////////////////
	ang_bias_z=350;				////////////////////////////////////////


	msg.ang[0] = msg.ang[0]*ang_a_x+ang_bias_x;		//////////
	msg.ang[1] = msg.ang[1]*ang_a_y+ang_bias_y;		//�␳��//
	msg.ang[2] = msg.ang[2]*ang_a_z+ang_bias_z;		//////////


	//}else{
	*/
		//////////////��ID=2�̕␳����////////////

	

		
		//�␳�W������(�����x)�@������.h�ɒ�`
	
	//acc_a_x=2.1476;			////////////////////////////////////////	
	//acc_a_y=2.1891;			////////////////////////////////////////
	//acc_a_z=2.1311;			////////	�����ɒl����́@�@//////////
	//acc_bias_x=-1.5705;		////////////////////////////////////////
	//acc_bias_y=-0.6965;		////////////////////////////////////////
	//acc_bias_z=-0.6287;		////////////////////////////////////////

	
	msg.acc[0] = (msg.acc[0]+acc_bias_x)*acc_a_x;		//////////
	msg.acc[1] = (msg.acc[1]+acc_bias_y)*acc_a_y;		//�␳��//
	msg.acc[2] = (msg.acc[2]+acc_bias_z)*acc_a_z;		//////////
	



	
	//  �␳�W���̒�`�@�i�p���x�j
	double ang_a_x, ang_a_y, ang_a_z;	//	a:�X��
	double ang_bias_x,ang_bias_y,ang_bias_z;	//	bias:�o�C�A�X

	
	//�␳�W������
	ang_a_x=4.09;				///////////////////////////////////////
	ang_a_y=1.0;				///////////////////////////////////////
	ang_a_z=1.0;				/////////	�����ɒl����́@�@/////////
	ang_bias_x=337;				///////////////////////////////////////
	ang_bias_y=0;				///////////////////////////////////////
	ang_bias_z=0;				///////////////////////////////////////


	msg.ang[0] = (msg.ang[0]+ang_bias_x)*ang_a_x;		//////////
	msg.ang[1] = (msg.ang[1]+ang_bias_y)*ang_a_y;		//�␳��//
	msg.ang[2] = (msg.ang[2]+ang_bias_z)*ang_a_z;		//////////
	//}
	
	/////////////////////////////////////////////////////////////////////
	//////////////////////	�␳�v���O�����I���  ///////////////////////
	/////////////////////////////////////////////////////////////////////

	//sleep(0.01); //�␳�e�X�g�̂��߈ꎟ�ǉ��@

	//<A-3>
	
	/*+++++++++++++++++++++++++++++++++++�@�������܂Œǉ����i11/18�j++++++++++++++++++++++++++++++++++++*/
	
	
	//static int iii=0;	//�e�X�g�i12/16�j
	static int count=0, count2=0;
	//iii++;

	
	////���[�p�X�t�B���^///////
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



	/////////////////*�Z���T�ʂŃf�[�^�ۊǁi10/21�j*////////////
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
		//�T���v����+2�ŌŒ肷��
		//printf("�T���v�����O�I��\n");
		count=myVar.numSample+2;
		count2=myVar.numSample+2;
	}

	count2++;
	if(count2%2==1)//�����̂Ƃ�
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
	if(countSeq2%2==1)//�����̂Ƃ��H
		countSeq++;
		*/
	//static long int countSeq;
	//if(countSeq%50==1){//�����̂Ƃ��H
	
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
	�����Ńf�[�^�̕\���icout�ŃR�}���h�v�����v�g�ɁCmsg.status.Format�ŃA�v���P�[�V���������ɁCfprintf�ɃG�N�Z���t�@�C���ɕ\���j
	*/


	// �\���e�L�X�g�ݒ�
	///�ꎞ�R�����g�A�E�g11/7///
	/*CString str;
	msg.status.Format("�����xx=%f\n�@�@ �@�@y=%f\n�@�@ �@�@z=%f\n\n�p���xx=%f\n�@�@ �@�@y=%f\n�@ �@�@�@z=%f\n" , msg.acc[0], msg.acc[1], msg.acc[2] ,msg.ang[0], msg.ang[1], msg.ang[2]);
	msgemg.status.Format("nama=%f\n   AD�ϊ�=%f\n ",dataemg.emg[1],msgemg.emg[1]);
	*/
	//+++++++++++++++++++++++++++++++++++++++++++ ���ǉ����i11/18�j+++++++++++++++++++++++++++++++++++++++++++
	
	//�f�[�^���m�F�ł����̂ŃR�����g�A�E�g11/2
	//�ؓd�f�[�^�o��
    ////�o�͂��ꎞ�R�����g�A�E�g
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
	
	//�W���C���o��
	
	else if(packet.smid==4){
		cout<< "ID=4 : �����x(x,y,z)=" <<msg.acc[0] << "_"  << msg.acc[1] << "_"  << msg.acc[2] <<endl;
		//cout<< "       �p���x(x,y,z)=" <<msg.ang[0] << "_"  << msg.ang[1] << "_"  << msg.ang[2] <<"\n\n";
		//cout<<"================================================"<<endl;
		//fprintf(fCon->output,"%f\t%f\t%f\t%f\t%f\t%f\n",msg.acc[0],msg.acc[1],msg.acc[2],msg.ang[0],msg.ang[1],msg.ang[2]);
				}
	else if(packet.smid==5){
		cout<< "ID=5 : �����x(x,y,z)=" <<msg.acc[0] << "_"  << msg.acc[1] << "_"  << msg.acc[2] <<endl;
		//cout<< "       �p���x(x,y,z)=" <<msg.ang[0] << "_"  << msg.ang[1] << "_"  << msg.ang[2] <<"\n\n";
		//cout<<"================================================"<<endl;
		//fprintf(fCon->output,"%f\t%f\t%f\t%f\t%f\t%f\n",msg.acc[0],msg.acc[1],msg.acc[2],msg.ang[0],msg.ang[1],msg.ang[2]);
				}
	else if(packet.smid==6){
		cout<< "ID=6 : �����x(x,y,z)=" <<msg.acc[0] << "_"  << msg.acc[1] << "_"  << msg.acc[2] <<endl;
		//cout<< "       �p���x(x,y,z)=" <<msg.ang[0] << "_"  << msg.ang[1] << "_"  << msg.ang[2] <<"\n\n";
		//cout<<"================================================"<<endl;
		//fprintf(fCon->output,"%f\t%f\t%f\t%f\t%f\t%f\n",msg.acc[0],msg.acc[1],msg.acc[2],msg.ang[0],msg.ang[1],msg.ang[2]);
				}
	else if(packet.smid==7){
		cout<< "ID=7 : �����x(x,y,z)=" <<msg.acc[0] << "_"  << msg.acc[1] << "_"  << msg.acc[2] <<endl;
		//cout<< "       �p���x(x,y,z)=" <<msg.ang[0] << "_"  << msg.ang[1] << "_"  << msg.ang[2] <<"\n\n";
		//cout<<"================================================"<<endl;
		//fprintf(fCon->output,"%f\t%f\t%f\t%f\t%f\t%f\n",msg.acc[0],msg.acc[1],msg.acc[2],msg.ang[0],msg.ang[1],msg.ang[2]);
				}
	else if(packet.smid==8){
		cout<< "ID=8 : �����x(x,y,z)=" <<msg.acc[0] << "_"  << msg.acc[1] << "_"  << msg.acc[2] <<endl;
		//cout<< "       �p���x(x,y,z)=" <<msg.ang[0] << "_"  << msg.ang[1] << "_"  << msg.ang[2] <<"\n\n";
		//cout<<"================================================"<<endl;
		//fprintf(fCon->output,"%f\t%f\t%f\t%f\t%f\t%f\n",msg.acc[0],msg.acc[1],msg.acc[2],msg.ang[0],msg.ang[1],msg.ang[2]);
				}
	else if(packet.smid==9){
		cout<< "ID=9 : �����x(x,y,z)=" <<msg.acc[0] << "_"  << msg.acc[1] << "_"  << msg.acc[2] <<endl;
		//cout<< "       �p���x(x,y,z)=" <<msg.ang[0] << "_"  << msg.ang[1] << "_"  << msg.ang[2] <<"\n\n";
		//cout<<"================================================"<<endl;
		//fprintf(fCon->output,"%f\t%f\t%f\t%f\t%f\t%f\n",msg.acc[0],msg.acc[1],msg.acc[2],msg.ang[0],msg.ang[1],msg.ang[2]);
				}
	else if(packet.smid==10){	
		cout<< "ID=10 : �����x(x,y,z)=" << msg.acc[0] << "_" << msg.acc[1] << "_" << msg.acc[2]  << endl;		
		//cout<< "       �p���x(x,y,z)=" <<msg.ang[0] << "_" << msg.ang[1] << "_" << msg.ang[2] <<"\n";
		//cout<<"----------------------------"<<endl;
	//	fprintf(fCon->output,"%f\t%f\t%f\t%f\t%f\t%f\t",msg.acc[0],msg.acc[1],msg.acc[2],msg.ang[0],msg.ang[1],msg.ang[2]);
		}
		
*/
	//+++++++++++++++++++++++++++++++++++++++++++ �������܂Ł��i11/18�j+++++++++++++++++++++++++++++++++
	
	//int i;
	//for(i=0;i<21;i++)/*
	//cout<<"[0][i]"<<m_pScene->accArrDlg[0][1]<<endl;
	

	//fprintf(fCon->output,"%f\t%f\t%f\t%f\t%f\t%f\n",msg.acc[0],msg.acc[1],msg.acc[2],msg.ang[0],msg.ang[1],msg.ang[2]);
	//sleep(0.25); //�␳�e�X�g�̂��߈ꎟ�ǉ��A

	
	//<A-4>


	// ���C���X���b�h�Ƀ��b�Z�[�W���M
	::PostMessage(h_dlg, WM_USER_STAT_UPDATE, 0, 0);
	::PostMessage(h_dlg, WM_USER_ACC_UPDATE, 0, 0);
	
}

// �v����~
void CDllSampleCppDlg::CbStopMeasure(const char *port_name, unsigned char *buffer, int size)
{
    
	// �\���e�L�X�g�ݒ�
	CString str;
	msg.status = "�v�����~���܂���";

	// �����x�f�[�^0���Z�b�g
	msg.acc[0] = 0;
	msg.acc[1] = 0;
	msg.acc[2] = 0;

	//�ؓd�f�[�^0���Z�b�g1/25
	msgemg.emg[0]=0;
	msgemg.emg[1]=0;
	msgemg.iemg[0]=0;
	msgemg.iemg[1]=0;


	// ���C���X���b�h�Ƀ��b�Z�[�W���M
	::PostMessage(h_dlg, WM_USER_STAT_UPDATE, 0, 0);
	::PostMessage(h_dlg, WM_USER_ACC_UPDATE, 0, 0);
}

// �d��OFF
void CDllSampleCppDlg::CbPwOff(const char *port_name, unsigned char *buffer, int size)
{
	// �\���e�L�X�g�ݒ�
	CString str;
	msg.status = "�d����؂�܂���";

	// ���C���X���b�h�Ƀ��b�Z�[�W���M
	::PostMessage(h_dlg, WM_USER_STAT_UPDATE, 0, 0);
}

//////////////////////////////////////////////////////////////////////////////////
// �R�[���o�b�N�֐������܂�
//////////////////////////////////////////////////////////////////////////////////




// CDllSampleCppDlg ���b�Z�[�W �n���h���[

BOOL CDllSampleCppDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// "�o�[�W�������..." ���j���[���V�X�e�� ���j���[�ɒǉ����܂��B

	// IDM_ABOUTBOX �́A�V�X�e�� �R�}���h�͈͓̔��ɂȂ���΂Ȃ�܂���B
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

	// ���̃_�C�A���O�̃A�C�R����ݒ肵�܂��B�A�v���P�[�V�����̃��C�� �E�B���h�E���_�C�A���O�łȂ��ꍇ�A
	//  Framework �́A���̐ݒ�������I�ɍs���܂��B
	SetIcon(m_hIcon, TRUE);			// �傫���A�C�R���̐ݒ�
	SetIcon(m_hIcon, FALSE);		// �������A�C�R���̐ݒ�


	//////////////////////////////////////////////////////////////////////////////////
	// �ǉ�����������
	//////////////////////////////////////////////////////////////////////////////////

	// �|�[�g���ꗗ�擾
	vector<PortName> pn = Cmd::GetPorts();


	for(int i=0; i<(int)pn.size(); i++)
	{
		mc_combo_port.InsertString(-1, CString(pn[i].name));
	}

	// �v���_�N�gID�̏�����
	mc_spin_pid.SetRange(1, 255);
	//mc_spin_pid.SetPos(1);//�e�X�g�̂��߈ꎞID�ύX�i255��17�j
	mc_spin_pid.SetPos(255);//�e�X�g�̂��߈ꎞID�ύX�i255��17�j

	// �Z���T���W���[��ID�̏�����
	mc_spin_smid.SetRange(1, 255);
	//mc_spin_smid.SetPos(2);//�e�X�g�̂��߈ꎞID�ύX�i2��17�j
	mc_spin_smid.SetPos(255);//�e�X�g�̂��߈ꎞID�ύX�i2��17�j

	// �R�[���o�b�N�֐��o�^
	cmd.SetCmdCallback(DAT_GET_STATUS, CbGetStatus);
	cmd.SetCmdCallback(ACK_PREP_MEASURE, CbPrepMeasure);
	cmd.SetCmdCallback(DAT_START_MEASURE, CbStartMeasure);
	cmd.SetCmdCallback(ACK_STOP_MEASURE, CbStopMeasure);
	cmd.SetCmdCallback(ACK_PW_OFF, CbPwOff);

	// ���C���X���b�h�̃E�B���h�E�n���h���ۑ�
	h_dlg = this->GetSafeHwnd();

	//////////////////////////////////////////////////////////////////////////////////
	// �ǉ����������������܂�
	//////////////////////////////////////////////////////////////////////////////////



	//OpenGL�̏���������-----------------------
	m_pDC = new CClientDC(&m_glView);
	if (SetUpPixelFormat(m_pDC->m_hDC) != FALSE) {
    m_GLRC = wglCreateContext(m_pDC->m_hDC);
    wglMakeCurrent(m_pDC->m_hDC, m_GLRC);
    CRect rc;
    m_glView.GetClientRect(&rc);
    GLint width = rc.Width();
    GLint height = rc.Height();
    GLdouble aspect = (GLdouble)width / (GLdouble)height;

    // OpenGL �̏����ݒ�
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-aspect, aspect, -1.0, 1.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity(); 
  }
	//�V�[���̐���
    m_pScene = new Scene;
	m_pG_Scene = new G_Scene;


	//�t�@�C���R���g���[���̐���
	fCon= new FileControl;

	//�t�@�C���ǂݍ��݂̃G�f�B�b�g�{�b�N�X�̏�������
	SetDlgItemText(IDC_EDIT1,"");
	SetDlgItemText(IDC_EDIT3,"");

	//------------------------------------------





	return TRUE;  // �t�H�[�J�X���R���g���[���ɐݒ肵���ꍇ�������ATRUE ��Ԃ��܂��B
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

// �_�C�A���O�ɍŏ����{�^����ǉ�����ꍇ�A�A�C�R����`�悷�邽�߂�
//  ���̃R�[�h���K�v�ł��B�h�L�������g/�r���[ ���f�����g�� MFC �A�v���P�[�V�����̏ꍇ�A
//  ����́AFramework �ɂ���Ď����I�ɐݒ肳��܂��B

void CDllSampleCppDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �`��̃f�o�C�X �R���e�L�X�g

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// �N���C�A���g�̎l�p�`�̈���̒���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �A�C�R���̕`��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();

		//OpenGL�ɂ��`��---------------------------
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// �����ŃV�[����`��
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

// ���[�U�[���ŏ��������E�B���h�E���h���b�O���Ă���Ƃ��ɕ\������J�[�\�����擾���邽�߂ɁA
//  �V�X�e�������̊֐����Ăяo���܂��B
HCURSOR CDllSampleCppDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//////////////////////////////////////////////////////////////////////////////////
// �쐬�����{�^���̏���
//////////////////////////////////////////////////////////////////////////////////

// COM�|�[�g�ڑ��{�^��
void CDllSampleCppDlg::OnBnClickedButtonConnect()
{
	UpdateData(TRUE);

	// COM�|�[�g���擾
	CString str;
	mc_combo_port.GetLBText(mc_combo_port.GetCurSel(), str);

	// �ڑ�����or���s
	if(cmd.Open(str))
	{
		mv_static_connection = "��ԁF�ڑ�";
	}
	else
	{
		mv_static_connection = "�ڑ��Ɏ��s���܂���";
	}
	UpdateData(FALSE);
}

// COM�|�[�g�ؒf�{�^��
void CDllSampleCppDlg::OnBnClickedButtonDisconnect()
{
	UpdateData(TRUE);

	// �ؒf����or���s
	if(cmd.Close())
	{
		mv_static_connection = "��ԁF�ؒf";
	}
	else
	{
		mv_static_connection = "�ؒf�Ɏ��s���܂���";
	}
	UpdateData(FALSE);
}

// �X�e�[�^�X���擾�{�^��
void CDllSampleCppDlg::OnBnClickedButtonStatus()
{
	// �v���_�N�gID�C�Z���T���W���[��ID�擾
	unsigned char pid = mc_spin_pid.GetPos();
	unsigned char smid = mc_spin_smid.GetPos();

	// �R�}���h���M
	cmd.GetStatus(pid, smid);
}

// �d��OFF�{�^��
void CDllSampleCppDlg::OnBnClickedButtonPwoff()
{
	// �v���_�N�gID�C�Z���T���W���[��ID�擾
	unsigned char pid = mc_spin_pid.GetPos();
	unsigned char smid = mc_spin_smid.GetPos();

	// �R�}���h���M
	cmd.PwOff(pid, smid);
}
/*
+++++++++++++++++++++++++++++++++++++++++<A-5>++++++++++++++++++++++++++++++++++++++++++++++++
�v�����[�h�������ŗ^����
�v�����[�h�F�ڑ��䐔�̕ύX�C�T���v�����O���g���̕ύX�ȂǁD�ڂ�����pdf"�yDLL�zwSensor_CmdInterface_rev3_8_0_CPPDLL"��9�y�[�W������
*/
// �v�������{�^��		�d�v�I++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void CDllSampleCppDlg::OnBnClickedButtonPrepare()
{
	// �v���_�N�gID�C�Z���T���W���[��ID�擾
	unsigned char pid = mc_spin_pid.GetPos();
	unsigned char smid = mc_spin_smid.GetPos();

	// �R�}���h���M�i�v�������A�t�@�C���ۑ��Ȃ��j
	cmd.PrepMeasure(pid, smid, "", 69 , "");		//�v�����[�h��10�i���ŗ^����i�v�����[�h�Fpdf"�yDLL�zwSensor_CmdInterface_rev3_8_0_CPPDLL"��9�y�[�W������j
}
//<A-5>
// �v���J�n�{�^��		�d�v�I++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
void CDllSampleCppDlg::OnBnClickedButtonStart()
{
	//sleep(1);
	// �v���_�N�gID�C�Z���T���W���[��ID�擾
	unsigned char pid = mc_spin_pid.GetPos();
	unsigned char smid = mc_spin_smid.GetPos();

	// ���ݎ����擾
	CTime c_time = CTime::GetCurrentTime();
	unsigned char YY = c_time.GetYear() - 2000;
	unsigned char MM = c_time.GetMonth();
	unsigned char DD = c_time.GetDay();
	unsigned char hh = c_time.GetHour();
	unsigned char mm = c_time.GetMinute();
	



	//////////////////////////////////****�ǉ�*****/////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////////////////


	//������accArr���m�ہi�y�[�W1���Q�Ɓj
	// Allocate
		/*accArr=new double*[3];
		for(ui i=0; i<3; i++) {
			accArr[i] = new double[20];
			
		}
		*//////////////////////////////////////////////////////////��
		//m_pScene->accScene[0] = msg.acc[0];
		//m_pScene->accScene[1] = msg.acc[1];
		//m_pScene->accScene[2] = msg.acc[2];
		
		//accArr[1] = &msg.acc[1];
		//accArr[2] = &msg.acc[2];
		
		

		//m_pScene->accScene[0] = msg.acc[0];
		//m_pScene->accScene[0] = 12345;

		//msg.acc[0]=12345;

		//sleep(1);
		cout<<"�T���v�����O�J�n"<<endl;
		
		//���莞�̎��Ԃ��m�F���邽�ߒǉ�
/*	clock_t start,end;

	start = clock();

	cout<<"start="<<start<<endl;*/

		/////////////////////////////////////****�ǉ�*****///////////////////
		////////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////

	/*
	++++++++++++++++++++++++++++++++++++++++<A-5>+++++++++++++++++++++++++++++++
	������Ɠ��l�Ɍv�����[�h�������ŗ^����
	*/
	// �R�}���h���M�i�v���J�n�A�t�@�C���ۑ��Ȃ��j
	cmd.StartMeasure(pid, smid, YY, MM, DD, hh, mm, 69);//�v�����[�h��10�i���ŗ^����i�v�����[�h�Fpdf"�yDLL�zwSensor_CmdInterface_rev3_8_0_CPPDLL"��9�y�[�W������j
	
	//cout<<"m_pScene"<<m_pScene->accScene[0]<<endl;
	//<A-5>

}

// �v����~�{�^��
void CDllSampleCppDlg::OnBnClickedButtonEnd()
{
	/*
	clock_t start,end;
	end = clock();

	cout << "start=" << start<<"___end="<< end << endl;
	*/
	// �v���_�N�gID�C�Z���T���W���[��ID�擾
	unsigned char pid = mc_spin_pid.GetPos();
	unsigned char smid = mc_spin_smid.GetPos();

	for(int i=0; i<100; i++)
	{
		// �R�}���h���M�i�v����~�j
		cmd.StopMeasure(pid, smid);

		Sleep(3);
	}
}

//////////////////////////////////////////////////////////////////////////////////
// �쐬�����{�^���̏��������܂�
//////////////////////////////////////////////////////////////////////////////////

/*
++++++++++++++++++++++++++++++++++++++++<A-6>+++++++++++++++++++++++++++++++++++++
���̃v���O�������h���[�v�J�n�h�{�^���������������̏���
�W���C���̐��f�[�^�𐳋K��������C���ȑg�D���̃A���S���Y���Ɏ󂯓n���i�����ȑg�D���̎��s�j�D
*/

void CDllSampleCppDlg::OnBnClickedButton1yoko()//�W�R�\�V�L�J�X�^�[�g(�w�K�J�n�{�^��)
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B


	//�����ŁCSOM���s���C���[�v���Ƃ�Invalidate(FALSE);	UpdateWindow();���Ăяo���H
	//Invalidate()���Ă΂���OnPaint()���Ă΂��D
	//�ϐ��̒ǉ��ŁC�����炭RV[][][]�𓮓I�Ɋm�ۂ�����CPaint()����m_pScene->temp[][][]��RV[][][]�����H
	//����iPaint()���j�ɂ́Cm_pScene->***()�֐���p���đ������K�v����H
	//RV[][][]��Paint()���Ŏg����D
	//RV�̌^�̓g���v���|�C���^�Ő錾������C�������𓮓I�m�ہD
		

	//�����ȑg�D���̃v���O�����̌Ăяo���i�����s�j

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
	strData.Format("���[�v�I���@�J��Ԃ���-> %d",m_pScene->numLearn);
	AfxMessageBox(strData);
	
	
}
//<A-6>

bool CDllSampleCppDlg::SetUpPixelFormat(HDC hdc)
{
	PIXELFORMATDESCRIPTOR pfd = {
    sizeof(PIXELFORMATDESCRIPTOR),  // PFD�̃T�C�Y
    1,                              // �o�[�W����
    PFD_DRAW_TO_WINDOW |            // �E�B���h�E�ɕ`�悷��
    PFD_SUPPORT_OPENGL |            // OpenGL���g��
    PFD_DOUBLEBUFFER,               // �_�u���o�b�t�@�����O����
    PFD_TYPE_RGBA,                  // RGBA���[�h
    24,                             // �J���[�o�b�t�@��24�r�b�g
    0, 0, 0, 0, 0, 0,               //  (�e�`�����l���̃r�b�g���͎w�肵�Ȃ�)
    0, 0,                           // �A���t�@�o�b�t�@�͎g��Ȃ�
    0, 0, 0, 0, 0,                  // �A�L�������[�V�����o�b�t�@�͎g��Ȃ�
    32,                             // �f�v�X�o�b�t�@��32�r�b�g
    0,                              // �X�e���V���o�b�t�@�͎g��Ȃ�
    0,                              // �⏕�o�b�t�@�͎g��Ȃ�
    PFD_MAIN_PLANE,                 // ���C�����C���[
    0,                              //  (�\��)
    0, 0, 0                         // ���C���[�}�X�N�͖�������
  };
  int pf = ChoosePixelFormat(hdc, &pfd);
  if (pf != 0) return SetPixelFormat(hdc, pf, &pfd);
  return FALSE; 


	return false;
}


void CDllSampleCppDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: �����Ƀ��b�Z�[�W �n���h���[ �R�[�h��ǉ����܂��B
	// ����OpenGL�̍폜------------
	delete m_pScene;
	//------------------------------

	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(m_GLRC);
	delete m_pDC;
}


void CDllSampleCppDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �����Ƀ��b�Z�[�W �n���h���[ �R�[�h��ǉ����܂��B

	//OpenGL-----------------------
	if (wglGetCurrentContext() != NULL) {
    CRect rc;
    m_glView.GetClientRect(&rc);
    GLint width = rc.Width();
    GLint height = rc.Height();
    GLdouble aspect = (GLdouble)width / (GLdouble)height;
    // OpenGL�̏����ݒ�
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-aspect, aspect, -1.0, 1.0, -10.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
	}
	//------------------------------

}


void CDllSampleCppDlg::OnBnClickedButtonTest2()//�hbutton1�h�{�^���������������̏���
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	m_pScene->init_reference();
	Invalidate(FALSE);	// Call onPaint()
	UpdateWindow();		// Redraw Window?
	
	int kkkk;
	//m_pScene->init_reference();
	//kkkk=m_pScene->TasTest();
	CString    strData;
	strData.Format("�j���[������=%d\n�J��Ԃ���=%d",m_pScene->numNeuro,m_pScene->numLearn);
	AfxMessageBox(strData);

}


void CDllSampleCppDlg::OnBnClickedButton2test3()//�ʑ��I���{�^��
{
	OnBnClickedButtonEnd();	//�@�v���I���֐�
	m_pScene->curFlag=false;
	
}
void TestFunction(void)
{




	CString    strData;
	strData.Format("���̃{�^���I");
	AfxMessageBox(strData);
}


void CDllSampleCppDlg::OnBnClickedButtonfilestart()//�hfileopen�h�{�^���������������̏���
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	//fCon->output=fopen("../accdata/acc3.xls","w");
	//fprintf(fCon->output,"acc[0]\tacc[1]\tacc[2]\tang[0]\tang[1]\tang[2]\n");
	//fCon->output=fopen("../refVec/refVec.xls","w");
}


void CDllSampleCppDlg::OnBnClickedButtonFileclose()//�hfileclose�h�{�^���������������̏���
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	fclose(fCon->output);
}

unsigned int CDllSampleCppDlg::ProjectionRoop(void){
		
    while(m_pScene->curFlag){
		
		for(ui i=0; i<6; i++){
			myVar.curAccArrDlg[i]=myVar.curAccArrDlg[i]-m_pScene->min;		// cur�͍ŏ���acc��min�Cmax��p���Đ��K��
			myVar.curAccArrDlg[i]=myVar.curAccArrDlg[i]/m_pScene->max;		// cur�͍ŏ���acc��min�Cmax��p���Đ��K��
		}
		
		m_pScene->UseSOM(myVar.curAccArrDlg);

		Invalidate(FALSE);		// Call onPaint()
		//UpdateWindow();		// Redraw Window?

		//sleep�����Ȃ��ƁCOnPaint�������ŌĂяo����C���̏����m�[�h��T���O��draw���̍��W�ϊ����ipos=*dim�j�Ɉ���������D
		//��莞�ԍX�V�̈Ӗ����܂߂ėp���������ǂ��D
		//sleep(0.05);//�Ƃ肠�����̍ō����C�܂��܂��\���Ǝv����
		sleep(0.08);


	}

	//_beginthreadex()���g������K�v�C_beginthread()�Ȃ�s�v�D
	_endthread();

	return 0;
}

unsigned int WINAPI CDllSampleCppDlg::ThreadStart(void *obj){

	//�@�������static�����o�֐�����W���֐��փL���X�g���C�X���b�h�֐����Ăяo���D
	return reinterpret_cast<CDllSampleCppDlg*>(obj)->ProjectionRoop();

}


void CDllSampleCppDlg::OnBnClickedButton1()//�h�ʑ��J�n�h�{�^���������������̏���
{

	m_pScene->curFlag=true;

	// �V����Thread�Ń��[�v�J�n�C�X���b�h�֐��́Cstatic�֐��iThreadStart()�j�����܂��Ă���n�߂�D_beginthread�ł�_beginthreadex�ł��D
	//_beginthread( &CDllSampleCppDlg::ThreadStart, 0, this );
	_beginthreadex( NULL, 0, &CDllSampleCppDlg::ThreadStart, this, 0, NULL );
	
	
}




void CDllSampleCppDlg::OnBnClickedButton3()// �Q�ƃx�N�g���̕ۑ�
{

	// �t�@�C���I���_�C�A���O�őI�������t�@�C������m_EditRef�i�G�f�B�b�g�{�b�N�X�̕ϐ��j�ɑ���D
	CString         filter("All Files (*.*)|*.*");
	CFileDialog     selDlg(FALSE, "xls", NULL, OFN_OVERWRITEPROMPT, filter);

	if (selDlg.DoModal() == IDOK)	UpdateData(FALSE);


	unsigned int i,j,k;

	//�t�@�C���I�����L�����Z�������ꍇ�Ȃ�
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
	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void CDllSampleCppDlg::OnEnChangeEdit2()
{
	// TODO:  ���ꂪ RICHEDIT �R���g���[���̏ꍇ�A���̃R���g���[����
	// ���̒ʒm�𑗐M����ɂ́ACDialogEx::OnInitDialog() �֐����I�[�o�[���C�h���A
	// CRichEditCtrl().SetEventMask() ��
	// OR ��Ԃ� ENM_CHANGE �t���O���}�X�N�ɓ���ČĂяo���K�v������܂��B

	// TODO:  �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����Ă��������B
}


void CDllSampleCppDlg::OnBnClickedButton4()//�Q�ƃx�N�g���t�@�C���ǂݍ��݂̃{�^��
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B

	// �t�@�C���I���_�C�A���O�őI�������t�@�C������m_EditRef�i�G�f�B�b�g�{�b�N�X�̕ϐ��j�ɑ���D
	CString         filter("All Files (*.*)|*.*");
	CFileDialog     selDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, filter);
	
	if (selDlg.DoModal() == IDOK){
		m_EditRef = selDlg.GetFileName();
		UpdateData(FALSE);
	}


	//�I�������t�@�C������Q�ƃx�N�g��������C�X�V�D
	unsigned int i,j,k,temp;
	char str[100];

	fCon->output=fopen(selDlg.GetPathName(),"r");

	//�t�@�C���I�����L�����Z�������ꍇ�Ȃ�
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


void CDllSampleCppDlg::OnBnClickedButton5()//�P���T���v���̕ۑ�
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B

	// �t�@�C���I���_�C�A���O�őI�������t�@�C������m_EditRef�i�G�f�B�b�g�{�b�N�X�̕ϐ��j�ɑ���D
	CString         filter("All Files (*.*)|*.*");
	CFileDialog     selDlg(FALSE, "xls", NULL, OFN_OVERWRITEPROMPT, filter);

	if (selDlg.DoModal() == IDOK)	UpdateData(FALSE);


	unsigned int i,j,k;

	fCon->output=fopen(selDlg.GetPathName(),"w");

	//�t�@�C���I�����L�����Z�������ꍇ�Ȃ�
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


void CDllSampleCppDlg::OnBnClickedButton6()//�P���T���v���ǂݍ��݃{�^��
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B

	// �t�@�C���I���_�C�A���O�őI�������t�@�C������m_EditRef�i�G�f�B�b�g�{�b�N�X�̕ϐ��j�ɑ���D
	CString         filter("All Files (*.*)|*.*");
	CFileDialog     selDlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, filter);
	
	if (selDlg.DoModal() == IDOK){
		m_EditInp = selDlg.GetFileName();
		UpdateData(FALSE);
	}


	//�I�������t�@�C��������̓x�N�g��������C�X�V�D
	unsigned int i,j,k,temp;
	char str[100];

	fCon->output=fopen(selDlg.GetPathName(),"r");

	//�t�@�C���I�����L�����Z�������ꍇ�Ȃ�
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


void CDllSampleCppDlg::OnBnClickedButton7()//�t�B���^�����i���K�������j
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B

	
	
	//++++++++++++++++++++++++++�@��������ҏW�@+++++++++++++++++++++
	
	//myVal.accArrDlg�𐳋K��(0�`1)��
	
	//���K���e�X�g
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
	cout<<"�`�����l�`"<<endl;
	/*
	cout<<"box[1]="<<box[1]<<endl;
	cout<<"box[2]="<<box[2]<<endl;
	cout<<"box[3]="<<box[3]<<endl;
	cout<<"box[4]="<<box[4]<<endl;
	


	*/

	/*
	+++++++++++++++++++++++++++++++++++++++<A-6>++++++++++++++++++++++++++++++++++
	���K���̃v���O����
	���ȑg�D���̃A���S���Y���Ɏ󂯓n���ہC�f�[�^���h0�`1�h�̒l�ɐ��K�����Ȃ���΂Ȃ�Ȃ�
	�ŏ��l�����̒l�̏ꍇ�C������f�[�^�S�̂ɉ�������C�ő�l�Ŋ��邱�ƂŐ��K��
	�ŏ��l�����̒l�̏ꍇ�C�f�[�^�S�̂��ő�l�Ŋ��邱�ƂŐ��K��
	*/

	//�ő�l(max)�ƍŏ��l(min)��������
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

	//�ŏ��l��������
	for(abc=0;abc<5;abc++){
		for(aaa=0;aaa<myVar.numSample;aaa++){

			//if(myVar.accArrDlg[abc][aaa]>max)
			//	max = myVar.accArrDlg[abc][aaa];
			if(myVar.accArrDlg[abc][aaa]<m_pScene->min)
				m_pScene->min = myVar.accArrDlg[abc][aaa];
		}
	}


	cout<<"�`�@min��max���������`"<<endl;
	//cout<<"�ő�l�E�E�E"<<max<<endl;
	cout<<"�ŏ��l�E�E�E"<<m_pScene->min<<endl<<endl;


	//�S�Ă̒l�ɍŏ��l�������C0�ȏ�ɂ���

	if(m_pScene->min<0){

		for(abc=0;abc<5;abc++){
			myVar.curAccArrDlg[abc]=myVar.curAccArrDlg[abc]-m_pScene->min;		// cur�͍ŏ���acc��min�Cmax��p���Đ��K��
			for(aaa=0;aaa<myVar.numSample;aaa++){
				myVar.accArrDlg[abc][aaa]=myVar.accArrDlg[abc][aaa]-m_pScene->min;
				//myVar.curAccArrDlg[abc][aaa]=myVar.curAccArrDlg[abc][aaa]-m_pScene->min;		// cur�͍ŏ���acc��min�Cmax��p���Đ��K��
			}
		}
		
	}



	//�ő�l��������
	m_pScene->max = myVar.accArrDlg[0][0];
	for(abc=0;abc<5;abc++){
		for(aaa=0;aaa<myVar.numSample;aaa++){

			if(myVar.accArrDlg[abc][aaa]>m_pScene->max)
				m_pScene->max = myVar.accArrDlg[abc][aaa];
			//if(myVar.accArrDlg[abc][aaa]<min)
			//	min = myVar.accArrDlg[abc][aaa];
		}
	}
	cout<<"�ő�l�E�E�E"<<m_pScene->max<<endl;
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
	
	cout<<"�`�Amin��S�l�ɉ�����`"<<endl;
	cout<<"�ő�l�E�E�E"<<max<<endl;
	cout<<"�ŏ��l�E�E�E"<<min<<endl<<endl;
	*/
	for(abc=0;abc<5;abc++){
		myVar.curAccArrDlg[abc]=myVar.curAccArrDlg[abc]/m_pScene->max;			// cur�͍ŏ���acc��min�Cmax��p���Đ��K��
		for(aaa=0;aaa<myVar.numSample;aaa++){
			myVar.accArrDlg[abc][aaa]=myVar.accArrDlg[abc][aaa]/m_pScene->max;
			//myVar.curAccArrDlg[abc][aaa]=myVar.curAccArrDlg[abc][aaa]/m_pScene->max;			// cur�͍ŏ���acc��min�Cmax��p���Đ��K��
		}
	}

	/*
	cout<<"�`�B�S�l��max�Ŋ���(0�`1�ɐ��K��)�`"<<endl;
	cout<<"box[0]="<<box[0]<<endl;
	cout<<"box[1]="<<box[1]<<endl;
	cout<<"box[2]="<<box[2]<<endl;
	cout<<"box[3]="<<box[3]<<endl;
	cout<<"box[4]="<<box[4]<<endl;
	*/
	

	cout<<endl;
	cout<<"myVar�̐��K��="<<endl;
	for(aaa=0;aaa<myVar.numSample;aaa++){
		for(abc=0;abc<5;abc++){
		
			cout<<myVar.accArrDlg[abc][aaa]<<"\t\t";
		}
		cout<<endl;
	}

	//<A-6>
	
	///////////////////////////////////////m_pScene��accArr�ɑ��

	int i=0,j=0;
	for(i=0;i<5;i++)
		for(j=0;j<myVar.numSample;j++){
			m_pScene->subAccArrDlg[i][j]=myVar.accArrDlg[i][j];
			//m_pScene->subCurAccArrDlg[i][j]=myVar.curAccArrDlg[i][j];
		}
		//	m_pScene->subangArrDlg[i][j]=myVar.angArrDlg[i][j];

	//cout<<"[0][1]"<<m_pScene->subaccArrDlg[0][1]<<endl;


	//++++++++++++++++++++++++++�@�����܂ŕҏW�@+++++++++++++++++++++
}





//������������������������������������������������������������������������������������������������������������
//++++++++++++++++++++++++++++++++++++G+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++��

void CDllSampleCppDlg::OnBnClickedNandemotestbutton()//�{�^��2
{
	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
	
	//onPaint()��G_Scene���Ă�
	//if(m_pG_Scene->startCount==1){
	//Initialize++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
		for(ui i=0; i<m_pG_Scene->numHorisphe; i++)
			for(ui j=0; j<m_pG_Scene->numVertsphe; j++)
				m_pG_Scene->G_Grid_Init(i,j);			// Initialize (ELIMINATE)
		m_pG_Scene->score=0;
		//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

		m_pG_Scene->startFlag=!m_pG_Scene->startFlag;

		//�^�C�}�[�̐ݒ�
		m_nTimer = SetTimer(1, 600, 0);

		m_pG_Scene->G_Init();

		Invalidate(FALSE);	// Call onPaint()
		UpdateWindow();		// Redraw Window?
	//}


}


void CDllSampleCppDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �����Ƀ��b�Z�[�W �n���h���[ �R�[�h��ǉ����邩�A����̏������Ăяo���܂��B
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
	// TODO: �����ɓ���ȃR�[�h��ǉ����邩�A�������͊�{�N���X���Ăяo���Ă��������B
	
	//push key && already push "ButtonG"
	if(pMsg->message == WM_KEYDOWN && m_pG_Scene->startFlag){
		switch(pMsg->wParam){
			case VK_TAB:{
				CString str="tab�������ꂽ";
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

void CDllSampleCppDlg::OnBnClickedButton8()//(�v�������f�[�^���G�N�Z���ɏo�͂���)
{
	
	
	static int i=0;
	//�G�N�Z���o��
	
	static int a=0;
	FILE *file;
	file = fopen("test.csv","w");
	for(i<0;i<numSample;i++){
		fprintf(file,"%f\t,%f\t,%f\n",myVar.accArrDlg[4][i],myVar.accArrDlg[5][i],myVar.accArrDlg[6][i]);
	}
	
	fclose(file);
	
	//cout�o��
	/*
	cout<<"___�f�[�^�o��___"<<endl;
	for(i<0;i<numSample;i++){
		cout<<"accx="<<myVar.accArrDlg[4][i]<<"__accy="<<myVar.accArrDlg[5][i]<<"__accz="<<myVar.accArrDlg[6][i]<<endl;
	}*/

	// TODO: �����ɃR���g���[���ʒm�n���h���[ �R�[�h��ǉ����܂��B
}

