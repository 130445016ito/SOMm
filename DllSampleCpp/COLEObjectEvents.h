// [Typelib �N���X�ǉ��E�B�U�[�h] �ō쐬���ꂽ IDispatch ���b�p�[ �N���X�𐶐����܂����B

#import "C:\\Program Files\\Microsoft Office\\Office12\\EXCEL.EXE" no_namespace
// COLEObjectEvents ���b�p�[ �N���X

class COLEObjectEvents : public COleDispatchDriver
{
public:
	COLEObjectEvents(){} // COleDispatchDriver ����̃R���X�g���N�^�[���Ăяo���܂��B
	COLEObjectEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	COLEObjectEvents(const COLEObjectEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// OLEObjectEvents ���\�b�h
public:
	void GotFocus()
	{
		InvokeHelper(0x605, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}
	void LostFocus()
	{
		InvokeHelper(0x606, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// OLEObjectEvents �v���p�e�B
public:

};
