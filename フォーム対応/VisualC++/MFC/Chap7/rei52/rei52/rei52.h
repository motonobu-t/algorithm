// rei52.h : rei52 �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// Crei52App:
// ���̃N���X�̎����ɂ��ẮArei52.cpp ���Q�Ƃ��Ă��������B
//

class Crei52App : public CWinApp
{
public:
	Crei52App();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Crei52App theApp;