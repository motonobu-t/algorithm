// Rei20View.h : CRei20View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei20View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei20View();
	DECLARE_DYNCREATE(CRei20View)

public:
	enum{ IDD = IDD_REI20_FORM };

// ����
public:
	CRei20Doc* GetDocument() const;

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
	virtual ~CRei20View();
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
	CEdit text1;
};

#ifndef _DEBUG  // Rei20View.cpp �̃f�o�b�O �o�[�W����
inline CRei20Doc* CRei20View::GetDocument() const
   { return reinterpret_cast<CRei20Doc*>(m_pDocument); }
#endif

