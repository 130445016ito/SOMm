// [Typelib �N���X�ǉ��E�B�U�[�h] �ō쐬���ꂽ IDispatch ���b�p�[ �N���X�𐶐����܂����B

#import "C:\\Program Files\\Microsoft Office\\Office12\\EXCEL.EXE" no_namespace
// CSpellingOptions ���b�p�[ �N���X

class CSpellingOptions : public COleDispatchDriver
{
public:
	CSpellingOptions(){} // COleDispatchDriver ����̃R���X�g���N�^�[���Ăяo���܂��B
	CSpellingOptions(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CSpellingOptions(const CSpellingOptions& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// SpellingOptions ���\�b�h
public:
	long get_DictLang()
	{
		long result;
		InvokeHelper(0x8ac, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_DictLang(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x8ac, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	CString get_UserDict()
	{
		CString result;
		InvokeHelper(0x8ad, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
		return result;
	}
	void put_UserDict(LPCTSTR newValue)
	{
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x8ad, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_IgnoreCaps()
	{
		BOOL result;
		InvokeHelper(0x8ae, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_IgnoreCaps(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8ae, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_SuggestMainOnly()
	{
		BOOL result;
		InvokeHelper(0x8af, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_SuggestMainOnly(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8af, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_IgnoreMixedDigits()
	{
		BOOL result;
		InvokeHelper(0x8b0, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_IgnoreMixedDigits(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8b0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_IgnoreFileNames()
	{
		BOOL result;
		InvokeHelper(0x8b1, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_IgnoreFileNames(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8b1, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_GermanPostReform()
	{
		BOOL result;
		InvokeHelper(0x8b2, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_GermanPostReform(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8b2, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_KoreanCombineAux()
	{
		BOOL result;
		InvokeHelper(0x8b3, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_KoreanCombineAux(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8b3, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_KoreanUseAutoChangeList()
	{
		BOOL result;
		InvokeHelper(0x8b4, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_KoreanUseAutoChangeList(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8b4, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	BOOL get_KoreanProcessCompound()
	{
		BOOL result;
		InvokeHelper(0x8b5, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	void put_KoreanProcessCompound(BOOL newValue)
	{
		static BYTE parms[] = VTS_BOOL ;
		InvokeHelper(0x8b5, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_HebrewModes()
	{
		long result;
		InvokeHelper(0x8b6, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_HebrewModes(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x8b6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_ArabicModes()
	{
		long result;
		InvokeHelper(0x8b7, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_ArabicModes(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x8b7, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}

	// SpellingOptions �v���p�e�B
public:

};
