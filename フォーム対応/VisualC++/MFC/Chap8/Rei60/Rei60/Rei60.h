// Rei60.h : Rei60 �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CRei60App:
// ���̃N���X�̎����ɂ��ẮARei60.cpp ���Q�Ƃ��Ă��������B
//

class CRei60App : public CWinApp
{
public:
	CRei60App();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRei60App theApp;