// Dr48_2View.h : CDr48_2View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr48_2View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr48_2View();
	DECLARE_DYNCREATE(CDr48_2View)

public:
	enum{ IDD = IDD_DR48_2_FORM };

// ����
public:
	CDr48_2Doc* GetDocument() const;

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
	virtual ~CDr48_2View();
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

#ifndef _DEBUG  // Dr48_2View.cpp �̃f�o�b�O �o�[�W����
inline CDr48_2Doc* CDr48_2View::GetDocument() const
   { return reinterpret_cast<CDr48_2Doc*>(m_pDocument); }
#endif

