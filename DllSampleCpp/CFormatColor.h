// [Typelib �N���X�ǉ��E�B�U�[�h] �ō쐬���ꂽ IDispatch ���b�p�[ �N���X�𐶐����܂����B

#import "C:\\Program Files\\Microsoft Office\\Office12\\EXCEL.EXE" no_namespace
// CFormatColor ���b�p�[ �N���X

class CFormatColor : public COleDispatchDriver
{
public:
	CFormatColor(){} // COleDispatchDriver ����̃R���X�g���N�^�[���Ăяo���܂��B
	CFormatColor(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CFormatColor(const CFormatColor& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// FormatColor ���\�b�h
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
	VARIANT get_Color()
	{
		VARIANT result;
		InvokeHelper(0x63, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_Color(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x63, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	long get_ColorIndex()
	{
		long result;
		InvokeHelper(0x61, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_ColorIndex(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x61, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	VARIANT get_ThemeColor()
	{
		VARIANT result;
		InvokeHelper(0x93d, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_ThemeColor(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x93d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}
	VARIANT get_TintAndShade()
	{
		VARIANT result;
		InvokeHelper(0x93e, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	void put_TintAndShade(VARIANT& newValue)
	{
		static BYTE parms[] = VTS_VARIANT ;
		InvokeHelper(0x93e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, &newValue);
	}

	// FormatColor �v���p�e�B
public:

};
