// Rei27View.h : CRei27View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei27View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei27View();
	DECLARE_DYNCREATE(CRei27View)

public:
	enum{ IDD = IDD_REI27_FORM };

// ����
public:
	CRei27Doc* GetDocument() const;

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
	virtual ~CRei27View();
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

#ifndef _DEBUG  // Rei27View.cpp �̃f�o�b�O �o�[�W����
inline CRei27Doc* CRei27View::GetDocument() const
   { return reinterpret_cast<CRei27Doc*>(m_pDocument); }
#endif

