// Dr17View.h : CDr17View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr17View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr17View();
	DECLARE_DYNCREATE(CDr17View)

public:
	enum{ IDD = IDD_DR17_FORM };

// ����
public:
	CDr17Doc* GetDocument() const;

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
	virtual ~CDr17View();
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

#ifndef _DEBUG  // Dr17View.cpp �̃f�o�b�O �o�[�W����
inline CDr17Doc* CDr17View::GetDocument() const
   { return reinterpret_cast<CDr17Doc*>(m_pDocument); }
#endif

