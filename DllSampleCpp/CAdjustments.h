// [Typelib �N���X�ǉ��E�B�U�[�h] �ō쐬���ꂽ IDispatch ���b�p�[ �N���X�𐶐����܂����B

#import "C:\\Program Files\\Microsoft Office\\Office12\\EXCEL.EXE" no_namespace
// CAdjustments ���b�p�[ �N���X

class CAdjustments : public COleDispatchDriver
{
public:
	CAdjustments(){} // COleDispatchDriver ����̃R���X�g���N�^�[���Ăяo���܂��B
	CAdjustments(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAdjustments(const CAdjustments& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// Adjustments ���\�b�h
public:
	LPDISPATCH get_Application()
	{
		LPDISPATCH result;
		InvokeHelper(0x60020000, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_Creator()
	{
		long result;
		InvokeHelper(0x60020001, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_Parent()
	{
		LPDISPATCH result;
		InvokeHelper(0x1, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	long get_Count()
	{
		long result;
		InvokeHelper(0x2, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
		return result;
	}
	float get_Item(long Index)
	{
		float result;
		static BYTE parms[] = VTS_I4 ;
		InvokeHelper(0x0, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, parms, Index);
		return result;
	}
	void put_Item(long Index, float newValue)
	{
		static BYTE parms[] = VTS_I4 VTS_R4 ;
		InvokeHelper(0x0, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms, Index, newValue);
	}

	// Adjustments �v���p�e�B
public:

};
