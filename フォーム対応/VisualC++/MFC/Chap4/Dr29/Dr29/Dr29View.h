// Dr29View.h : CDr29View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr29View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr29View();
	DECLARE_DYNCREATE(CDr29View)

public:
	enum{ IDD = IDD_DR29_FORM };

// ����
public:
	CDr29Doc* GetDocument() const;

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
	virtual ~CDr29View();
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

#ifndef _DEBUG  // Dr29View.cpp �̃f�o�b�O �o�[�W����
inline CDr29Doc* CDr29View::GetDocument() const
   { return reinterpret_cast<CDr29Doc*>(m_pDocument); }
#endif

