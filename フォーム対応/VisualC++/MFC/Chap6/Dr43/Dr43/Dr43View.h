// Dr43View.h : CDr43View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr43View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr43View();
	DECLARE_DYNCREATE(CDr43View)

public:
	enum{ IDD = IDD_DR43_FORM };

// ����
public:
	CDr43Doc* GetDocument() const;

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
	virtual ~CDr43View();
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

#ifndef _DEBUG  // Dr43View.cpp �̃f�o�b�O �o�[�W����
inline CDr43Doc* CDr43View::GetDocument() const
   { return reinterpret_cast<CDr43Doc*>(m_pDocument); }
#endif

