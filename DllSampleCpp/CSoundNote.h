// [Typelib �N���X�ǉ��E�B�U�[�h] �ō쐬���ꂽ IDispatch ���b�p�[ �N���X�𐶐����܂����B

#import "C:\\Program Files\\Microsoft Office\\Office12\\EXCEL.EXE" no_namespace
// CSoundNote ���b�p�[ �N���X

class CSoundNote : public COleDispatchDriver
{
public:
	CSoundNote(){} // COleDispatchDriver ����̃R���X�g���N�^�[���Ăяo���܂��B
	CSoundNote(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CSoundNote(const CSoundNote& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// ����
public:

	// ����
public:


	// SoundNote ���\�b�h
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
	VARIANT Delete()
	{
		VARIANT result;
		InvokeHelper(0x75, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT Import(LPCTSTR Filename)
	{
		VARIANT result;
		static BYTE parms[] = VTS_BSTR ;
		InvokeHelper(0x395, DISPATCH_METHOD, VT_VARIANT, (void*)&result, parms, Filename);
		return result;
	}
	VARIANT Play()
	{
		VARIANT result;
		InvokeHelper(0x396, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}
	VARIANT Record()
	{
		VARIANT result;
		InvokeHelper(0x397, DISPATCH_METHOD, VT_VARIANT, (void*)&result, NULL);
		return result;
	}

	// SoundNote �v���p�e�B
public:

};
