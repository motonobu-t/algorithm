// Rei18View.h : CRei18View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei18View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei18View();
	DECLARE_DYNCREATE(CRei18View)

public:
	enum{ IDD = IDD_REI18_FORM };

// ����
public:
	CRei18Doc* GetDocument() const;

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
	virtual ~CRei18View();
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

#ifndef _DEBUG  // Rei18View.cpp �̃f�o�b�O �o�[�W����
inline CRei18Doc* CRei18View::GetDocument() const
   { return reinterpret_cast<CRei18Doc*>(m_pDocument); }
#endif

