// Rei33View.h : CRei33View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei33View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei33View();
	DECLARE_DYNCREATE(CRei33View)

public:
	enum{ IDD = IDD_REI33_FORM };

// ����
public:
	CRei33Doc* GetDocument() const;

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
	virtual ~CRei33View();
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

#ifndef _DEBUG  // Rei33View.cpp �̃f�o�b�O �o�[�W����
inline CRei33Doc* CRei33View::GetDocument() const
   { return reinterpret_cast<CRei33Doc*>(m_pDocument); }
#endif

