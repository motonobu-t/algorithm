// Dr65View.h : CDr65View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr65View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr65View();
	DECLARE_DYNCREATE(CDr65View)

public:
	enum{ IDD = IDD_DR65_FORM };

// ����
public:
	CDr65Doc* GetDocument() const;

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
	virtual ~CDr65View();
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

#ifndef _DEBUG  // Dr65View.cpp �̃f�o�b�O �o�[�W����
inline CDr65Doc* CDr65View::GetDocument() const
   { return reinterpret_cast<CDr65Doc*>(m_pDocument); }
#endif

