// Rei66ListBox.h : Rei66ListBox �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CRei66ListBoxApp:
// ���̃N���X�̎����ɂ��ẮARei66ListBox.cpp ���Q�Ƃ��Ă��������B
//

class CRei66ListBoxApp : public CWinApp
{
public:
	CRei66ListBoxApp();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CRei66ListBoxApp theApp;