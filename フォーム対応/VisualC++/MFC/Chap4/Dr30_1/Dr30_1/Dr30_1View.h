// Dr30_1View.h : CDr30_1View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr30_1View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr30_1View();
	DECLARE_DYNCREATE(CDr30_1View)

public:
	enum{ IDD = IDD_DR30_1_FORM };

// ����
public:
	CDr30_1Doc* GetDocument() const;

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
	virtual ~CDr30_1View();
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

#ifndef _DEBUG  // Dr30_1View.cpp �̃f�o�b�O �o�[�W����
inline CDr30_1Doc* CDr30_1View::GetDocument() const
   { return reinterpret_cast<CDr30_1Doc*>(m_pDocument); }
#endif

