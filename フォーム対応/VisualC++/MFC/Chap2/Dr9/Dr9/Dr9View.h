// Dr9View.h : CDr9View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr9View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr9View();
	DECLARE_DYNCREATE(CDr9View)

public:
	enum{ IDD = IDD_DR9_FORM };

// ����
public:
	CDr9Doc* GetDocument() const;

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
	virtual ~CDr9View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CEdit text1;
	CEdit text2;
	afx_msg void OnBnClickedButton1();
	CStatic pict;
};

#ifndef _DEBUG  // Dr9View.cpp �̃f�o�b�O �o�[�W����
inline CDr9Doc* CDr9View::GetDocument() const
   { return reinterpret_cast<CDr9Doc*>(m_pDocument); }
#endif

