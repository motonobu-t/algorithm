// Rei58View.h : CRei58View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei58View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei58View();
	DECLARE_DYNCREATE(CRei58View)

public:
	enum{ IDD = IDD_REI58_FORM };

// ����
public:
	CRei58Doc* GetDocument() const;

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
	virtual ~CRei58View();
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

#ifndef _DEBUG  // Rei58View.cpp �̃f�o�b�O �o�[�W����
inline CRei58Doc* CRei58View::GetDocument() const
   { return reinterpret_cast<CRei58Doc*>(m_pDocument); }
#endif

