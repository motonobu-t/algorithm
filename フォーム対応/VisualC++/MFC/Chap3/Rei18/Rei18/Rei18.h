// Rei18.h : Rei18 �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CRei18App:
// ���̃N���X�̎����ɂ��ẮARei18.cpp ���Q�Ƃ��Ă��������B
//

class CRei18App : public CWinApp
{
public:
	CRei18App();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRei18App theApp;