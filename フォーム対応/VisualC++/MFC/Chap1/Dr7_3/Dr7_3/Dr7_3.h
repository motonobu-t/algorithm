// Dr7_3.h : Dr7_3 �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CDr7_3App:
// ���̃N���X�̎����ɂ��ẮADr7_3.cpp ���Q�Ƃ��Ă��������B
//

class CDr7_3App : public CWinApp
{
public:
	CDr7_3App();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr7_3App theApp;