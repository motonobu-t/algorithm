// Dr53View.h : CDr53View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr53View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr53View();
	DECLARE_DYNCREATE(CDr53View)

public:
	enum{ IDD = IDD_DR53_FORM };

// ����
public:
	CDr53Doc* GetDocument() const;

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
	virtual ~CDr53View();
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
//	afx_msg void OnStnClickedPict();
};

#ifndef _DEBUG  // Dr53View.cpp �̃f�o�b�O �o�[�W����
inline CDr53Doc* CDr53View::GetDocument() const
   { return reinterpret_cast<CDr53Doc*>(m_pDocument); }
#endif

