// Dr5View.h : CDr5View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr5View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr5View();
	DECLARE_DYNCREATE(CDr5View)

public:
	enum{ IDD = IDD_DR5_FORM };

// ����
public:
	CDr5Doc* GetDocument() const;

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
	virtual ~CDr5View();
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

#ifndef _DEBUG  // Dr5View.cpp �̃f�o�b�O �o�[�W����
inline CDr5Doc* CDr5View::GetDocument() const
   { return reinterpret_cast<CDr5Doc*>(m_pDocument); }
#endif

