// Dr31View.h : CDr31View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr31View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr31View();
	DECLARE_DYNCREATE(CDr31View)

public:
	enum{ IDD = IDD_DR31_FORM };

// ����
public:
	CDr31Doc* GetDocument() const;

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
	virtual ~CDr31View();
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

#ifndef _DEBUG  // Dr31View.cpp �̃f�o�b�O �o�[�W����
inline CDr31Doc* CDr31View::GetDocument() const
   { return reinterpret_cast<CDr31Doc*>(m_pDocument); }
#endif

