// Rei62View.h : CRei62View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei62View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei62View();
	DECLARE_DYNCREATE(CRei62View)

public:
	enum{ IDD = IDD_REI62_FORM };

// ����
public:
	CRei62Doc* GetDocument() const;

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
	virtual ~CRei62View();
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

#ifndef _DEBUG  // Rei62View.cpp �̃f�o�b�O �o�[�W����
inline CRei62Doc* CRei62View::GetDocument() const
   { return reinterpret_cast<CRei62Doc*>(m_pDocument); }
#endif

