// [Typelib �N���X�ǉ��E�B�U�[�h] �ō쐬���ꂽ IDispatch ���b�p�[ �N���X�𐶐����܂����B

#import "C:\\Program Files\\Microsoft Office\\Office12\\EXCEL.EXE" no_namespace
// CXPath ���b�p�[ �N���X

class CXPath : public COleDispatchDriver
{
public:
	CXPath(){} // COleDispatchDriver ����̃R���X�g���N�^�[���Ăяo���܂��B
	CXPath(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CXPath(const CXPath& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// XPath ���\�b�h
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
	CString get__Default()
	{
		CString result;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	CString get_Value()
	{
		CString result;
		InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Map()
	{
		LPDISPATCH result;
		InvokeHelper(0x8d6, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	void SetValue(LPDISPATCH Map, LPCTSTR XPath, VARIANT& SelectionNamespace, VARIANT& Repeating)
	{
		static BYTE parms[] = VTS_DISPATCH VTS_BSTR VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x936, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Map, XPath, &SelectionNamespace, &Repeating);
	}
	void Clear()
	{
		InvokeHelper(0x6f, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	BOOL get_Repeating()
	{
		BOOL result;
		InvokeHelper(0x938, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}

	// XPath �v���p�e�B
public:

};
