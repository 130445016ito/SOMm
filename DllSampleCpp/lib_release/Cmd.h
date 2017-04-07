///
/// @file  Cmd.h
/// @brief ����M�R�}���h�����N���X
///

#pragma once

#include"Com.h"
#include"Table.h"
#include"Packet.h"

#include<map>
#include<queue>
#include<vector>

using namespace std;

namespace lp_wsm
{
	///
	/// @brief ����M�R�}���h�����N���X�ł��B
	///
	class Cmd : public Com
	{
	public:
		///
		/// @brief �X�e�[�^�X���擾�R�}���h�𑗐M���܂��B
		///
		/// @param pid  �v���_�N�gID
		/// @param smid �ΏۃZ���T���W���[��ID
		///
		__declspec(dllexport) void GetStatus(unsigned char pid, unsigned char smid);

		///
		/// @brief �v�������R�}���h�𑗐M���܂��B
		///
		/// @param pid      �v���_�N�gID
		/// @param smid     �ΏۃZ���T���W���[��ID
		/// @param filename �t�@�C����
		/// @param mode     �v�����[�h
		/// @param comment  �t�@�C���R�����g
		///
		__declspec(dllexport) void PrepMeasure(unsigned char pid, unsigned char smid, const char *filename, unsigned char mode, const char *comment);

		///
		/// @brief �v���J�n�R�}���h�𑗐M���܂��B
		///
		/// @param pid  �v���_�N�gID
		/// @param smid �ΏۃZ���T���W���[��ID
		/// @param YY   �v���J�n���ԁi�N�j
		/// @param MM   �v���J�n���ԁi���j
		/// @param DD   �v���J�n���ԁi���j
		/// @param hh   �v���J�n���ԁi���j
		/// @param mm   �v���J�n���ԁi���j
		/// @param mode �v�����[�h
		///
		__declspec(dllexport) void StartMeasure(unsigned char pid, unsigned char smid, unsigned char YY, unsigned char MM, unsigned char DD, unsigned char hh, unsigned char mm, unsigned char mode);

		///
		/// @brief �v����~�R�}���h�𑗐M���܂��B
		///
		/// @param pid  �v���_�N�gID
		/// @param smid �ΏۃZ���T���W���[��ID
		///
		__declspec(dllexport) void StopMeasure(unsigned char pid, unsigned char smid);

		///
		/// @brief �����R�}���h�𑗐M���܂��B
		///
		/// @param pid     �v���_�N�gID
		/// @param smid    �ΏۃZ���T���W���[��ID
		/// @param sync_no �����ԍ�
		///
		__declspec(dllexport) void Sync(unsigned char pid, unsigned char smid, unsigned char sync_no);

		///
		/// @brief �����ԍ��ǂݏo���R�}���h�𑗐M���܂��B
		///
		/// @param pid     �v���_�N�gID
		/// @param smid    �ΏۃZ���T���W���[��ID
		/// @param file_no �t�@�C���ԍ�
		///
		__declspec(dllexport) void ReadSync(unsigned char pid, unsigned char smid, unsigned char file_no);

		///
		/// @brief �t�@�C�����擾�R�}���h�𑗐M���܂��B
		///
		/// @param pid  �v���_�N�gID
		/// @param smid �ΏۃZ���T���W���[��ID
		///
		__declspec(dllexport) void GetFileInfo(unsigned char pid, unsigned char smid);

		///
		/// @brief �ŐV�t�@�C�����擾�R�}���h�𑗐M���܂��B
		///
		/// @param pid  �v���_�N�gID
		/// @param smid �ΏۃZ���T���W���[��ID
		///
		__declspec(dllexport) void GetLastFileInfo(unsigned char pid, unsigned char smid);

		///
		/// @brief �t�@�C�����擾2�R�}���h�𑗐M���܂��B
		///
		/// @param pid      �v���_�N�gID
		/// @param smid     �ΏۃZ���T���W���[��ID
		/// @param send_num ���M��
		///
		__declspec(dllexport) void GetFileInfo2(unsigned char pid, unsigned char smid, unsigned char send_num);

