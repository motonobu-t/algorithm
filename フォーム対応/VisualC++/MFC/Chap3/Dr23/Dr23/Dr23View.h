// Dr23View.h : CDr23View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr23View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr23View();
	DECLARE_DYNCREATE(CDr23View)

public:
	enum{ IDD = IDD_DR23_FORM };

// ����
public:
	CDr23Doc* GetDocument() const;

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
	virtual ~CDr23View();
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

#ifndef _DEBUG  // Dr23View.cpp �̃f�o�b�O �o�[�W����
inline CDr23Doc* CDr23View::GetDocument() const
   { return reinterpret_cast<CDr23Doc*>(m_pDocument); }
#endif

