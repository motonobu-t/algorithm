// Rei46View.h : CRei46View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei46View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei46View();
	DECLARE_DYNCREATE(CRei46View)

public:
	enum{ IDD = IDD_REI46_FORM };

// ����
public:
	CRei46Doc* GetDocument() const;

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
	virtual ~CRei46View();
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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // Rei46View.cpp �̃f�o�b�O �o�[�W����
inline CRei46Doc* CRei46View::GetDocument() const
   { return reinterpret_cast<CRei46Doc*>(m_pDocument); }
#endif

