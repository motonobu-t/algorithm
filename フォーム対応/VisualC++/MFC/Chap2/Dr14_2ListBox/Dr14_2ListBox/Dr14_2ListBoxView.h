// Dr14_2ListBoxView.h : CDr14_2ListBoxView �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr14_2ListBoxView : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr14_2ListBoxView();
	DECLARE_DYNCREATE(CDr14_2ListBoxView)

public:
	enum{ IDD = IDD_DR14_2LISTBOX_FORM };

// ����
public:
	CDr14_2ListBoxDoc* GetDocument() const;

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
	virtual ~CDr14_2ListBoxView();
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

#ifndef _DEBUG  // Dr14_2ListBoxView.cpp �̃f�o�b�O �o�[�W����
inline CDr14_2ListBoxDoc* CDr14_2ListBoxView::GetDocument() const
   { return reinterpret_cast<CDr14_2ListBoxDoc*>(m_pDocument); }
#endif

