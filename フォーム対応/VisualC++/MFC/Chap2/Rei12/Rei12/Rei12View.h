// Rei12View.h : CRei12View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei12View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei12View();
	DECLARE_DYNCREATE(CRei12View)

public:
	enum{ IDD = IDD_REI12_FORM };

// ����
public:
	CRei12Doc* GetDocument() const;

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
	virtual ~CRei12View();
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

#ifndef _DEBUG  // Rei12View.cpp �̃f�o�b�O �o�[�W����
inline CRei12Doc* CRei12View::GetDocument() const
   { return reinterpret_cast<CRei12Doc*>(m_pDocument); }
#endif

