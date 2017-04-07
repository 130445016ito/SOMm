///
/// @file  Table.h
/// @brief �萔�l�Q
///

#pragma once

namespace lp_wsm
{
	///
	/// @brief �v���_�N�gID�̒萔�l�ł��B
	///
	enum EProductId : unsigned char
	{
		PID_WMS_50_1500  = 0x01, ///< 9���C�����X���[�V�����Z���T(50G/1500dps)
		PID_EMG          = 0x02, ///< ���C�����XEMG���K�[
		PID_WMS_5_300    = 0x03, ///< 9���C�����X���[�V�����Z���T(5G/300dps)
		//rsv             = 0x04,
		PID_WMS_HS       = 0x05, ///< 9���C�����X���[�V�����Z���T(HighSpeed�d�l)
		//rsv             = 0x06,
		//rsv             = 0x07,
		//rsv             = 0x08,
		PID_WMS2_50_1500 = 0x09, ///< 9�����C�����X���[�V�����Z���T2(50G/1500dps)
		PID_WMS2_5_30    = 0x0A, ///< 9�����C�����X���[�V�����Z���T2(5G/30dps)
		PID_WMS2_5_1500  = 0x0B, ///< 9�����C�����X���[�V�����Z���T2(5G/1500dps)
		PID_WMS2_16_1500 = 0x0C, ///< 9�����C�����X���[�V�����Z���T2(16G/1500dps)
		PID_SWMS_50_1500 = 0x0D, ///< ���^9�����C�����X���[�V�����Z���T(50G/1500dps)
		PID_SWMS_5_300   = 0x0E, ///< ���^9�����C�����X���[�V�����Z���T(5G/300dps)
		PID_SWMS_5_1500  = 0x0F, ///< ���^9�����C�����X���[�V�����Z���T(5G/1500dps)
		PID_SWMS_16_1500 = 0x10, ///< ���^9�����C�����X���[�V�����Z���T(16G/1500dps)
		PID_SWMS_HS      = 0x11, ///< ���^9�����C�����X���[�V�����Z���T(HighSpeed�d�l)
		PID_ECG          = 0x12, ///< ���C�����XECG���K�[
		PID_GSR          = 0x13, ///< ���C�����XGSR���K�[
		PID_DL           = 0x14, ///< �����^6���f�[�^���K�[
		PID_EEG          = 0x15, ///< ���C�����XEEG���K�[
		PID_WIFI_CVT     = 0x16, ///< WiFi�R���o�[�^
		//rsv             = 0x17,
		//rsv             = 0x18,
		//rsv             = 0x19,
		PID_MYO_DRY      = 0x1A, ///< ���C�����X�ؓd�Z���T(����)
		PID_MYO_WMS_DRY  = 0x1B, ///< ���C�����X�ؓd�Z���T(����, �����x)
		PID_MYO_WET      = 0x1C, ///< ���C�����X�ؓd�Z���T(����)
		PID_MYO_WMS_WET  = 0x1D, ///< ���C�����X�ؓd�Z���T(����, �����x)
		PID_GPS          = 0x1E, ///< GPS+9�����C�����X���[�V�����Z���T
		PID_WP_16_1500   = 0x1F, ///< �h���^9�����C�����X���[�V�����Z���T(16g/1500dps)
		PID_WP_5_1500    = 0x20, ///< �h���^9�����C�����X���[�V�����Z���T(5G/1500dps)
		PID_W6CH         = 0xFA, ///< ���C�����X6ch���K�[
		PID_ALL          = 0xFF, ///< �S�@��ꊇ����
	};

	///
	/// @brief �R�}���h�ԍ��̒萔�l�ł��B
	///
	enum ECommandNo : unsigned char
	{
		CMD_GET_STATUS         = 0x05, ///< �X�e�[�^�X���擾
		CMD_PREP_MEASURE       = 0x1F, ///< �v������
		CMD_START_MEASURE      = 0x02, ///< �v���J�n
		CMD_STOP_MEASURE       = 0x04, ///< �v����~
		CMD_SYNC               = 0x20, ///< ����
		CMD_READ_SYNC          = 0x48, ///< �����ԍ��ǂݏo��
		CMD_GET_FILE_INFO      = 0x07, ///< �t�@�C�����擾
		CMD_GET_LAST_FILE_INFO = 0x44, ///< �ŐV�t�@�C�����擾
		CMD_GET_FILE_INFO_2    = 0x21, ///< �t�@�C�����擾2
		CMD_READ_FILE          = 0x09, ///< �t�@�C���f�[�^�擾
		CMD_READ_FILE_EX       = 0x25, ///< �t�@�C���f�[�^�擾�g��
		CMD_READ_LAST_FILE     = 0x46, ///< �ŐV�t�@�C���f�[�^�擾
		CMD_READ_FILE_2        = 0x23, ///< �t�@�C���f�[�^�擾2
		CMD_READ_COMMENT       = 0x1D, ///< �t�@�C���R�����g�擾
		CMD_WRITE_COMMENT      = 0x1C, ///< �t�@�C���R�����g��������
		CMD_ERASE_MEMORY       = 0x12, ///< ����������
		CMD_SET_ID             = 0x01, ///< ID�ݒ�
		CMD_SET_CH             = 0x0E, ///< �����`�����l���ݒ�
		CMD_SET_FREQ           = 0x0B, ///< �T���v�����O���g���ݒ�
		CMD_SET_TIME           = 0x0C, ///< �v�����Ԑݒ�
		CMD_SET_MAG_GAIN       = 0x0D, ///< �n���C�Q�C���ݒ�
		CMD_SET_UNIQ_CONFIG    = 0x27, ///< �Z���T��ŗL�ݒ�
		CMD_SET_EX_DEVICE      = 0x30, ///< �O���ڑ��@��ŗL�ݒ菑������
		CMD_GET_EX_DEVICE      = 0x31, ///< �O���ڑ��@��ŗL�ݒ�ǂݍ���
		CMD_SET_OFFSET         = 0x1A, ///< �␳�l�L�[�o�^
		CMD_RESET_CONFIG       = 0x11, ///< �ݒ菉����
		CMD_GET_SERIAL         = 0x14, ///< �V���A���ԍ��擾
		CMD_GET_FW_VER         = 0x13, ///< �t�@�[���E�F�A�o�[�W�����擾
		CMD_GET_HW_VER         = 0x16, ///< �n�[�h�E�F�A�o�[�W�����擾
		CMD_PW_OFF             = 0x28, ///< �d��OFF
	};

