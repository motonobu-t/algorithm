// Rei66ListBoxView.h : CRei66ListBoxView �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei66ListBoxView : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei66ListBoxView();
	DECLARE_DYNCREATE(CRei66ListBoxView)

public:
	enum{ IDD = IDD_REI66LISTBOX_FORM };

// ����
public:
	CRei66ListBoxDoc* GetDocument() const;

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
	virtual ~CRei66ListBoxView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_list1;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // Rei66ListBoxView.cpp �̃f�o�b�O �o�[�W����
inline CRei66ListBoxDoc* CRei66ListBoxView::GetDocument() const
   { return reinterpret_cast<CRei66ListBoxDoc*>(m_pDocument); }
#endif