		///
		/// @brief �t�@�C���f�[�^�擾�R�}���h�𑗐M���܂��B
		///
		/// @param pid       �v���_�N�gID
		/// @param smid      �ΏۃZ���T���W���[��ID
		/// @param file_no   �t�@�C���ԍ�
		/// @param seq_start �J�n�V�[�P���X�ԍ�
		/// @param seq_num   �V�[�P���X��
		///
		__declspec(dllexport) void ReadFile(unsigned char pid, unsigned char smid, unsigned char file_no, unsigned int seq_start = 0, unsigned int seq_num = 0xFFFFFFFF);

		///
		/// @brief �t�@�C���f�[�^�擾�g���R�}���h�𑗐M���܂��B
		///
		/// @param pid       �v���_�N�gID
		/// @param smid      �ΏۃZ���T���W���[��ID
		/// @param file_no   �t�@�C���ԍ�
		/// @param seq_start �J�n�V�[�P���X�ԍ�
		/// @param seq_num   �V�[�P���X��
		/// @param send_num  ���d���M��
		///
		__declspec(dllexport) void ReadFileEx(unsigned char pid, unsigned char smid, unsigned char file_no, unsigned int seq_start = 0, unsigned int seq_num = 0xFFFFFFFF, unsigned char send_num = 1);

		///
		/// @brief �ŐV�t�@�C���f�[�^�擾�R�}���h�𑗐M���܂��B
		///
		/// @param pid       �v���_�N�gID
		/// @param smid      �ΏۃZ���T���W���[��ID
		/// @param seq_start �J�n�V�[�P���X�ԍ�
		/// @param seq_num   �V�[�P���X��
		///
		__declspec(dllexport) void ReadLastFile(unsigned char pid, unsigned char smid, unsigned int seq_start = 0, unsigned int seq_num = 0xFFFFFFFF);

		///
		/// @brief �t�@�C���f�[�^�擾2�R�}���h�𑗐M���܂��B
		///
		/// @param pid      �v���_�N�gID
		/// @param smid     �ΏۃZ���T���W���[��ID
		/// @param send_num ���M��
		/// @param filename �t�@�C����
		///
		__declspec(dllexport) void ReadFile2(unsigned char pid, unsigned char smid, unsigned char send_num, const char *filename);

		///
		/// @brief �t�@�C���R�����g�擾�R�}���h�𑗐M���܂��B
		///
		/// @param pid     �v���_�N�gID
		/// @param smid    �ΏۃZ���T���W���[��ID
		/// @param file_no �t�@�C���ԍ�
		///
		__declspec(dllexport) void ReadComment(unsigned char pid, unsigned char smid, unsigned char file_no);

		///
		/// @brief �t�@�C���R�����g�������݃R�}���h�𑗐M���܂��B
		///
		/// @param pid     �v���_�N�gID
		/// @param smid    �ΏۃZ���T���W���[��ID
		/// @param file_no �t�@�C���ԍ�
		/// @param comment �t�@�C���R�����g
		///
		__declspec(dllexport) void WriteComment(unsigned char pid, unsigned char smid, unsigned char file_no, const char *comment);

		///
		/// @brief �����������R�}���h�𑗐M���܂��B
		///
		/// @param pid  �v���_�N�gID
		/// @param smid �ΏۃZ���T���W���[��ID
		///
		__declspec(dllexport) void EraseMemory(unsigned char pid, unsigned char smid);

		///
		/// @brief ID�ݒ�R�}���h�𑗐M���܂��B
		///
		/// @param pid  �v���_�N�gID
		/// @param smid �ΏۃZ���T���W���[��ID
		/// @param id   ID�i1�`254���w��\�j
		///
		__declspec(dllexport) void SetId(unsigned char pid, unsigned char smid, unsigned char id);

