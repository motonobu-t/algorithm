// Dr32View.h : CDr32View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr32View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr32View();
	DECLARE_DYNCREATE(CDr32View)

public:
	enum{ IDD = IDD_DR32_FORM };

// ����
public:
	CDr32Doc* GetDocument() const;

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
	virtual ~CDr32View();
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

#ifndef _DEBUG  // Dr32View.cpp �̃f�o�b�O �o�[�W����
inline CDr32Doc* CDr32View::GetDocument() const
   { return reinterpret_cast<CDr32Doc*>(m_pDocument); }
#endif

