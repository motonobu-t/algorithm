// Dr59View.h : CDr59View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr59View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr59View();
	DECLARE_DYNCREATE(CDr59View)

public:
	enum{ IDD = IDD_DR59_FORM };

// ����
public:
	CDr59Doc* GetDocument() const;

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
	virtual ~CDr59View();
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

#ifndef _DEBUG  // Dr59View.cpp �̃f�o�b�O �o�[�W����
inline CDr59Doc* CDr59View::GetDocument() const
   { return reinterpret_cast<CDr59Doc*>(m_pDocument); }
#endif

