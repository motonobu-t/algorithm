// Rei39View.h : CRei39View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei39View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei39View();
	DECLARE_DYNCREATE(CRei39View)

public:
	enum{ IDD = IDD_REI39_FORM };

// ����
public:
	CRei39Doc* GetDocument() const;

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
	virtual ~CRei39View();
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

#ifndef _DEBUG  // Rei39View.cpp �̃f�o�b�O �o�[�W����
inline CRei39Doc* CRei39View::GetDocument() const
   { return reinterpret_cast<CRei39Doc*>(m_pDocument); }
#endif

