// Rei64View.h : CRei64View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei64View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei64View();
	DECLARE_DYNCREATE(CRei64View)

public:
	enum{ IDD = IDD_REI64_FORM };

// ����
public:
	CRei64Doc* GetDocument() const;

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
	virtual ~CRei64View();
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

#ifndef _DEBUG  // Rei64View.cpp �̃f�o�b�O �o�[�W����
inline CRei64Doc* CRei64View::GetDocument() const
   { return reinterpret_cast<CRei64Doc*>(m_pDocument); }
#endif