		///
		/// @brief �����`�����l���ݒ�R�}���h�𑗐M���܂��B
		///
		/// @param pid  �v���_�N�gID
		/// @param smid �ΏۃZ���T���W���[��ID
		/// @param ch   �����`�����l��
		///
		__declspec(dllexport) void SetCh(unsigned char pid, unsigned char smid, unsigned char ch);

		///
		/// @brief �T���v�����O���g���ݒ�R�}���h�𑗐M���܂��B
		///
		/// @param pid  �v���_�N�gID
		/// @param smid �ΏۃZ���T���W���[��ID
		/// @param freq �T���v�����O���g��
		///
		__declspec(dllexport) void SetFreq(unsigned char pid, unsigned char smid, unsigned short freq);

		///
		/// @brief �v�����Ԑݒ�R�}���h�𑗐M���܂��B
		///
		/// @param pid  �v���_�N�gID
		/// @param smid �ΏۃZ���T���W���[��ID
		/// @param hh   �v�����ԁi���j
		/// @param mm   �v�����ԁi���j
		/// @param ss   �v�����ԁi�b�j
		///
		__declspec(dllexport) void SetTime(unsigned char pid, unsigned char smid, unsigned char hh, unsigned char mm, unsigned char ss);

		///
		/// @brief 9�����C�����X���[�V�����Z���T�̒n���C�Q�C���ݒ�R�}���h�𑗐M���܂��B
		///
		/// @param pid  �v���_�N�gID
		/// @param smid �ΏۃZ���T���W���[��ID
		/// @param gain �n���C�Z���T�Q�C��
		///
		__declspec(dllexport) void SetMagneticGain(unsigned char pid, unsigned char smid, unsigned char gain);

		///
		/// @brief �Z���T��ŗL�ݒ�R�}���h�𑗐M���܂��B
		///
		/// @param pid         �v���_�N�gID
		/// @param smid        �ΏۃZ���T���W���[��ID
		/// @param target      �ΏۃZ���T
		/// @param sub         �T�u����
		/// @param config      �ŗL�ݒ�
		/// @param config_size �ŗL�ݒ�̗L���o�C�g��
		///
		__declspec(dllexport) void SetUniqConfig(unsigned char pid, unsigned char smid, unsigned char target, unsigned short sub, unsigned char *config, unsigned char config_size);

		///
		/// @brief ���C�����X�ؓd�Z���T�̃Q�C���ݒ�R�}���h�𑗐M���܂��B
		///
		/// @param pid  �v���_�N�gID
		/// @param smid �ΏۃZ���T���W���[��ID
		/// @param gain �Q�C���ݒ�l
		///
		__declspec(dllexport) void SetMyoGain(unsigned char pid, unsigned char smid, unsigned char gain);

		///
		/// @brief �O���ڑ��@��ŗL�ݒ菑�����݃R�}���h�𑗐M���܂��B
		///
		/// @param pid         �v���_�N�gID
		/// @param smid        �ΏۃZ���T���W���[��ID
		/// @param target      �Ώۋ@��
		/// @param sub         �T�u����
		/// @param config      �ŗL�ݒ�
		/// @param config_size �ŗL�ݒ�̗L���o�C�g��
		///
		__declspec(dllexport) void SetExDevice(unsigned char pid, unsigned char smid, unsigned char target, unsigned short sub, unsigned char *config, unsigned char config_size);

		///
		/// @brief �O���ڑ��@��ŗL�ݒ�ǂݍ��݃R�}���h�𑗐M���܂��B
		///
		/// @param pid         �v���_�N�gID
		/// @param smid        �ΏۃZ���T���W���[��ID
		/// @param target      �Ώۋ@��
		/// @param sub         �T�u����
		///
		__declspec(dllexport) void GetExDevice(unsigned char pid, unsigned char smid, unsigned char target, unsigned short sub);

