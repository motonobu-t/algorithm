// Dr33View.h : CDr33View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr33View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr33View();
	DECLARE_DYNCREATE(CDr33View)

public:
	enum{ IDD = IDD_DR33_FORM };

// ����
public:
	CDr33Doc* GetDocument() const;

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
	virtual ~CDr33View();
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
	afx_msg void OnBnClickedButton3();
};

#ifndef _DEBUG  // Dr33View.cpp �̃f�o�b�O �o�[�W����
inline CDr33Doc* CDr33View::GetDocument() const
   { return reinterpret_cast<CDr33Doc*>(m_pDocument); }
#endif

