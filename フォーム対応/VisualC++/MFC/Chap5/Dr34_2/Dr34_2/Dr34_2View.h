// Dr34_2View.h : CDr34_2View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr34_2View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr34_2View();
	DECLARE_DYNCREATE(CDr34_2View)

public:
	enum{ IDD = IDD_DR34_2_FORM };

// ����
public:
	CDr34_2Doc* GetDocument() const;

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
	virtual ~CDr34_2View();
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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
//	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // Dr34_2View.cpp �̃f�o�b�O �o�[�W����
inline CDr34_2Doc* CDr34_2View::GetDocument() const
   { return reinterpret_cast<CDr34_2Doc*>(m_pDocument); }
#endif

