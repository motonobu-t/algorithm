// Rei7View.h : CRei7View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei7View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei7View();
	DECLARE_DYNCREATE(CRei7View)

public:
	enum{ IDD = IDD_REI7_FORM };

// ����
public:
	CRei7Doc* GetDocument() const;

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
	virtual ~CRei7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CEdit text1;
	afx_msg void OnBnClickedButton1();
	CStatic pict;
};

#ifndef _DEBUG  // Rei7View.cpp �̃f�o�b�O �o�[�W����
inline CRei7Doc* CRei7View::GetDocument() const
   { return reinterpret_cast<CRei7Doc*>(m_pDocument); }
#endif

