// Dr26_4.h : Dr26_4 �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CDr26_4App:
// ���̃N���X�̎����ɂ��ẮADr26_4.cpp ���Q�Ƃ��Ă��������B
//

class CDr26_4App : public CWinApp
{
public:
	CDr26_4App();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr26_4App theApp;