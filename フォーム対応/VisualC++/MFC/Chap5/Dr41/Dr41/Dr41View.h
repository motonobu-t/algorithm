// Dr41View.h : CDr41View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr41View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr41View();
	DECLARE_DYNCREATE(CDr41View)

public:
	enum{ IDD = IDD_DR41_FORM };

// ����
public:
	CDr41Doc* GetDocument() const;

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
	virtual ~CDr41View();
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
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // Dr41View.cpp �̃f�o�b�O �o�[�W����
inline CDr41Doc* CDr41View::GetDocument() const
   { return reinterpret_cast<CDr41Doc*>(m_pDocument); }
#endif

