// Dr28_2View.h : CDr28_2View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr28_2View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr28_2View();
	DECLARE_DYNCREATE(CDr28_2View)

public:
	enum{ IDD = IDD_DR28_2_FORM };

// ����
public:
	CDr28_2Doc* GetDocument() const;

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
	virtual ~CDr28_2View();
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

#ifndef _DEBUG  // Dr28_2View.cpp �̃f�o�b�O �o�[�W����
inline CDr28_2Doc* CDr28_2View::GetDocument() const
   { return reinterpret_cast<CDr28_2Doc*>(m_pDocument); }
#endif

