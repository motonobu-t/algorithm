// Dr1_1View.h : CDr1_1View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr1_1View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr1_1View();
	DECLARE_DYNCREATE(CDr1_1View)

public:
	enum{ IDD = IDD_DR1_1_FORM };

// ����
public:
	CDr1_1Doc* GetDocument() const;

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
	virtual ~CDr1_1View();
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

#ifndef _DEBUG  // Dr1_1View.cpp �̃f�o�b�O �o�[�W����
inline CDr1_1Doc* CDr1_1View::GetDocument() const
   { return reinterpret_cast<CDr1_1Doc*>(m_pDocument); }
#endif

