// Rei23View.h : CRei23View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei23View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei23View();
	DECLARE_DYNCREATE(CRei23View)

public:
	enum{ IDD = IDD_REI23_FORM };

// ����
public:
	CRei23Doc* GetDocument() const;

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
	virtual ~CRei23View();
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

#ifndef _DEBUG  // Rei23View.cpp �̃f�o�b�O �o�[�W����
inline CRei23Doc* CRei23View::GetDocument() const
   { return reinterpret_cast<CRei23Doc*>(m_pDocument); }
#endif

