// [Typelib �N���X�ǉ��E�B�U�[�h] �ō쐬���ꂽ IDispatch ���b�p�[ �N���X�𐶐����܂����B

#import "C:\\Program Files\\Microsoft Office\\Office12\\EXCEL.EXE" no_namespace
// CPage ���b�p�[ �N���X

class CPage : public COleDispatchDriver
{
public:
	CPage(){} // COleDispatchDriver ����̃R���X�g���N�^�[���Ăяo���܂��B
	CPage(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CPage(const CPage& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// Page ���\�b�h
public:
	LPDISPATCH get_LeftHeader()
	{
		LPDISPATCH result;
		InvokeHelper(0x3fa, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_CenterHeader()
	{
		LPDISPATCH result;
		InvokeHelper(0x3f3, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_RightHeader()
	{
		LPDISPATCH result;
		InvokeHelper(0x402, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_LeftFooter()
	{
		LPDISPATCH result;
		InvokeHelper(0x3f9, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_CenterFooter()
	{
		LPDISPATCH result;
		InvokeHelper(0x3f2, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}
	LPDISPATCH get_RightFooter()
	{
		LPDISPATCH result;
		InvokeHelper(0x401, DISPATCH_PROPERTYGET, VT_DISPATCH, (void*)&result, NULL);
		return result;
	}

	// Page �v���p�e�B
public:

};
