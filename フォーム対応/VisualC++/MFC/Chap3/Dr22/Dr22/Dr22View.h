// Dr22View.h : CDr22View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr22View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr22View();
	DECLARE_DYNCREATE(CDr22View)

public:
	enum{ IDD = IDD_DR22_FORM };

// ����
public:
	CDr22Doc* GetDocument() const;

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
	virtual ~CDr22View();
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
};

#ifndef _DEBUG  // Dr22View.cpp �̃f�o�b�O �o�[�W����
inline CDr22Doc* CDr22View::GetDocument() const
   { return reinterpret_cast<CDr22Doc*>(m_pDocument); }
#endif

