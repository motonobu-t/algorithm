// Dr4View.h : CDr4View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr4View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr4View();
	DECLARE_DYNCREATE(CDr4View)

public:
	enum{ IDD = IDD_DR4_FORM };

// ����
public:
	CDr4Doc* GetDocument() const;

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
	virtual ~CDr4View();
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

#ifndef _DEBUG  // Dr4View.cpp �̃f�o�b�O �o�[�W����
inline CDr4Doc* CDr4View::GetDocument() const
   { return reinterpret_cast<CDr4Doc*>(m_pDocument); }
#endif

