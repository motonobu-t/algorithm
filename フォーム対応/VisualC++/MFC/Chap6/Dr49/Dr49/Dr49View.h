// Dr49View.h : CDr49View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr49View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr49View();
	DECLARE_DYNCREATE(CDr49View)

public:
	enum{ IDD = IDD_DR49_FORM };

// ����
public:
	CDr49Doc* GetDocument() const;

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
	virtual ~CDr49View();
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

#ifndef _DEBUG  // Dr49View.cpp �̃f�o�b�O �o�[�W����
inline CDr49Doc* CDr49View::GetDocument() const
   { return reinterpret_cast<CDr49Doc*>(m_pDocument); }
#endif

