// Dr62_2View.h : CDr62_2View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr62_2View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr62_2View();
	DECLARE_DYNCREATE(CDr62_2View)

public:
	enum{ IDD = IDD_DR62_2_FORM };

// ����
public:
	CDr62_2Doc* GetDocument() const;

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
	virtual ~CDr62_2View();
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

#ifndef _DEBUG  // Dr62_2View.cpp �̃f�o�b�O �o�[�W����
inline CDr62_2Doc* CDr62_2View::GetDocument() const
   { return reinterpret_cast<CDr62_2Doc*>(m_pDocument); }
#endif

