// Rei34View.h : CRei34View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei34View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei34View();
	DECLARE_DYNCREATE(CRei34View)

public:
	enum{ IDD = IDD_REI34_FORM };

// ����
public:
	CRei34Doc* GetDocument() const;

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
	virtual ~CRei34View();
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
	CEdit text2;
};

#ifndef _DEBUG  // Rei34View.cpp �̃f�o�b�O �o�[�W����
inline CRei34Doc* CRei34View::GetDocument() const
   { return reinterpret_cast<CRei34Doc*>(m_pDocument); }
#endif

