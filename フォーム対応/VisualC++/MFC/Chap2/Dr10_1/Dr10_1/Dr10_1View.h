// Dr10_1View.h : CDr10_1View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr10_1View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr10_1View();
	DECLARE_DYNCREATE(CDr10_1View)

public:
	enum{ IDD = IDD_DR10_1_FORM };

// ����
public:
	CDr10_1Doc* GetDocument() const;

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
	virtual ~CDr10_1View();
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

#ifndef _DEBUG  // Dr10_1View.cpp �̃f�o�b�O �o�[�W����
inline CDr10_1Doc* CDr10_1View::GetDocument() const
   { return reinterpret_cast<CDr10_1Doc*>(m_pDocument); }
#endif

