// Dr8_1View.h : CDr8_1View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr8_1View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr8_1View();
	DECLARE_DYNCREATE(CDr8_1View)

public:
	enum{ IDD = IDD_DR8_1_FORM };

// ����
public:
	CDr8_1Doc* GetDocument() const;

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
	virtual ~CDr8_1View();
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
	CStatic pict;
};

#ifndef _DEBUG  // Dr8_1View.cpp �̃f�o�b�O �o�[�W����
inline CDr8_1Doc* CDr8_1View::GetDocument() const
   { return reinterpret_cast<CDr8_1Doc*>(m_pDocument); }
#endif

