// Dr26_4View.h : CDr26_4View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr26_4View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr26_4View();
	DECLARE_DYNCREATE(CDr26_4View)

public:
	enum{ IDD = IDD_DR26_4_FORM };

// ����
public:
	CDr26_4Doc* GetDocument() const;

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
	virtual ~CDr26_4View();
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
	CEdit text2;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // Dr26_4View.cpp �̃f�o�b�O �o�[�W����
inline CDr26_4Doc* CDr26_4View::GetDocument() const
   { return reinterpret_cast<CDr26_4Doc*>(m_pDocument); }
#endif

