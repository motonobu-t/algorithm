// Dr52View.h : CDr52View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr52View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr52View();
	DECLARE_DYNCREATE(CDr52View)

public:
	enum{ IDD = IDD_DR52_FORM };

// ����
public:
	CDr52Doc* GetDocument() const;

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
	virtual ~CDr52View();
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

#ifndef _DEBUG  // Dr52View.cpp �̃f�o�b�O �o�[�W����
inline CDr52Doc* CDr52View::GetDocument() const
   { return reinterpret_cast<CDr52Doc*>(m_pDocument); }
#endif

