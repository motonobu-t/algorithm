// Dr21View.h : CDr21View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr21View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr21View();
	DECLARE_DYNCREATE(CDr21View)

public:
	enum{ IDD = IDD_DR21_FORM };

// ����
public:
	CDr21Doc* GetDocument() const;

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
	virtual ~CDr21View();
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
	CEdit text1;
};

#ifndef _DEBUG  // Dr21View.cpp �̃f�o�b�O �o�[�W����
inline CDr21Doc* CDr21View::GetDocument() const
   { return reinterpret_cast<CDr21Doc*>(m_pDocument); }
#endif

