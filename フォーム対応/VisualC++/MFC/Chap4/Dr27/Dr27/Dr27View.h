// Dr27View.h : CDr27View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr27View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr27View();
	DECLARE_DYNCREATE(CDr27View)

public:
	enum{ IDD = IDD_DR27_FORM };

// ����
public:
	CDr27Doc* GetDocument() const;

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
	virtual ~CDr27View();
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

#ifndef _DEBUG  // Dr27View.cpp �̃f�o�b�O �o�[�W����
inline CDr27Doc* CDr27View::GetDocument() const
   { return reinterpret_cast<CDr27Doc*>(m_pDocument); }
#endif

