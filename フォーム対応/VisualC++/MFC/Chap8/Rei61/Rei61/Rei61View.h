// Rei61View.h : CRei61View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei61View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei61View();
	DECLARE_DYNCREATE(CRei61View)

public:
	enum{ IDD = IDD_REI61_FORM };

// ����
public:
	CRei61Doc* GetDocument() const;

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
	virtual ~CRei61View();
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

#ifndef _DEBUG  // Rei61View.cpp �̃f�o�b�O �o�[�W����
inline CRei61Doc* CRei61View::GetDocument() const
   { return reinterpret_cast<CRei61Doc*>(m_pDocument); }
#endif

