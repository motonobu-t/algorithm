// Rei41View.h : CRei41View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei41View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei41View();
	DECLARE_DYNCREATE(CRei41View)

public:
	enum{ IDD = IDD_REI41_FORM };

// ����
public:
	CRei41Doc* GetDocument() const;

// ����
public:

// �I�[�o�[���C�h
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	virtual void OnInitialUpdate(); // �\�z��ɏ��߂ČĂяo����܂��B

// ����
public:
	virtual ~CRei41View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CEdit text1;
	CEdit text2;
	CEdit text3;
	CStatic pict;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // Rei41View.cpp �̃f�o�b�O �o�[�W����
inline CRei41Doc* CRei41View::GetDocument() const
   { return reinterpret_cast<CRei41Doc*>(m_pDocument); }
#endif

