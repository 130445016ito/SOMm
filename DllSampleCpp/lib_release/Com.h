///
/// @file  Com.h
/// @brief COM�|�[�g����֘A�N���X
///

#pragma once

#include<windows.h>
#include<setupapi.h>
#include<string>
#include<vector>

#include"Packet.h"

#pragma comment(lib, "setupapi.lib")

using namespace std;

namespace lp_wsm
{
	///
	/// @brief �|�[�g���ێ��p�\���̂ł��B
	///
	struct PortName
	{
		char name[32];      ///< �|�[�g��
		char friendly[256]; ///< �|�[�g�̃t�����h���[�l�[��

		///
		/// �f�t�H���g�R���X�g���N�^�ł��B
		///
		PortName();
	};

	///
	/// @brief COM�|�[�g����N���X�ł��B
	///
	class Com
	{
	public:
		///
		/// @brief �g�p�\��Com�|�[�g�ꗗ���擾���܂��B
		///
		/// @return ���p�\�ȃ|�[�g���̔z��
		///
		__declspec(dllexport) static vector<PortName> GetPorts();
		
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) Com();

		///
		/// @brief �f�X�g���N�^�ł��B
		///
		__declspec(dllexport) ~Com();

		///
		/// @brief COM�|�[�g���I�[�v�����܂��B
		///
		/// @param port_name �I�[�v������|�[�g��
		/// @return �I�[�v���ł������ǂ���
		///
		__declspec(dllexport) bool Open(const char *port_name);

		///
		/// @brief �J���Ă���COM�|�[�g���N���[�Y���܂��B
		///
		/// @return �N���[�Y�ł������ǂ���
		///
		__declspec(dllexport) bool Close();

		///
		/// @brief �f�[�^�𑗐M���܂��B
		///
		/// @param buffer ���M����f�[�^�̔z��
		/// @param bytes �z��̒���
		/// @return ���M�ł������ǂ���
		///
		__declspec(dllexport) bool Write(unsigned char * buffer, unsigned long bytes);

		///
		/// @brief �p�P�b�g��M���̃R�[���o�b�N�֐����w�肵�܂��B
		///
		/// @param func �o�^����R�[���o�b�N�֐�
		///
		__declspec(dllexport) void SetCallback(void (*func)(const char*, unsigned char*, int));

	protected:
		///
		/// @brief COM�|�[�g���ł��B
		///
		string port_name;

	private:
		__declspec(dllexport) static DWORD WINAPI ThreadFunc(LPVOID lpParameter);
		__declspec(dllexport) DWORD Read();

		/// COM�|�[�g
		HANDLE myHComPort;

		/// �C�x���g�҂��X���b�h
		HANDLE myHThread;
		DWORD  myThreadId;

		/// �p�P�b�g��M���̃R�[���o�b�N�֐�
		void (*callback)(const char*, unsigned char*, int);

		/// �p�P�b�g�҂��i�������Ȃ��j
		__declspec(dllexport) virtual void WaitPacket(unsigned char *buffer, int size);
	};
}
