// Rei10View.h : CRei10View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei10View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei10View();
	DECLARE_DYNCREATE(CRei10View)

public:
	enum{ IDD = IDD_REI10_FORM };

// ����
public:
	CRei10Doc* GetDocument() const;

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
	virtual ~CRei10View();
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

#ifndef _DEBUG  // Rei10View.cpp �̃f�o�b�O �o�[�W����
inline CRei10Doc* CRei10View::GetDocument() const
   { return reinterpret_cast<CRei10Doc*>(m_pDocument); }
#endif

