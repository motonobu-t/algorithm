// Dr51_1.h : Dr51_1 �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CDr51_1App:
// ���̃N���X�̎����ɂ��ẮADr51_1.cpp ���Q�Ƃ��Ă��������B
//

class CDr51_1App : public CWinApp
{
public:
	CDr51_1App();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr51_1App theApp;