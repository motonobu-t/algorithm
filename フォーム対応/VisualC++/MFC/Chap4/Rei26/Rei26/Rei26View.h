// Rei26View.h : CRei26View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei26View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei26View();
	DECLARE_DYNCREATE(CRei26View)

public:
	enum{ IDD = IDD_REI26_FORM };

// ����
public:
	CRei26Doc* GetDocument() const;

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
	virtual ~CRei26View();
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
};

#ifndef _DEBUG  // Rei26View.cpp �̃f�o�b�O �o�[�W����
inline CRei26Doc* CRei26View::GetDocument() const
   { return reinterpret_cast<CRei26Doc*>(m_pDocument); }
#endif

