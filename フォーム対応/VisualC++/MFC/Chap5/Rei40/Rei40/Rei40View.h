// Rei40View.h : CRei40View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei40View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei40View();
	DECLARE_DYNCREATE(CRei40View)

public:
	enum{ IDD = IDD_REI40_FORM };

// ����
public:
	CRei40Doc* GetDocument() const;

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
	virtual ~CRei40View();
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
};

#ifndef _DEBUG  // Rei40View.cpp �̃f�o�b�O �o�[�W����
inline CRei40Doc* CRei40View::GetDocument() const
   { return reinterpret_cast<CRei40Doc*>(m_pDocument); }
#endif

