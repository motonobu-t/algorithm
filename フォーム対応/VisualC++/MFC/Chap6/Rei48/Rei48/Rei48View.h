// Rei48View.h : CRei48View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei48View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei48View();
	DECLARE_DYNCREATE(CRei48View)

public:
	enum{ IDD = IDD_REI48_FORM };

// ����
public:
	CRei48Doc* GetDocument() const;

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
	virtual ~CRei48View();
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

#ifndef _DEBUG  // Rei48View.cpp �̃f�o�b�O �o�[�W����
inline CRei48Doc* CRei48View::GetDocument() const
   { return reinterpret_cast<CRei48Doc*>(m_pDocument); }
#endif

