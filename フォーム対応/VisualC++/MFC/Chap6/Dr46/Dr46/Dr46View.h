// Dr46View.h : CDr46View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr46View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr46View();
	DECLARE_DYNCREATE(CDr46View)

public:
	enum{ IDD = IDD_DR46_FORM };

// ����
public:
	CDr46Doc* GetDocument() const;

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
	virtual ~CDr46View();
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

#ifndef _DEBUG  // Dr46View.cpp �̃f�o�b�O �o�[�W����
inline CDr46Doc* CDr46View::GetDocument() const
   { return reinterpret_cast<CDr46Doc*>(m_pDocument); }
#endif

