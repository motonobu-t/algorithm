// Dr45_1View.h : CDr45_1View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr45_1View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr45_1View();
	DECLARE_DYNCREATE(CDr45_1View)

public:
	enum{ IDD = IDD_DR45_1_FORM };

// ����
public:
	CDr45_1Doc* GetDocument() const;

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
	virtual ~CDr45_1View();
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
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // Dr45_1View.cpp �̃f�o�b�O �o�[�W����
inline CDr45_1Doc* CDr45_1View::GetDocument() const
   { return reinterpret_cast<CDr45_1Doc*>(m_pDocument); }
#endif

