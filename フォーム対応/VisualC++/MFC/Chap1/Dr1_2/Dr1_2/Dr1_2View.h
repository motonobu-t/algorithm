// Dr1_2View.h : CDr1_2View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr1_2View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr1_2View();
	DECLARE_DYNCREATE(CDr1_2View)

public:
	enum{ IDD = IDD_DR1_2_FORM };

// ����
public:
	CDr1_2Doc* GetDocument() const;

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
	virtual ~CDr1_2View();
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

#ifndef _DEBUG  // Dr1_2View.cpp �̃f�o�b�O �o�[�W����
inline CDr1_2Doc* CDr1_2View::GetDocument() const
   { return reinterpret_cast<CDr1_2Doc*>(m_pDocument); }
#endif

