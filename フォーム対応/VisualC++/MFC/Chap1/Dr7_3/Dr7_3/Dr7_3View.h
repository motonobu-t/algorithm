// Dr7_3View.h : CDr7_3View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr7_3View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr7_3View();
	DECLARE_DYNCREATE(CDr7_3View)

public:
	enum{ IDD = IDD_DR7_3_FORM };

// ����
public:
	CDr7_3Doc* GetDocument() const;

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
	virtual ~CDr7_3View();
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
	CEdit text1;
	CStatic pict;
};

#ifndef _DEBUG  // Dr7_3View.cpp �̃f�o�b�O �o�[�W����
inline CDr7_3Doc* CDr7_3View::GetDocument() const
   { return reinterpret_cast<CDr7_3Doc*>(m_pDocument); }
#endif

