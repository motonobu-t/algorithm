// Rei36View.h : CRei36View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei36View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei36View();
	DECLARE_DYNCREATE(CRei36View)

public:
	enum{ IDD = IDD_REI36_FORM };

// ����
public:
	CRei36Doc* GetDocument() const;

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
	virtual ~CRei36View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CStatic pict;
	CEdit text1;
	CEdit text2;
	CEdit text3;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};

#ifndef _DEBUG  // Rei36View.cpp �̃f�o�b�O �o�[�W����
inline CRei36Doc* CRei36View::GetDocument() const
   { return reinterpret_cast<CRei36Doc*>(m_pDocument); }
#endif

