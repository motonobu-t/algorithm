// Rei31View.h : CRei31View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei31View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei31View();
	DECLARE_DYNCREATE(CRei31View)

public:
	enum{ IDD = IDD_REI31_FORM };

// ����
public:
	CRei31Doc* GetDocument() const;

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
	virtual ~CRei31View();
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
//	afx_msg void OnStnClickedPict();
};

#ifndef _DEBUG  // Rei31View.cpp �̃f�o�b�O �o�[�W����
inline CRei31Doc* CRei31View::GetDocument() const
   { return reinterpret_cast<CRei31Doc*>(m_pDocument); }
#endif

