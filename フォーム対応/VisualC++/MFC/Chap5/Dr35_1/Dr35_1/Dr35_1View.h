// Dr35_1View.h : CDr35_1View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr35_1View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr35_1View();
	DECLARE_DYNCREATE(CDr35_1View)

public:
	enum{ IDD = IDD_DR35_1_FORM };

// ����
public:
	CDr35_1Doc* GetDocument() const;

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
	virtual ~CDr35_1View();
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
};

#ifndef _DEBUG  // Dr35_1View.cpp �̃f�o�b�O �o�[�W����
inline CDr35_1Doc* CDr35_1View::GetDocument() const
   { return reinterpret_cast<CDr35_1Doc*>(m_pDocument); }
#endif