	///
	/// @brief �����R�[�h��\���萔�l�ł��B
	///
	enum EReplyCode : unsigned char
	{
		ACK_GET_STATUS      = 0x85, ///< ACK�p�P�b�g�F�X�e�[�^�X���擾
		ACK_PREP_MEASURE    = 0x9F, ///< ACK�p�P�b�g�F�v������
		ACK_START_MEASURE   = 0x82, ///< ACK�p�P�b�g�F�v���J�n
		ACK_STOP_MEASURE    = 0x84, ///< ACK�p�P�b�g�F�v����~
		ACK_READ_SYNC       = 0xC8, ///< ACK�p�P�b�g�F����
		ACK_GET_FILE_INFO   = 0x87, ///< ACK�p�P�b�g�F�t�@�C�����擾
		ACK_GET_FILE_INFO_2 = 0xA1, ///< ACK�p�P�b�g�F�t�@�C�����擾2
		ACK_READ_FILE       = 0x89, ///< ACK�p�P�b�g�F�t�@�C���f�[�^�擾
		ACK_READ_FILE_2     = 0xA3, ///< ACK�p�P�b�g�F�t�@�C���f�[�^�擾2
		ACK_ERASE_MEMORY    = 0x92, ///< ACK�p�P�b�g�F����������
		ACK_SET_ID          = 0x81, ///< ACK�p�P�b�g�FID�ݒ�
		ACK_SET_CH          = 0x8E, ///< ACK�p�P�b�g�F�����`�����l���ݒ�
		ACK_SET_FREQ        = 0x8B, ///< ACK�p�P�b�g�F�T���v�����O���g���ݒ�
		ACK_SET_TIME        = 0x8C, ///< ACK�p�P�b�g�F�v�����Ԑݒ�
		ACK_SET_UNIQ_CONFIG = 0x8D, ///< ACK�p�P�b�g�F�Z���T��ŗL�ݒ�
		ACK_SET_EX_DEVICE   = 0xB0, ///< ACK�p�P�b�g�F�O���ڑ��@��ŗL�ݒ菑������
		ACK_GET_EX_DEVICE   = 0xB1, ///< ACK�p�P�b�g�F�O���ڑ��@��ŗL�ݒ�ǂݍ���
		ACK_SET_OFFSET      = 0x9A, ///< ACK�p�P�b�g�F�␳�l�L�[�o�^
		ACK_RESET_CONFIG    = 0x91, ///< ACK�p�P�b�g�F�ݒ菉����
		ACK_PW_OFF          = 0xA8, ///< ACK�p�P�b�g�F�d��OFF

		DAT_GET_STATUS      = 0x86, ///< �f�[�^�p�P�b�g�F�X�e�[�^�X���擾
		DAT_START_MEASURE   = 0x83, ///< �f�[�^�p�P�b�g�F�v���J�n
		DAT_READ_SYNC       = 0xC9, ///< �f�[�^�p�P�b�g�F����
		DAT_GET_FILE_INFO   = 0x88, ///< �f�[�^�p�P�b�g�F�t�@�C�����擾
		DAT_GET_FILE_INFO_2 = 0xA2, ///< �f�[�^�p�P�b�g�F�t�@�C�����擾2
		DAT_READ_FILE       = 0x8A, ///< �f�[�^�p�P�b�g�F�t�@�C���f�[�^�擾
		DAT_READ_FILE_2     = 0xA4, ///< �f�[�^�p�P�b�g�F�t�@�C���f�[�^�擾2
		DAT_READ_COMMENT    = 0x9D, ///< �f�[�^�p�P�b�g�F�t�@�C���R�����g�擾
		DAT_WRITE_COMMENT   = 0x9C, ///< �f�[�^�p�P�b�g�F�t�@�C���R�����g��������
		DAT_GET_SERIAL      = 0x94, ///< �f�[�^�p�P�b�g�F�V���A���ԍ��擾
		DAT_GET_FW_VER      = 0x93, ///< �f�[�^�p�P�b�g�F�t�@�[���E�F�A�o�[�W�����擾
		DAT_GET_HW_VER      = 0x96, ///< �f�[�^�p�P�b�g�F�n�[�h�E�F�A�o�[�W�����擾
	};
}
