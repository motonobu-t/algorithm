// Dr20_1.h : Dr20_1 �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CDr20_1App:
// ���̃N���X�̎����ɂ��ẮADr20_1.cpp ���Q�Ƃ��Ă��������B
//

class CDr20_1App : public CWinApp
{
public:
	CDr20_1App();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr20_1App theApp;