// Dr24View.h : CDr24View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr24View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr24View();
	DECLARE_DYNCREATE(CDr24View)

public:
	enum{ IDD = IDD_DR24_FORM };

// ����
public:
	CDr24Doc* GetDocument() const;

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
	virtual ~CDr24View();
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

#ifndef _DEBUG  // Dr24View.cpp �̃f�o�b�O �o�[�W����
inline CDr24Doc* CDr24View::GetDocument() const
   { return reinterpret_cast<CDr24Doc*>(m_pDocument); }
#endif

