// [Typelib �N���X�ǉ��E�B�U�[�h] �ō쐬���ꂽ IDispatch ���b�p�[ �N���X�𐶐����܂����B

#import "C:\\Program Files\\Microsoft Office\\Office12\\EXCEL.EXE" no_namespace
// CSpeech ���b�p�[ �N���X

class CSpeech : public COleDispatchDriver
{
public:
	CSpeech(){} // COleDispatchDriver ����̃R���X�g���N�^�[���Ăяo���܂��B
	CSpeech(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CSpeech(const CSpeech& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// Speech ���\�b�h
public:
	void Speak(LPCTSTR Text, VARIANT& SpeakAsync, VARIANT& SpeakXML, VARIANT& Purge)
	{
		static BYTE parms[] = VTS_BSTR VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x7e1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Text, &SpeakAsync, &SpeakXML, &Purge);
	}
	long get_Direction()
	{
		long result;
		InvokeHelper(0xa8, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Direction(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0xa8, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_SpeakCellOnEnter()
	{
		BOOL result;
		InvokeHelper(0x8bb, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_SpeakCellOnEnter(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8bb, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// Speech �v���p�e�B
public:

};
