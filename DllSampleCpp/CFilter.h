// [Typelib �N���X�ǉ��E�B�U�[�h] �ō쐬���ꂽ IDispatch ���b�p�[ �N���X�𐶐����܂����B

#import "C:\\Program Files\\Microsoft Office\\Office12\\EXCEL.EXE" no_namespace
// CFilter ���b�p�[ �N���X

class CFilter : public COleDispatchDriver
{
public:
	CFilter(){} // COleDispatchDriver ����̃R���X�g���N�^�[���Ăяo���܂��B
	CFilter(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CFilter(const CFilter& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// Filter ���\�b�h
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
	BOOL get_On()
	{
		BOOL result;
		InvokeHelper(0x652, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
		return result;
	}
	VARIANT get_Criteria1()
	{
		VARIANT result;
		InvokeHelper(0x31c, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	long get__Operator()
	{
		long result;
		InvokeHelper(0xa51, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	VARIANT get_Criteria2()
	{
		VARIANT result;
		InvokeHelper(0x31e, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	long get_Operator()
	{
		long result;
		InvokeHelper(0x31d, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	void put_Operator(long newValue)
	{
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x31d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, newValue);
	}
	long get_Count()
	{
		long result;
		InvokeHelper(0x76, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}

	// Filter �v���p�e�B
public:

};
