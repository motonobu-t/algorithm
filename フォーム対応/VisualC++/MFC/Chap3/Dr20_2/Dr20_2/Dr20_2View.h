// Dr20_2View.h : CDr20_2View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr20_2View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr20_2View();
	DECLARE_DYNCREATE(CDr20_2View)

public:
	enum{ IDD = IDD_DR20_2_FORM };

// ����
public:
	CDr20_2Doc* GetDocument() const;

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
	virtual ~CDr20_2View();
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
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // Dr20_2View.cpp �̃f�o�b�O �o�[�W����
inline CDr20_2Doc* CDr20_2View::GetDocument() const
   { return reinterpret_cast<CDr20_2Doc*>(m_pDocument); }
#endif

