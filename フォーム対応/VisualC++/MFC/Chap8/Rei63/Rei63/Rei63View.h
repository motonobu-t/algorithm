// Rei63View.h : CRei63View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei63View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei63View();
	DECLARE_DYNCREATE(CRei63View)

public:
	enum{ IDD = IDD_REI63_FORM };

// ����
public:
	CRei63Doc* GetDocument() const;

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
	virtual ~CRei63View();
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

#ifndef _DEBUG  // Rei63View.cpp �̃f�o�b�O �o�[�W����
inline CRei63Doc* CRei63View::GetDocument() const
   { return reinterpret_cast<CRei63Doc*>(m_pDocument); }
#endif

