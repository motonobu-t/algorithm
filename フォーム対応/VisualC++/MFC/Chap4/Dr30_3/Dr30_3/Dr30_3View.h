// Dr30_3View.h : CDr30_3View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr30_3View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr30_3View();
	DECLARE_DYNCREATE(CDr30_3View)

public:
	enum{ IDD = IDD_DR30_3_FORM };

// ����
public:
	CDr30_3Doc* GetDocument() const;

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
	virtual ~CDr30_3View();
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

#ifndef _DEBUG  // Dr30_3View.cpp �̃f�o�b�O �o�[�W����
inline CDr30_3Doc* CDr30_3View::GetDocument() const
   { return reinterpret_cast<CDr30_3Doc*>(m_pDocument); }
#endif

