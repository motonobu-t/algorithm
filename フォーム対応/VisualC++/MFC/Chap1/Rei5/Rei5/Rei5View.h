// Rei5View.h : CRei5View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei5View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei5View();
	DECLARE_DYNCREATE(CRei5View)

public:
	enum{ IDD = IDD_REI5_FORM };

// ����
public:
	CRei5Doc* GetDocument() const;

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
	virtual ~CRei5View();
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
//	afx_msg void OnStnClickedPict();
};

#ifndef _DEBUG  // Rei5View.cpp �̃f�o�b�O �o�[�W����
inline CRei5Doc* CRei5View::GetDocument() const
   { return reinterpret_cast<CRei5Doc*>(m_pDocument); }
#endif

