// Rei35View.h : CRei35View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei35View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei35View();
	DECLARE_DYNCREATE(CRei35View)

public:
	enum{ IDD = IDD_REI35_FORM };

// ����
public:
	CRei35Doc* GetDocument() const;

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
	virtual ~CRei35View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	CStatic pict;
	CEdit text1;
	CEdit text2;
	CEdit text3;
};

#ifndef _DEBUG  // Rei35View.cpp �̃f�o�b�O �o�[�W����
inline CRei35Doc* CRei35View::GetDocument() const
   { return reinterpret_cast<CRei35Doc*>(m_pDocument); }
#endif