		///
		/// @brief �␳�l�L�[�o�^�R�}���h�𑗐M���܂��B
		///
		/// @param pid       �v���_�N�gID
		/// @param smid      �ΏۃZ���T���W���[��ID
		/// @param data      �f�[�^
		/// @param data_size �f�[�^�T�C�Y
		///
		__declspec(dllexport) void SetOffset(unsigned char pid, unsigned char smid, unsigned char *data, unsigned char data_size);

		///
		/// @brief �ݒ菉�����R�}���h�𑗐M���܂��B
		///
		/// @param pid  �v���_�N�gID
		/// @param smid �ΏۃZ���T���W���[��ID
		///
		__declspec(dllexport) void ResetConfig(unsigned char pid, unsigned char smid);

		///
		/// @brief �V���A���ԍ��擾�R�}���h�𑗐M���܂��B
		///
		/// @param pid  �v���_�N�gID
		/// @param smid �ΏۃZ���T���W���[��ID
		///
		__declspec(dllexport) void GetSerial(unsigned char pid, unsigned char smid);

		///
		/// @brief �t�@�[���E�F�A�o�[�W�����擾�R�}���h�𑗐M���܂��B
		///
		/// @param pid  �v���_�N�gID
		/// @param smid �ΏۃZ���T���W���[��ID
		///
		__declspec(dllexport) void GetFwVer(unsigned char pid, unsigned char smid);

		///
		/// @brief �n�[�h�E�F�A�o�[�W�����擾�R�}���h�𑗐M���܂��B
		///
		/// @param pid  �v���_�N�gID
		/// @param smid �ΏۃZ���T���W���[��ID
		///
		__declspec(dllexport) void GetHwVer(unsigned char pid, unsigned char smid);

		///
		/// @brief �d��OFF�R�}���h�𑗐M���܂��B
		///
		/// @param pid  �v���_�N�gID
		/// @param smid �ΏۃZ���T���W���[��ID
		///
		__declspec(dllexport) void PwOff(unsigned char pid, unsigned char smid);

		///
		/// @brief �p�P�b�g��M���̃R�[���o�b�N�֐���o�^���܂��B
		///
		/// @param code �����R�[�h
		/// @param func �R�[���o�b�N�֐�
		///
		__declspec(dllexport) void SetCmdCallback(unsigned char code, void (*func)(const char *port_name, unsigned char *packet, int size));

	private:
		/// �R�[���o�b�N�֐��I�u�W�F�N�g
		class CCallback
		{
		public:
			CCallback();
			CCallback(void (*func)(const char *port_name, unsigned char *packet, int size));
			void operator()(const char *port_name, unsigned char *packet, int size);
			void SetFunc(void (*func)(const char *port_name, unsigned char *packet, int size));

		private:
			void (*func)(const char *port_name, unsigned char *packet, int size);
			static void dummy(const char *port_name, unsigned char *packet, int size);
		};

		/// �R�[���o�b�N�֐��e�[�u��
		map<unsigned char, CCallback> cb;

		/// �p�P�b�g�҂��p
		queue<unsigned char> rcv_buffer;	// ��M�ς݃o�b�t�@
		vector<unsigned char> rcv_packet;	// ��M�ς݃p�P�b�g

		/// �p�P�b�g�؂�o��
		__declspec(dllexport) void WaitPacket(unsigned char* buffer, int size);

		/// BCC�v�Z
		unsigned char GetBcc(unsigned char* command, int size);
		bool CheckBcc(unsigned char* command, int size);

		/// �R�}���h�p�P�b�g�̃w�b�_(�R�}���h�ԍ��܂�)���v�Z
		void SetHeader(unsigned char *command, unsigned char size, unsigned char pid, unsigned char smid, unsigned char command_no);

		/// �R�}���h�p�P�b�g�̃t�b�^(BCC�ƃt�b�^)���v�Z
		void SetFooter(unsigned char *command, int size);
	};
}
