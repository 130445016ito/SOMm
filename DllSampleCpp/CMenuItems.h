// [Typelib �N���X�ǉ��E�B�U�[�h] �ō쐬���ꂽ IDispatch ���b�p�[ �N���X�𐶐����܂����B

#import "C:\\Program Files\\Microsoft Office\\Office12\\EXCEL.EXE" no_namespace
// CMenuItems ���b�p�[ �N���X

class CMenuItems : public COleDispatchDriver
{
public:
	CMenuItems(){} // COleDispatchDriver ����̃R���X�g���N�^�[���Ăяo���܂��B
	CMenuItems(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CMenuItems(const CMenuItems& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// MenuItems ���\�b�h
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
	LPDISPATCH Add(LPCTSTR Caption, VARIANT& OnAction, VARIANT& ShortcutKey, VARIANT& Before, VARIANT& Restore, VARIANT& StatusBar, VARIANT& HelpFile, VARIANT& HelpContextID)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0xb5, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Caption, &OnAction, &ShortcutKey, &Before, &Restore, &StatusBar, &HelpFile, &HelpContextID);
		return result;
	}
	LPDISPATCH AddMenu(LPCTSTR Caption, VARIANT& Before, VARIANT& Restore)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_BSTR VTS_VARIANT VTS_VARIANT ;
		InvokeHelper(0x256, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, parms, Caption, &Before, &Restore);
		return result;
	}
	long get_Count()
	{
		long result;
		InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get__Default(VARIANT& Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, &Index);
		return result;
	}
	LPDISPATCH get_Item(VARIANT& Index)
	{
		LPDISPATCH result;
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0xaa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, parms, &Index);
		return result;
	}
	LPUNKNOWN get__NewEnum()
	{
		LPUNKNOWN result;
		InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
		return result;
	}

	// MenuItems �v���p�e�B
public:

};