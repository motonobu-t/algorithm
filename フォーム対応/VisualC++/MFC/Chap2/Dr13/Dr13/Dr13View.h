// Dr13View.h : CDr13View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr13View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr13View();
	DECLARE_DYNCREATE(CDr13View)

public:
	enum{ IDD = IDD_DR13_FORM };

// ����
public:
	CDr13Doc* GetDocument() const;

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
	virtual ~CDr13View();
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

#ifndef _DEBUG  // Dr13View.cpp �̃f�o�b�O �o�[�W����
inline CDr13Doc* CDr13View::GetDocument() const
   { return reinterpret_cast<CDr13Doc*>(m_pDocument); }
#endif

