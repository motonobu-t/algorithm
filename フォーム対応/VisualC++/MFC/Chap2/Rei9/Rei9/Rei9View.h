// Rei9View.h : CRei9View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei9View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei9View();
	DECLARE_DYNCREATE(CRei9View)

public:
	enum{ IDD = IDD_REI9_FORM };

// ����
public:
	CRei9Doc* GetDocument() const;

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
	virtual ~CRei9View();
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

#ifndef _DEBUG  // Rei9View.cpp �̃f�o�b�O �o�[�W����
inline CRei9Doc* CRei9View::GetDocument() const
   { return reinterpret_cast<CRei9Doc*>(m_pDocument); }
#endif

