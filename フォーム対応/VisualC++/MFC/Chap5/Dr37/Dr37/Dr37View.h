// Dr37View.h : CDr37View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr37View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr37View();
	DECLARE_DYNCREATE(CDr37View)

public:
	enum{ IDD = IDD_DR37_FORM };

// ����
public:
	CDr37Doc* GetDocument() const;

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
	virtual ~CDr37View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CEdit text1;
	CEdit text2;
	CStatic pict;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // Dr37View.cpp �̃f�o�b�O �o�[�W����
inline CDr37Doc* CDr37View::GetDocument() const
   { return reinterpret_cast<CDr37Doc*>(m_pDocument); }
#endif

