// Dr6View.h : CDr6View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr6View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr6View();
	DECLARE_DYNCREATE(CDr6View)

public:
	enum{ IDD = IDD_DR6_FORM };

// ����
public:
	CDr6Doc* GetDocument() const;

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
	virtual ~CDr6View();
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
	CEdit text1;
	CEdit text2;
	CStatic pict;
//	afx_msg void OnStnClickedPict();
};

#ifndef _DEBUG  // Dr6View.cpp �̃f�o�b�O �o�[�W����
inline CDr6Doc* CDr6View::GetDocument() const
   { return reinterpret_cast<CDr6Doc*>(m_pDocument); }
#endif

