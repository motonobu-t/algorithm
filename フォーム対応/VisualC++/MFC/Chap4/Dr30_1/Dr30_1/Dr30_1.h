// Dr30_1.h : Dr30_1 �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CDr30_1App:
// ���̃N���X�̎����ɂ��ẮADr30_1.cpp ���Q�Ƃ��Ă��������B
//

class CDr30_1App : public CWinApp
{
public:
	CDr30_1App();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr30_1App theApp;