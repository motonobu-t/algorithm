// Rei24View.h : CRei24View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei24View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei24View();
	DECLARE_DYNCREATE(CRei24View)

public:
	enum{ IDD = IDD_REI24_FORM };

// ����
public:
	CRei24Doc* GetDocument() const;

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
	virtual ~CRei24View();
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

#ifndef _DEBUG  // Rei24View.cpp �̃f�o�b�O �o�[�W����
inline CRei24Doc* CRei24View::GetDocument() const
   { return reinterpret_cast<CRei24Doc*>(m_pDocument); }
#endif

