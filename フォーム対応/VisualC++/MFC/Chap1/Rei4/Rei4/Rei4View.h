// Rei4View.h : CRei4View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei4View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei4View();
	DECLARE_DYNCREATE(CRei4View)

public:
	enum{ IDD = IDD_REI4_FORM };

// ����
public:
	CRei4Doc* GetDocument() const;

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
	virtual ~CRei4View();
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

#ifndef _DEBUG  // Rei4View.cpp �̃f�o�b�O �o�[�W����
inline CRei4Doc* CRei4View::GetDocument() const
   { return reinterpret_cast<CRei4Doc*>(m_pDocument); }
#endif

