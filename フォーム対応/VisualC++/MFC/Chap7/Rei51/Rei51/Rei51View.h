// Rei51View.h : CRei51View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei51View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei51View();
	DECLARE_DYNCREATE(CRei51View)

public:
	enum{ IDD = IDD_REI51_FORM };

// ����
public:
	CRei51Doc* GetDocument() const;

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
	virtual ~CRei51View();
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
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // Rei51View.cpp �̃f�o�b�O �o�[�W����
inline CRei51Doc* CRei51View::GetDocument() const
   { return reinterpret_cast<CRei51Doc*>(m_pDocument); }
#endif

