// Rei3View.h : CRei3View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei3View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei3View();
	DECLARE_DYNCREATE(CRei3View)

public:
	enum{ IDD = IDD_REI3_FORM };

// ����
public:
	CRei3Doc* GetDocument() const;

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
	virtual ~CRei3View();
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

#ifndef _DEBUG  // Rei3View.cpp �̃f�o�b�O �o�[�W����
inline CRei3Doc* CRei3View::GetDocument() const
   { return reinterpret_cast<CRei3Doc*>(m_pDocument); }
#endif

