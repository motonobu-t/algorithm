// Rei49View.h : CRei49View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei49View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei49View();
	DECLARE_DYNCREATE(CRei49View)

public:
	enum{ IDD = IDD_REI49_FORM };

// ����
public:
	CRei49Doc* GetDocument() const;

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
	virtual ~CRei49View();
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

#ifndef _DEBUG  // Rei49View.cpp �̃f�o�b�O �o�[�W����
inline CRei49Doc* CRei49View::GetDocument() const
   { return reinterpret_cast<CRei49Doc*>(m_pDocument); }
#endif

