// Rei38View.h : CRei38View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei38View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei38View();
	DECLARE_DYNCREATE(CRei38View)

public:
	enum{ IDD = IDD_REI38_FORM };

// ����
public:
	CRei38Doc* GetDocument() const;

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
	virtual ~CRei38View();
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

#ifndef _DEBUG  // Rei38View.cpp �̃f�o�b�O �o�[�W����
inline CRei38Doc* CRei38View::GetDocument() const
   { return reinterpret_cast<CRei38Doc*>(m_pDocument); }
#endif

