// Dr36View.h : CDr36View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr36View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr36View();
	DECLARE_DYNCREATE(CDr36View)

public:
	enum{ IDD = IDD_DR36_FORM };

// ����
public:
	CDr36Doc* GetDocument() const;

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
	virtual ~CDr36View();
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
	afx_msg void OnBnClickedButton3();
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBnClickedButton4();
};

#ifndef _DEBUG  // Dr36View.cpp �̃f�o�b�O �o�[�W����
inline CDr36Doc* CDr36View::GetDocument() const
   { return reinterpret_cast<CDr36Doc*>(m_pDocument); }
#endif

