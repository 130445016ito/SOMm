// [Typelib �N���X�ǉ��E�B�U�[�h] �ō쐬���ꂽ IDispatch ���b�p�[ �N���X�𐶐����܂����B

#import "C:\\Program Files\\Microsoft Office\\Office12\\EXCEL.EXE" no_namespace
// CPivotAxis ���b�p�[ �N���X

class CPivotAxis : public COleDispatchDriver
{
public:
	CPivotAxis(){} // COleDispatchDriver ����̃R���X�g���N�^�[���Ăяo���܂��B
	CPivotAxis(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CPivotAxis(const CPivotAxis& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// PivotAxis ���\�b�h
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
	LPDISPATCH get_PivotLines()
	{
		LPDISPATCH result;
		InvokeHelper(0xa7d, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	// PivotAxis �v���p�e�B
public:

};
