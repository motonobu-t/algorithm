// Rei22View.h : CRei22View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei22View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei22View();
	DECLARE_DYNCREATE(CRei22View)

public:
	enum{ IDD = IDD_REI22_FORM };

// ����
public:
	CRei22Doc* GetDocument() const;

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
	virtual ~CRei22View();
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

#ifndef _DEBUG  // Rei22View.cpp �̃f�o�b�O �o�[�W����
inline CRei22Doc* CRei22View::GetDocument() const
   { return reinterpret_cast<CRei22Doc*>(m_pDocument); }
#endif

