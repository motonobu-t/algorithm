// Rei37View.h : CRei37View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei37View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei37View();
	DECLARE_DYNCREATE(CRei37View)

public:
	enum{ IDD = IDD_REI37_FORM };

// ����
public:
	CRei37Doc* GetDocument() const;

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
	virtual ~CRei37View();
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
	CEdit text2;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // Rei37View.cpp �̃f�o�b�O �o�[�W����
inline CRei37Doc* CRei37View::GetDocument() const
   { return reinterpret_cast<CRei37Doc*>(m_pDocument); }
#endif

