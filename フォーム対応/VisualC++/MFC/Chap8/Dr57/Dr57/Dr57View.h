// Dr57View.h : CDr57View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr57View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr57View();
	DECLARE_DYNCREATE(CDr57View)

public:
	enum{ IDD = IDD_DR57_FORM };

// ����
public:
	CDr57Doc* GetDocument() const;

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
	virtual ~CDr57View();
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

#ifndef _DEBUG  // Dr57View.cpp �̃f�o�b�O �o�[�W����
inline CDr57Doc* CDr57View::GetDocument() const
   { return reinterpret_cast<CDr57Doc*>(m_pDocument); }
#endif

