// Rei44View.h : CRei44View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei44View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei44View();
	DECLARE_DYNCREATE(CRei44View)

public:
	enum{ IDD = IDD_REI44_FORM };

// ����
public:
	CRei44Doc* GetDocument() const;

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
	virtual ~CRei44View();
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

#ifndef _DEBUG  // Rei44View.cpp �̃f�o�b�O �o�[�W����
inline CRei44Doc* CRei44View::GetDocument() const
   { return reinterpret_cast<CRei44Doc*>(m_pDocument); }
#endif

