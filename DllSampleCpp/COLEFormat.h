// [Typelib �N���X�ǉ��E�B�U�[�h] �ō쐬���ꂽ IDispatch ���b�p�[ �N���X�𐶐����܂����B

#import "C:\\Program Files\\Microsoft Office\\Office12\\EXCEL.EXE" no_namespace
// COLEFormat ���b�p�[ �N���X

class COLEFormat : public COleDispatchDriver
{
public:
	COLEFormat(){} // COleDispatchDriver ����̃R���X�g���N�^�[���Ăяo���܂��B
	COLEFormat(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	COLEFormat(const COLEFormat& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// OLEFormat ���\�b�h
public:
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x94, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_Creator()
	{
		long result;
		InvokeHelper(0x95, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Parent()
	{
		LPDISPATCH result;
		InvokeHelper(0x96, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void Activate()
	{
		InvokeHelper(0x130, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	LPDISPATCH get_Object()
	{
		LPDISPATCH result;
		InvokeHelper(0x419, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	CString get_progID()
	{
		CString result;
		InvokeHelper(0x5f3, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void Verb(VARIANT& Verb)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x25e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, &Verb);
	}

	// OLEFormat �v���p�e�B
public:

};
