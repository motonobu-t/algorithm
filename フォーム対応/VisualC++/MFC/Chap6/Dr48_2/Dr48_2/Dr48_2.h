// Dr48_2.h : Dr48_2 �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CDr48_2App:
// ���̃N���X�̎����ɂ��ẮADr48_2.cpp ���Q�Ƃ��Ă��������B
//

class CDr48_2App : public CWinApp
{
public:
	CDr48_2App();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr48_2App theApp;