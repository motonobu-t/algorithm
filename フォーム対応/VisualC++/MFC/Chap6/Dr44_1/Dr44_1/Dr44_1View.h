// Dr44_1View.h : CDr44_1View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr44_1View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr44_1View();
	DECLARE_DYNCREATE(CDr44_1View)

public:
	enum{ IDD = IDD_DR44_1_FORM };

// ����
public:
	CDr44_1Doc* GetDocument() const;

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
	virtual ~CDr44_1View();
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

#ifndef _DEBUG  // Dr44_1View.cpp �̃f�o�b�O �o�[�W����
inline CDr44_1Doc* CDr44_1View::GetDocument() const
   { return reinterpret_cast<CDr44_1Doc*>(m_pDocument); }
#endif

