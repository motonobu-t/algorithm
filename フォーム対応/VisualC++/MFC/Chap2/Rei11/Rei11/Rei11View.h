// Rei11View.h : CRei11View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei11View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei11View();
	DECLARE_DYNCREATE(CRei11View)

public:
	enum{ IDD = IDD_REI11_FORM };

// ����
public:
	CRei11Doc* GetDocument() const;

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
	virtual ~CRei11View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CStatic pict;
};

#ifndef _DEBUG  // Rei11View.cpp �̃f�o�b�O �o�[�W����
inline CRei11Doc* CRei11View::GetDocument() const
   { return reinterpret_cast<CRei11Doc*>(m_pDocument); }
#endif

