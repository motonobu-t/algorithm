// Dr26_5.h : Dr26_5 �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CDr26_5App:
// ���̃N���X�̎����ɂ��ẮADr26_5.cpp ���Q�Ƃ��Ă��������B
//

class CDr26_5App : public CWinApp
{
public:
	CDr26_5App();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr26_5App theApp;