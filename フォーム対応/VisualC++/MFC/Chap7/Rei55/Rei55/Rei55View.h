// Rei55View.h : CRei55View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei55View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei55View();
	DECLARE_DYNCREATE(CRei55View)

public:
	enum{ IDD = IDD_REI55_FORM };

// ����
public:
	CRei55Doc* GetDocument() const;

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
	virtual ~CRei55View();
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
	CEdit text1;
};

#ifndef _DEBUG  // Rei55View.cpp �̃f�o�b�O �o�[�W����
inline CRei55Doc* CRei55View::GetDocument() const
   { return reinterpret_cast<CRei55Doc*>(m_pDocument); }
#endif

