// Rei15View.h : CRei15View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei15View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei15View();
	DECLARE_DYNCREATE(CRei15View)

public:
	enum{ IDD = IDD_REI15_FORM };

// ����
public:
	CRei15Doc* GetDocument() const;

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
	virtual ~CRei15View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CStatic pict;
};

#ifndef _DEBUG  // Rei15View.cpp �̃f�o�b�O �o�[�W����
inline CRei15Doc* CRei15View::GetDocument() const
   { return reinterpret_cast<CRei15Doc*>(m_pDocument); }
#endif

