// Rei13View.h : CRei13View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei13View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei13View();
	DECLARE_DYNCREATE(CRei13View)

public:
	enum{ IDD = IDD_REI13_FORM };

// ����
public:
	CRei13Doc* GetDocument() const;

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
	virtual ~CRei13View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CStatic pict;
//	afx_msg void OnStnClickedPict();
};

#ifndef _DEBUG  // Rei13View.cpp �̃f�o�b�O �o�[�W����
inline CRei13Doc* CRei13View::GetDocument() const
   { return reinterpret_cast<CRei13Doc*>(m_pDocument); }
#endif

