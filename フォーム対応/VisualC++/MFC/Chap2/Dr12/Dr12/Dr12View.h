// Dr12View.h : CDr12View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr12View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr12View();
	DECLARE_DYNCREATE(CDr12View)

public:
	enum{ IDD = IDD_DR12_FORM };

// ����
public:
	CDr12Doc* GetDocument() const;

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
	virtual ~CDr12View();
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

#ifndef _DEBUG  // Dr12View.cpp �̃f�o�b�O �o�[�W����
inline CDr12Doc* CDr12View::GetDocument() const
   { return reinterpret_cast<CDr12Doc*>(m_pDocument); }
#endif

