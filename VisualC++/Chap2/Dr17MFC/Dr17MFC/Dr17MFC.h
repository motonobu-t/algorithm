// Dr17MFC.h : Dr17MFC �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C��
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH �ɑ΂��Ă��̃t�@�C�����C���N���[�h����O�� 'stdafx.h' ���C���N���[�h���Ă�������"
#endif

#include "resource.h"       // ���C�� �V���{��


// CDr17MFCApp:
// ���̃N���X�̎����ɂ��ẮADr17MFC.cpp ���Q�Ƃ��Ă��������B
//

class CDr17MFCApp : public CWinApp
{
public:
	CDr17MFCApp();


// �I�[�o�[���C�h
public:
	virtual BOOL InitInstance();

// ����
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CDr17MFCApp theApp;