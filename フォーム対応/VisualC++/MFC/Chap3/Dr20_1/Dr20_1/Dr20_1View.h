// Dr20_1View.h : CDr20_1View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr20_1View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr20_1View();
	DECLARE_DYNCREATE(CDr20_1View)

public:
	enum{ IDD = IDD_DR20_1_FORM };

// ����
public:
	CDr20_1Doc* GetDocument() const;

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
	virtual ~CDr20_1View();
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
//	afx_msg void OnStnClickedPict();
};

#ifndef _DEBUG  // Dr20_1View.cpp �̃f�o�b�O �o�[�W����
inline CDr20_1Doc* CDr20_1View::GetDocument() const
   { return reinterpret_cast<CDr20_1Doc*>(m_pDocument); }
#endif

