// Rei28View.h : CRei28View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei28View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei28View();
	DECLARE_DYNCREATE(CRei28View)

public:
	enum{ IDD = IDD_REI28_FORM };

// ����
public:
	CRei28Doc* GetDocument() const;

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
	virtual ~CRei28View();
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

#ifndef _DEBUG  // Rei28View.cpp �̃f�o�b�O �o�[�W����
inline CRei28Doc* CRei28View::GetDocument() const
   { return reinterpret_cast<CRei28Doc*>(m_pDocument); }
#endif

