// Dr45_2View.h : CDr45_2View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr45_2View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr45_2View();
	DECLARE_DYNCREATE(CDr45_2View)

public:
	enum{ IDD = IDD_DR45_2_FORM };

// ����
public:
	CDr45_2Doc* GetDocument() const;

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
	virtual ~CDr45_2View();
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

#ifndef _DEBUG  // Dr45_2View.cpp �̃f�o�b�O �o�[�W����
inline CDr45_2Doc* CDr45_2View::GetDocument() const
   { return reinterpret_cast<CDr45_2Doc*>(m_pDocument); }
#endif

