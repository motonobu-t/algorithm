// Dr55View.h : CDr55View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr55View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr55View();
	DECLARE_DYNCREATE(CDr55View)

public:
	enum{ IDD = IDD_DR55_FORM };

// ����
public:
	CDr55Doc* GetDocument() const;

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
	virtual ~CDr55View();
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
};

#ifndef _DEBUG  // Dr55View.cpp �̃f�o�b�O �o�[�W����
inline CDr55Doc* CDr55View::GetDocument() const
   { return reinterpret_cast<CDr55Doc*>(m_pDocument); }
#endif

