// Rei60View.h : CRei60View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei60View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei60View();
	DECLARE_DYNCREATE(CRei60View)

public:
	enum{ IDD = IDD_REI60_FORM };

// ����
public:
	CRei60Doc* GetDocument() const;

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
	virtual ~CRei60View();
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

#ifndef _DEBUG  // Rei60View.cpp �̃f�o�b�O �o�[�W����
inline CRei60Doc* CRei60View::GetDocument() const
   { return reinterpret_cast<CRei60Doc*>(m_pDocument); }
#endif

