// Dr47View.h : CDr47View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr47View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr47View();
	DECLARE_DYNCREATE(CDr47View)

public:
	enum{ IDD = IDD_DR47_FORM };

// ����
public:
	CDr47Doc* GetDocument() const;

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
	virtual ~CDr47View();
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

#ifndef _DEBUG  // Dr47View.cpp �̃f�o�b�O �o�[�W����
inline CDr47Doc* CDr47View::GetDocument() const
   { return reinterpret_cast<CDr47Doc*>(m_pDocument); }
#endif

