// Rei67View.h : CRei67View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei67View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei67View();
	DECLARE_DYNCREATE(CRei67View)

public:
	enum{ IDD = IDD_REI67_FORM };

// ����
public:
	CRei67Doc* GetDocument() const;

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
	virtual ~CRei67View();
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

#ifndef _DEBUG  // Rei67View.cpp �̃f�o�b�O �o�[�W����
inline CRei67Doc* CRei67View::GetDocument() const
   { return reinterpret_cast<CRei67Doc*>(m_pDocument); }
#endif

