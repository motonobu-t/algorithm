// Dr39View.h : CDr39View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr39View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr39View();
	DECLARE_DYNCREATE(CDr39View)

public:
	enum{ IDD = IDD_DR39_FORM };

// ����
public:
	CDr39Doc* GetDocument() const;

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
	virtual ~CDr39View();
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

#ifndef _DEBUG  // Dr39View.cpp �̃f�o�b�O �o�[�W����
inline CDr39Doc* CDr39View::GetDocument() const
   { return reinterpret_cast<CDr39Doc*>(m_pDocument); }
#endif

