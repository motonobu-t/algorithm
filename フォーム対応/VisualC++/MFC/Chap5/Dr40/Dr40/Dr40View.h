// Dr40View.h : CDr40View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr40View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr40View();
	DECLARE_DYNCREATE(CDr40View)

public:
	enum{ IDD = IDD_DR40_FORM };

// ����
public:
	CDr40Doc* GetDocument() const;

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
	virtual ~CDr40View();
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
	CEdit text3;
	CStatic pict;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};

#ifndef _DEBUG  // Dr40View.cpp �̃f�o�b�O �o�[�W����
inline CDr40Doc* CDr40View::GetDocument() const
   { return reinterpret_cast<CDr40Doc*>(m_pDocument); }
#endif

