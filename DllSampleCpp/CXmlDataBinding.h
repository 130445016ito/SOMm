// [Typelib �N���X�ǉ��E�B�U�[�h] �ō쐬���ꂽ IDispatch ���b�p�[ �N���X�𐶐����܂����B

#import "C:\\Program Files\\Microsoft Office\\Office12\\EXCEL.EXE" no_namespace
// CXmlDataBinding ���b�p�[ �N���X

class CXmlDataBinding : public COleDispatchDriver
{
public:
	CXmlDataBinding(){} // COleDispatchDriver ����̃R���X�g���N�^�[���Ăяo���܂��B
	CXmlDataBinding(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CXmlDataBinding(const CXmlDataBinding& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// XmlDataBinding ���\�b�h
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
	long Refresh()
	{
		long result;
		InvokeHelper(0x589, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
		return result;
	}
	void LoadSettings(LPCTSTR Url)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x919, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Url);
	}
	void ClearSettings()
	{
		InvokeHelper(0x91a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	CString get_SourceUrl()
	{
		CString result;
		InvokeHelper(0x91b, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}

	// XmlDataBinding �v���p�e�B
public:

};
