// Rei29View.h : CRei29View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei29View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei29View();
	DECLARE_DYNCREATE(CRei29View)

public:
	enum{ IDD = IDD_REI29_FORM };

// ����
public:
	CRei29Doc* GetDocument() const;

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
	virtual ~CRei29View();
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
};

#ifndef _DEBUG  // Rei29View.cpp �̃f�o�b�O �o�[�W����
inline CRei29Doc* CRei29View::GetDocument() const
   { return reinterpret_cast<CRei29Doc*>(m_pDocument); }
#endif

