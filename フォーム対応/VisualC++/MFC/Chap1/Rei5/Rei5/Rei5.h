// Rei5.h : Rei5 �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CRei5App:
// ���̃N���X�̎����ɂ��ẮARei5.cpp ���Q�Ƃ��Ă��������B
//

class CRei5App : public CWinApp
{
public:
	CRei5App();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRei5App theApp;