// [Typelib �N���X�ǉ��E�B�U�[�h] �ō쐬���ꂽ IDispatch ���b�p�[ �N���X�𐶐����܂����B

#import "C:\\Program Files\\Microsoft Office\\Office12\\EXCEL.EXE" no_namespace
// CRTDUpdateEvent ���b�p�[ �N���X

class CRTDUpdateEvent : public COleDispatchDriver
{
public:
	CRTDUpdateEvent(){} // COleDispatchDriver ����̃R���X�g���N�^�[���Ăяo���܂��B
	CRTDUpdateEvent(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CRTDUpdateEvent(const CRTDUpdateEvent& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// IRTDUpdateEvent ���\�b�h
public:
	void UpdateNotify()
	{
		InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	long get_HeartbeatInterval()
	{
		long result;
		InvokeHelper(0xb, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_HeartbeatInterval(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	void Disconnect()
	{
		InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// IRTDUpdateEvent �v���p�e�B
public:

};
