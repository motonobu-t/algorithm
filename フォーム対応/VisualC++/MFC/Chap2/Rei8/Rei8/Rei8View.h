// Rei8View.h : CRei8View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei8View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei8View();
	DECLARE_DYNCREATE(CRei8View)

public:
	enum{ IDD = IDD_REI8_FORM };

// ����
public:
	CRei8Doc* GetDocument() const;

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
	virtual ~CRei8View();
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

#ifndef _DEBUG  // Rei8View.cpp �̃f�o�b�O �o�[�W����
inline CRei8Doc* CRei8View::GetDocument() const
   { return reinterpret_cast<CRei8Doc*>(m_pDocument); }
#endif

