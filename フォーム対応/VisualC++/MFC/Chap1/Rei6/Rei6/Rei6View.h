// Rei6View.h : CRei6View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei6View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei6View();
	DECLARE_DYNCREATE(CRei6View)

public:
	enum{ IDD = IDD_REI6_FORM };

// ����
public:
	CRei6Doc* GetDocument() const;

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
	virtual ~CRei6View();
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
	CEdit text1;
	CEdit text2;
	CStatic pict;
};

#ifndef _DEBUG  // Rei6View.cpp �̃f�o�b�O �o�[�W����
inline CRei6Doc* CRei6View::GetDocument() const
   { return reinterpret_cast<CRei6Doc*>(m_pDocument); }
#endif

