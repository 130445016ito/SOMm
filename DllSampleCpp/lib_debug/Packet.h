///
/// @file  Packet.h
/// @brief ��M�p�P�b�g��͗p�\���̌Q
///

#pragma once

#include"Table.h"

namespace lp_wsm
{
	///
	/// @brief ��M�p�P�b�g�̊�{�\���̂ł��B
	///
	struct Packet
	{
		unsigned char smid; ///< �Z���T���W���[��ID
		unsigned char pid;  ///< �v���_�N�gID
		unsigned char code; ///< �����R�[�h

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// �����̓R�[���o�b�N�֐��̈��������̂܂ܗ��p���Ă��������B
		///
		/// @param buffer ��M�p�P�b�g�̃o�b�t�@
		/// @param size   �o�b�t�@�̃T�C�Y
		///
		Packet(unsigned char *buffer, int size);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		Packet();
	};

	///
	/// @brief ACK�p�P�b�g�\���̂ł��B
	///
	struct Ack : Packet
	{
		unsigned char status; ///< ACK�X�e�[�^�X

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// �����̓R�[���o�b�N�֐��̈��������̂܂ܗ��p���Ă��������B
		///
		/// @param buffer ��M�p�P�b�g�̃o�b�t�@
		/// @param size   �o�b�t�@�̃T�C�Y
		///
		__declspec(dllexport) Ack(unsigned char *buffer, int size);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) Ack();
	};

	///
	/// @brief �X�e�[�^�X���擾�̃f�[�^�p�P�b�g�\���̂ł��B
	///
	struct DatGetStatus : Packet
	{
		unsigned char hh;                ///< �v������(h)
		unsigned char mm;                ///< �v������(m)
		unsigned char ss;                ///< �v������(s)
		unsigned short freq;             ///< �T���v�����O���g��
		unsigned char ch;                ///< �����`�����l��
		unsigned char serial_no[5];      ///< �V���A���ԍ�
		unsigned char hw_ver[5];         ///< �n�[�h�E�F�A�o�[�W����
		unsigned char uniq_config[15];   ///< �Z���T���W���[���ŗL�ݒ�
		unsigned char default_calib[16]; ///< �f�t�H���g�L�����u���[�V�����L�[
		unsigned char user_calib[16];    ///< ���[�U�[�L�����u���[�V�����L�[
		unsigned int  mem_addr;          ///< �������A�h���X
		unsigned char num_files;         ///< ���������t�@�C����
		unsigned char battery;           ///< �o�b�e���l
		unsigned char comm_path;         ///< �ʐM�o�H(RF[0x00] or UART[0x01])
		unsigned char cpu_temp;          ///< CPU���x

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// �����̓R�[���o�b�N�֐��̈��������̂܂ܗ��p���Ă��������B
		///
		/// @param buffer ��M�p�P�b�g�̃o�b�t�@
		/// @param size   �o�b�t�@�̃T�C�Y
		///
		__declspec(dllexport) DatGetStatus(unsigned char *buffer, int size);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) DatGetStatus();
	};

	///
	/// @brief �v���J�n�̃f�[�^�p�P�b�g�\���̂ł��B
	///
	struct DatStartMeasure : Packet
	{
		unsigned char  battery;     ///< �o�b�e���d��
		unsigned short seq;         ///< �V�[�P���X�ԍ�
		unsigned char  data[5][18]; ///< �v���f�[�^

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// �����̓R�[���o�b�N�֐��̈��������̂܂ܗ��p���Ă��������B
		///
		/// @param buffer ��M�p�P�b�g�̃o�b�t�@
		/// @param size   �o�b�t�@�̃T�C�Y
		///
		__declspec(dllexport) DatStartMeasure(unsigned char *buffer, int size);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) DatStartMeasure();
	};

	///
	/// @brief 9�����C�����X���[�V�����Z���T�i���^�A�h���AGPS+9���j�̌v���f�[�^�\���̂ł��B
	///
	struct WmsData
	{
		short          mag[3]; ///< �n���C
		unsigned short acc[3]; ///< �����x
		unsigned short ang[3]; ///< �p���x

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// @param data �v���f�[�^�p�P�b�g�̌v���f�[�^���i1�T���v�����O�j
		/// @param pid  �v���_�N�gID<br>
		///             �i5G/300dps�d�l�̏ꍇ�͎w�肵�Ă��������j
		///
		__declspec(dllexport) WmsData(unsigned char data[18], unsigned char pid = 0x00);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) WmsData();
	};

	///
	/// @brief ���C�����XEMG���K�[�̌v���f�[�^�\���̂ł��B
	///
	struct EmgData
	{
		short acc[3];  ///< �����x
		short emg[2];  ///< EMG
		short iemg[2]; ///< IEMG

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// @param data �v���f�[�^�p�P�b�g�̌v���f�[�^���i1�T���v�����O�j
		///
		__declspec(dllexport) EmgData(unsigned char data[18]);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) EmgData();
	};

	///
	/// @brief ���C�����XECG���K�[�̌v���f�[�^�\���̂ł��B
	///
	struct EcgData
	{
		int ecg; ///< �S�d�i���3�o�C�g�j

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// @param data �v���f�[�^�p�P�b�g�̌v���f�[�^���i1�T���v�����O�j
		///
		__declspec(dllexport) EcgData(unsigned char data[18]);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) EcgData();
	};

	///
	/// @brief ���C�����XGSR���K�[�̌v���f�[�^�\���̂ł��B
	///
	struct GsrData
	{
		int eda_v; ///< �畆�d�ʁi�d�ʖ@�v���A���3�o�C�g�j
		int eda_c; ///< �畆�d�ʁi�d���@�v���A���3�o�C�g�j

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// @param data �v���f�[�^�p�P�b�g�̌v���f�[�^���i1�T���v�����O�j
		///
		__declspec(dllexport) GsrData(unsigned char data[18]);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) GsrData();
	};

	///
	/// @brief ���C�����X6ch���K�[�̌v���f�[�^�\���̂ł��B
	///
	struct W6chData
	{
		short          acc[3];          ///< �����x
		unsigned short analog_input[6]; ///< �A�i���O����1�`6

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// @param data �v���f�[�^�p�P�b�g�̌v���f�[�^���i1�T���v�����O�j
		///
		__declspec(dllexport) W6chData(unsigned char data[18]);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) W6chData();
	};

	///
	/// @brief ���C�����X�ؓd�Z���T�̌v���f�[�^�\���̂ł��B
	///
	struct MyoData
	{
		short          eda;    ///< �畆�d�ʁi�d�ʖ@�v���j
		unsigned short acc[3]; ///< �����x

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// @param data �v���f�[�^�p�P�b�g�̌v���f�[�^���i1�T���v�����O�j
		///
		__declspec(dllexport) MyoData(unsigned char data[18]);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) MyoData();
	};

	///
	/// @brief GPS�Z���T�̌v���f�[�^�\���̂ł��B
	///
	struct GpsData
	{
		bool          type_gps;		///< ��M�p�P�b�g��GPS�f�[�^���ǂ���
		unsigned char gps_length;   ///< GPS�Z���e���X��
		char          nmea[90];     ///< NMEA�`��������
		char          name[8];		///< "$GPGGA"
		double        m1;           ///< UTC����
		double        m2;           ///< �ܓx
		char          c1;           ///< �ܓx����(N or S)
		double        m3;           ///< �o�x
		char          c2;           ///< �o�x����(E or W)
		int           d1;           ///< 0=������,1=���ʒ�,2=RTCM�܂���SBASdifferential���ʒ�
		int           d2;           ///< �⑫�q����
		double        f1;           ///< �������ʌ덷
		double        f2;           ///< �C�����x
		char          M1;           ///< �C�����x�̒P��
		double        f3;           ///< �W�I�C�h���x
		char          M2;           ///< �W�I�C�h���x�̒P��
		int           d3;           ///< DGPS�␳�f�[�^�̎擾��̌o�ߎ���
		int           d4;           ///< DGPS��n��ID
		unsigned char cc;           ///< �`�F�b�N�T��

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// @param data �v���f�[�^�p�P�b�g�̌v���f�[�^���i1�T���v�����O�j
		///
		__declspec(dllexport) GpsData(unsigned char (*data)[18]);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) GpsData();

		///
		/// @brief ��M�p�P�b�g��GPS�f�[�^���ǂ������擾���܂��B
		///
		/// @param  data ��M�p�P�b�g�̃f�[�^��<br>
		/// @return ��M�p�P�b�g��GPS�f�[�^�ł����true
		///
		__declspec(dllexport) static bool isGpsData(unsigned char (*data)[18]);
	};

	///
	/// @brief �����ԍ��Ăяo���̃f�[�^�p�P�b�g�\���̂ł��B
	///
	struct DatReadSync : Packet
	{
		unsigned char file_no;       ///< �t�@�C���ԍ�
		unsigned char packet_no;     ///< �p�P�b�g�V�[�P���X
		unsigned char packet_num;    ///< �p�P�b�g�V�[�P���X�ŏI(�ő�7)
		unsigned char seq_num;       ///< �p�P�b�g���̗L���V�[�P���X(�ő�16)
		unsigned char sync_no[16];   ///< �����ԍ�
		unsigned int  sample_no[16]; ///< �����ԍ��̃T���v�����O��

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// �����̓R�[���o�b�N�֐��̈��������̂܂ܗ��p���Ă��������B
		///
		/// @param buffer ��M�p�P�b�g�̃o�b�t�@
		/// @param size   �o�b�t�@�̃T�C�Y
		///
		__declspec(dllexport) DatReadSync(unsigned char *buffer, int size);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) DatReadSync();
	};

	///
	/// @brief �t�@�C�����擾�̃f�[�^�p�P�b�g�\���̂ł��B
	///
	struct DatGetFileInfo : Packet
	{
		unsigned char  file_no;         ///< �t�@�C���ԍ�
		unsigned char  file_num;        ///< �S�t�@�C����
		unsigned short freq;            ///< �v�����T���v�����O���g��
		unsigned char  YY;              ///< �v���J�n����(Y)
		unsigned char  MM;              ///< �v���J�n����(M)
		unsigned char  DD;              ///< �v���J�n����(D)
		unsigned char  hh;              ///< �v���J�n����(h)
		unsigned char  mm;              ///< �v���J�n����(m)
		unsigned int   sample_num;      ///< �T���v�����O��
		unsigned char  calib[16];       ///< �v�����L�����u���[�V�����L�[
		unsigned char  uniq_config[15]; ///< �v�����Z���T���W���[���ŗL�ݒ�

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// �����̓R�[���o�b�N�֐��̈��������̂܂ܗ��p���Ă��������B
		///
		/// @param buffer ��M�p�P�b�g�̃o�b�t�@
		/// @param size   �o�b�t�@�̃T�C�Y
		///
		__declspec(dllexport) DatGetFileInfo(unsigned char *buffer, int size);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) DatGetFileInfo();
	};

	///
	/// @brief �t�@�C�����擾2�̃f�[�^�p�P�b�g�\���̂ł��B
	///
	struct DatGetFileInfo2 : Packet
	{
		unsigned char  file_no;         ///< �t�@�C���ԍ�
		unsigned char  file_num;        ///< �S�t�@�C����
		char           file_name[14];   ///< �t�@�C����
		unsigned short freq;            ///< �v���T���v�����O���g��
		unsigned char  YY;              ///< �v���J�n����(Y)
		unsigned char  MM;              ///< �v���J�n����(M)
		unsigned char  DD;              ///< �v���J�n����(D)
		unsigned char  hh;              ///< �v���J�n����(h)
		unsigned char  mm;              ///< �v���J�n����(m)
		unsigned int   sample_num;      ///< �T���v�����O��
		unsigned char  calib[16];       ///< �v�����L�����u���[�V�����L�[
		unsigned char  uniq_config[15]; ///< �v�����Z���T���W���[���ŗL�ݒ�

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// �����̓R�[���o�b�N�֐��̈��������̂܂ܗ��p���Ă��������B
		///
		/// @param buffer ��M�p�P�b�g�̃o�b�t�@
		/// @param size   �o�b�t�@�̃T�C�Y
		///
		__declspec(dllexport) DatGetFileInfo2(unsigned char *buffer, int size);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) DatGetFileInfo2();
	};

	///
	/// @brief �t�@�C���f�[�^�擾�̃f�[�^�p�P�b�g�\���̂ł��B
	///
	struct DatReadFile : Packet
	{
		unsigned int  packet_no;   ///< �p�P�b�g�ԍ�
		unsigned char size;        ///< �t�@�C���f�[�^�̊i�[��(1�`4)
		unsigned char data[4][18]; ///< �t�@�C���f�[�^

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// �����̓R�[���o�b�N�֐��̈��������̂܂ܗ��p���Ă��������B
		///
		/// @param buffer ��M�p�P�b�g�̃o�b�t�@
		/// @param size   �o�b�t�@�̃T�C�Y
		///
		__declspec(dllexport) DatReadFile(unsigned char *buffer, int size);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) DatReadFile();
	};

	///
	/// @brief �t�@�C���f�[�^�擾2�̃f�[�^�p�P�b�g�\���̂ł��B
	///
	struct DatReadFile2 : Packet
	{
		unsigned int packet_no;  ///< �p�P�b�g�ԍ�
		unsigned int packet_num; ///< �p�P�b�g����
		unsigned char size;      ///< �L���f�[�^
		unsigned char data[86];  ///< �f�[�^

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// �����̓R�[���o�b�N�֐��̈��������̂܂ܗ��p���Ă��������B
		///
		/// @param buffer ��M�p�P�b�g�̃o�b�t�@
		/// @param size   �o�b�t�@�̃T�C�Y
		///
		__declspec(dllexport) DatReadFile2(unsigned char *buffer, int size);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) DatReadFile2();
	};

	///
	/// @brief �t�@�C���R�����g�擾�̃f�[�^�p�P�b�g�\���̂ł��B
	///
	struct DatReadComment : Packet
	{
		char          comment[65]; ///< �R�����g�f�[�^
		unsigned char file_no;     ///< �t�@�C���ԍ�

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// �����̓R�[���o�b�N�֐��̈��������̂܂ܗ��p���Ă��������B
		///
		/// @param buffer ��M�p�P�b�g�̃o�b�t�@
		/// @param size   �o�b�t�@�̃T�C�Y
		///
		__declspec(dllexport) DatReadComment(unsigned char *buffer, int size);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) DatReadComment();
	};

	///
	/// @brief �t�@�C���R�����g�������݂̃f�[�^�p�P�b�g�\���̂ł��B
	///
	struct DatWriteComment : Packet
	{
		char          comment[65]; ///< ���������������݃f�[�^
		unsigned char file_no;     ///< �t�@�C���ԍ�

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// �����̓R�[���o�b�N�֐��̈��������̂܂ܗ��p���Ă��������B
		///
		/// @param buffer ��M�p�P�b�g�̃o�b�t�@
		/// @param size   �o�b�t�@�̃T�C�Y
		///
		__declspec(dllexport) DatWriteComment(unsigned char *buffer, int size);
		///
		/// �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) DatWriteComment();
	};

	///
	/// @brief �O���ڑ��@��ŗL�ݒ�ǂݍ��݂̃f�[�^�p�P�b�g�\���̂ł��B
	///
	struct DatGetExDevice : Packet
	{
		unsigned char target;      ///< �Ώۋ@��
		unsigned short sub;        ///< �T�u����
		unsigned char config_size; ///< �L���o�C�g��
		unsigned char config[64];  ///< �ŗL�ݒ�

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// �����̓R�[���o�b�N�֐��̈��������̂܂ܗ��p���Ă��������B
		///
		/// @param buffer ��M�p�P�b�g�̃o�b�t�@
		/// @param size   �o�b�t�@�̃T�C�Y
		///
		__declspec(dllexport) DatGetExDevice(unsigned char *buffer, int size);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) DatGetExDevice();
	};

	///
	/// @brief �V���A���ԍ��擾�̃f�[�^�p�P�b�g�\���̂ł��B
	///
	struct DatGetSerial : Packet
	{
		unsigned char serial_no[5]; ///< �V���A���ԍ�

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// �����̓R�[���o�b�N�֐��̈��������̂܂ܗ��p���Ă��������B
		///
		/// @param buffer ��M�p�P�b�g�̃o�b�t�@
		/// @param size   �o�b�t�@�̃T�C�Y
		///
		__declspec(dllexport) DatGetSerial(unsigned char *buffer, int size);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) DatGetSerial();
	};

	///
	/// @brief �t�@�[���E�F�A�o�[�W�����擾�̃f�[�^�p�P�b�g�\���̂ł��B
	///
	struct DatGetFwVer : Packet
	{
		unsigned char fw_ver[5]; ///< �t�@�[���E�F�A�ԍ�

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// �����̓R�[���o�b�N�֐��̈��������̂܂ܗ��p���Ă��������B
		///
		/// @param buffer ��M�p�P�b�g�̃o�b�t�@
		/// @param size   �o�b�t�@�̃T�C�Y
		///
		__declspec(dllexport) DatGetFwVer(unsigned char *buffer, int size);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) DatGetFwVer();
	};

	///
	/// @brief �n�[�h�E�F�A�o�[�W�����擾�̃f�[�^�p�P�b�g�\���̂ł��B
	///
	struct DatGetHwVer : Packet
	{
		unsigned char hw_ver[5]; ///< �n�[�h�E�F�A�o�[�W�����ԍ�

		///
		///	@brief �����I�Ƀ����o�����߂�R���X�g���N�^�ł��B
		///
		/// �����̓R�[���o�b�N�֐��̈��������̂܂ܗ��p���Ă��������B
		///
		/// @param buffer ��M�p�P�b�g�̃o�b�t�@
		/// @param size   �o�b�t�@�̃T�C�Y
		///
		__declspec(dllexport) DatGetHwVer(unsigned char *buffer, int size);
		///
		/// @brief �f�t�H���g�R���X�g���N�^�ł��B
		///
		__declspec(dllexport) DatGetHwVer();
	};
}
