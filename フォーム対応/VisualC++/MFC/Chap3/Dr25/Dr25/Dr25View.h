// Dr25View.h : CDr25View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr25View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr25View();
	DECLARE_DYNCREATE(CDr25View)

public:
	enum{ IDD = IDD_DR25_FORM };

// ����
public:
	CDr25Doc* GetDocument() const;

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
	virtual ~CDr25View();
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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CEdit text1;
	CEdit text2;
	CEdit text3;
};

#ifndef _DEBUG  // Dr25View.cpp �̃f�o�b�O �o�[�W����
inline CDr25Doc* CDr25View::GetDocument() const
   { return reinterpret_cast<CDr25Doc*>(m_pDocument); }
#endif

