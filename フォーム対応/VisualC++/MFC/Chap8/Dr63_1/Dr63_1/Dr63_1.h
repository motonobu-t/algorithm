// Dr63_1.h : Dr63_1 �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CDr63_1App:
// ���̃N���X�̎����ɂ��ẮADr63_1.cpp ���Q�Ƃ��Ă��������B
//

class CDr63_1App : public CWinApp
{
public:
	CDr63_1App();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr63_1App theApp;