// Dr66ListBox.h : Dr66ListBox �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CDr66ListBoxApp:
// ���̃N���X�̎����ɂ��ẮADr66ListBox.cpp ���Q�Ƃ��Ă��������B
//

class CDr66ListBoxApp : public CWinApp
{
public:
	CDr66ListBoxApp();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr66ListBoxApp theApp;