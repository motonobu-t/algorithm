// Dr14_2ListBox.h : Dr14_2ListBox �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CDr14_2ListBoxApp:
// ���̃N���X�̎����ɂ��ẮADr14_2ListBox.cpp ���Q�Ƃ��Ă��������B
//

class CDr14_2ListBoxApp : public CWinApp
{
public:
	CDr14_2ListBoxApp();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr14_2ListBoxApp theApp;