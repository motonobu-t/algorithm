// rei52View.h : Crei52View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class Crei52View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	Crei52View();
	DECLARE_DYNCREATE(Crei52View)

public:
	enum{ IDD = IDD_REI52_FORM };

// ����
public:
	Crei52Doc* GetDocument() const;

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
	virtual ~Crei52View();
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

#ifndef _DEBUG  // rei52View.cpp �̃f�o�b�O �o�[�W����
inline Crei52Doc* Crei52View::GetDocument() const
   { return reinterpret_cast<Crei52Doc*>(m_pDocument); }
#endif

