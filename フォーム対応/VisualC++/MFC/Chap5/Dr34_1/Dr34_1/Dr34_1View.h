// Dr34_1View.h : CDr34_1View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr34_1View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr34_1View();
	DECLARE_DYNCREATE(CDr34_1View)

public:
	enum{ IDD = IDD_DR34_1_FORM };

// ����
public:
	CDr34_1Doc* GetDocument() const;

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
	virtual ~CDr34_1View();
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
};

#ifndef _DEBUG  // Dr34_1View.cpp �̃f�o�b�O �o�[�W����
inline CDr34_1Doc* CDr34_1View::GetDocument() const
   { return reinterpret_cast<CDr34_1Doc*>(m_pDocument); }
#endif

