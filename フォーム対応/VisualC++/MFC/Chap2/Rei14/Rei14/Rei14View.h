// Rei14View.h : CRei14View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei14View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei14View();
	DECLARE_DYNCREATE(CRei14View)

public:
	enum{ IDD = IDD_REI14_FORM };

// ����
public:
	CRei14Doc* GetDocument() const;

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
	virtual ~CRei14View();
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

#ifndef _DEBUG  // Rei14View.cpp �̃f�o�b�O �o�[�W����
inline CRei14Doc* CRei14View::GetDocument() const
   { return reinterpret_cast<CRei14Doc*>(m_pDocument); }
#endif

