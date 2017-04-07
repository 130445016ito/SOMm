
// DllSampleCppDlg.h : �w�b�_�[ �t�@�C��
//

#pragma once

///////////////////////////////////////
// �C���N���[�h�C�����N�֘A
///////////////////////////////////////

// �w�b�_�t�@�C���C���N���[�h
#include"Cmd.h"


// ����OpenGL���C���N���[�h
#include "Scene.h"

// �X���b�h�g�p�̂���
#include <process.h>

// ���Ԍv��
#include <time.h>



// ���C�u�����̃����N
#pragma comment(lib, "LpWsmDll.lib")

// ���O��Ԏg�p�錾
using namespace lp_wsm;

// �Ǝ����b�Z�[�WID�̒�`
#define WM_USER_STAT_UPDATE (WM_USER + 1)
#define WM_USER_ACC_UPDATE (WM_USER + 2)

///////////////////////////////////////
// �C���N���[�h�C�����N�֘A�����܂�
///////////////////////////////////////

#include "afxwin.h"
#include "afxcmn.h"

// CDllSampleCppDlg �_�C�A���O
class CDllSampleCppDlg : public CDialogEx
{
// �R���X�g���N�V����
public:
	CDllSampleCppDlg(CWnd* pParent = NULL);	// �W���R���X�g���N�^�[

// �_�C�A���O �f�[�^
	enum { IDD = IDD_DLLSAMPLECPP_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �T�|�[�g

// ����
protected:
	HICON m_hIcon;

	// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
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
// �g�p�N���X�C�R�[���o�b�N�֐��錾
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
// �g�p�N���X�C�R�[���o�b�N�֐��錾�����܂�
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
	double *curAccArrDlg;//2��9���ǉ�
	int numSample;

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedNandemotestbutton();

//�@_beginthread�̑������́C�֐��̃|�C���^��n���D
//�@�������C�N���X�̃����o�֐���n���Ƃ��́Cstatic�֐��łȂ��Ƃ��߁D
//�@static�����o�֐��̓C���X�^���X�쐬���Ȃ��Ƃ��C�v���O�����J�n�ƂƂ��ɏ���������邽�߁D
//�@���̂��߁Cstatic�Ŋ֐������C�������L���X�g���ėp����D
//�@�{���̃X���b�h�֐��́CProjectionRoop(void)�D
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
// ���C���X���b�h�ւ̑��M�f�[�^�N���X
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
