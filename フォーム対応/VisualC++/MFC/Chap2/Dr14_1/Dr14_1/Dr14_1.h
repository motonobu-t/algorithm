// Dr14_1.h : Dr14_1 �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CDr14_1App:
// ���̃N���X�̎����ɂ��ẮADr14_1.cpp ���Q�Ƃ��Ă��������B
//

class CDr14_1App : public CWinApp
{
public:
	CDr14_1App();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr14_1App theApp;