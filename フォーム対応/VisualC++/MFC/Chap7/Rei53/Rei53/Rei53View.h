// Rei53View.h : CRei53View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei53View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei53View();
	DECLARE_DYNCREATE(CRei53View)

public:
	enum{ IDD = IDD_REI53_FORM };

// ����
public:
	CRei53Doc* GetDocument() const;

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
	virtual ~CRei53View();
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

#ifndef _DEBUG  // Rei53View.cpp �̃f�o�b�O �o�[�W����
inline CRei53Doc* CRei53View::GetDocument() const
   { return reinterpret_cast<CRei53Doc*>(m_pDocument); }
#endif

