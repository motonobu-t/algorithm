// Rei65View.h : CRei65View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei65View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei65View();
	DECLARE_DYNCREATE(CRei65View)

public:
	enum{ IDD = IDD_REI65_FORM };

// ����
public:
	CRei65Doc* GetDocument() const;

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
	virtual ~CRei65View();
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
	CEdit text1;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // Rei65View.cpp �̃f�o�b�O �o�[�W����
inline CRei65Doc* CRei65View::GetDocument() const
   { return reinterpret_cast<CRei65Doc*>(m_pDocument); }
#endif

