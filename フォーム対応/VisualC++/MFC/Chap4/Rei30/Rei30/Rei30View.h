// Rei30View.h : CRei30View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei30View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei30View();
	DECLARE_DYNCREATE(CRei30View)

public:
	enum{ IDD = IDD_REI30_FORM };

// ����
public:
	CRei30Doc* GetDocument() const;

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
	virtual ~CRei30View();
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

#ifndef _DEBUG  // Rei30View.cpp �̃f�o�b�O �o�[�W����
inline CRei30Doc* CRei30View::GetDocument() const
   { return reinterpret_cast<CRei30Doc*>(m_pDocument); }
#endif

