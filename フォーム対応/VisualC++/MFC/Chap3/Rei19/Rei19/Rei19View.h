// Rei19View.h : CRei19View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei19View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei19View();
	DECLARE_DYNCREATE(CRei19View)

public:
	enum{ IDD = IDD_REI19_FORM };

// ����
public:
	CRei19Doc* GetDocument() const;

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
	virtual ~CRei19View();
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

#ifndef _DEBUG  // Rei19View.cpp �̃f�o�b�O �o�[�W����
inline CRei19Doc* CRei19View::GetDocument() const
   { return reinterpret_cast<CRei19Doc*>(m_pDocument); }
#endif

