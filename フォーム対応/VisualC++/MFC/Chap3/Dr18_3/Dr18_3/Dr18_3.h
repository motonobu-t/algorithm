// Dr18_3.h : Dr18_3 �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CDr18_3App:
// ���̃N���X�̎����ɂ��ẮADr18_3.cpp ���Q�Ƃ��Ă��������B
//

class CDr18_3App : public CWinApp
{
public:
	CDr18_3App();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr18_3App theApp;