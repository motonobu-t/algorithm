// Rei17View.h : CRei17View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei17View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei17View();
	DECLARE_DYNCREATE(CRei17View)

public:
	enum{ IDD = IDD_REI17_FORM };

// ����
public:
	CRei17Doc* GetDocument() const;

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
	virtual ~CRei17View();
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

#ifndef _DEBUG  // Rei17View.cpp �̃f�o�b�O �o�[�W����
inline CRei17Doc* CRei17View::GetDocument() const
   { return reinterpret_cast<CRei17Doc*>(m_pDocument); }
#endif

