// Rei56View.h : CRei56View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei56View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei56View();
	DECLARE_DYNCREATE(CRei56View)

public:
	enum{ IDD = IDD_REI56_FORM };

// ����
public:
	CRei56Doc* GetDocument() const;

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
	virtual ~CRei56View();
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
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // Rei56View.cpp �̃f�o�b�O �o�[�W����
inline CRei56Doc* CRei56View::GetDocument() const
   { return reinterpret_cast<CRei56Doc*>(m_pDocument); }
#endif

