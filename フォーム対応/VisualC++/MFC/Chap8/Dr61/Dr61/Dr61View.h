// Dr61View.h : CDr61View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr61View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr61View();
	DECLARE_DYNCREATE(CDr61View)

public:
	enum{ IDD = IDD_DR61_FORM };

// ����
public:
	CDr61Doc* GetDocument() const;

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
	virtual ~CDr61View();
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

#ifndef _DEBUG  // Dr61View.cpp �̃f�o�b�O �o�[�W����
inline CDr61Doc* CDr61View::GetDocument() const
   { return reinterpret_cast<CDr61Doc*>(m_pDocument); }
#endif

