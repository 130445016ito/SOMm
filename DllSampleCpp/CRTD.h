// [Typelib �N���X�ǉ��E�B�U�[�h] �ō쐬���ꂽ IDispatch ���b�p�[ �N���X�𐶐����܂����B

#import "C:\\Program Files\\Microsoft Office\\Office12\\EXCEL.EXE" no_namespace
// CRTD ���b�p�[ �N���X

class CRTD : public COleDispatchDriver
{
public:
	CRTD(){} // COleDispatchDriver ����̃R���X�g���N�^�[���Ăяo���܂��B
	CRTD(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CRTD(const CRTD& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// RTD ���\�b�h
public:
	long get_ThrottleInterval()
	{
		long result;
		InvokeHelper(0x8c0, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_ThrottleInterval(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x8c0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void RefreshData()
	{
		InvokeHelper(0x8c1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void RestartServers()
	{
		InvokeHelper(0x8c2, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// RTD �v���p�e�B
public:

};
