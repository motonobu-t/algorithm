// Dr30_3.h : Dr30_3 �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CDr30_3App:
// ���̃N���X�̎����ɂ��ẮADr30_3.cpp ���Q�Ƃ��Ă��������B
//

class CDr30_3App : public CWinApp
{
public:
	CDr30_3App();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr30_3App theApp;