// Rei45View.h : CRei45View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei45View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei45View();
	DECLARE_DYNCREATE(CRei45View)

public:
	enum{ IDD = IDD_REI45_FORM };

// ����
public:
	CRei45Doc* GetDocument() const;

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
	virtual ~CRei45View();
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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // Rei45View.cpp �̃f�o�b�O �o�[�W����
inline CRei45Doc* CRei45View::GetDocument() const
   { return reinterpret_cast<CRei45Doc*>(m_pDocument); }
#endif

