// Rei66View.h : CRei66View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei66View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei66View();
	DECLARE_DYNCREATE(CRei66View)

public:
	enum{ IDD = IDD_REI66_FORM };

// ����
public:
	CRei66Doc* GetDocument() const;

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
	virtual ~CRei66View();
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

#ifndef _DEBUG  // Rei66View.cpp �̃f�o�b�O �o�[�W����
inline CRei66Doc* CRei66View::GetDocument() const
   { return reinterpret_cast<CRei66Doc*>(m_pDocument); }
#endif

