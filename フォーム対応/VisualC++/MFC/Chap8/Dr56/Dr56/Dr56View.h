// Dr56View.h : CDr56View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr56View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr56View();
	DECLARE_DYNCREATE(CDr56View)

public:
	enum{ IDD = IDD_DR56_FORM };

// ����
public:
	CDr56Doc* GetDocument() const;

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
	virtual ~CDr56View();
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

#ifndef _DEBUG  // Dr56View.cpp �̃f�o�b�O �o�[�W����
inline CDr56Doc* CDr56View::GetDocument() const
   { return reinterpret_cast<CDr56Doc*>(m_pDocument); }
#endif

