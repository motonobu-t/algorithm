// Rei57View.h : CRei57View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei57View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei57View();
	DECLARE_DYNCREATE(CRei57View)

public:
	enum{ IDD = IDD_REI57_FORM };

// ����
public:
	CRei57Doc* GetDocument() const;

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
	virtual ~CRei57View();
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

#ifndef _DEBUG  // Rei57View.cpp �̃f�o�b�O �o�[�W����
inline CRei57Doc* CRei57View::GetDocument() const
   { return reinterpret_cast<CRei57Doc*>(m_pDocument); }
#endif

