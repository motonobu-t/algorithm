// Dr54View.h : CDr54View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr54View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr54View();
	DECLARE_DYNCREATE(CDr54View)

public:
	enum{ IDD = IDD_DR54_FORM };

// ����
public:
	CDr54Doc* GetDocument() const;

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
	virtual ~CDr54View();
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

#ifndef _DEBUG  // Dr54View.cpp �̃f�o�b�O �o�[�W����
inline CDr54Doc* CDr54View::GetDocument() const
   { return reinterpret_cast<CDr54Doc*>(m_pDocument); }
#endif

