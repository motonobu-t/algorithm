// Dr14_1View.h : CDr14_1View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr14_1View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr14_1View();
	DECLARE_DYNCREATE(CDr14_1View)

public:
	enum{ IDD = IDD_DR14_1_FORM };

// ����
public:
	CDr14_1Doc* GetDocument() const;

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
	virtual ~CDr14_1View();
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

#ifndef _DEBUG  // Dr14_1View.cpp �̃f�o�b�O �o�[�W����
inline CDr14_1Doc* CDr14_1View::GetDocument() const
   { return reinterpret_cast<CDr14_1Doc*>(m_pDocument); }
#endif

