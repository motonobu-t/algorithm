// rei54View.h : Crei54View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class Crei54View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	Crei54View();
	DECLARE_DYNCREATE(Crei54View)

public:
	enum{ IDD = IDD_REI54_FORM };

// ����
public:
	Crei54Doc* GetDocument() const;

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
	virtual ~Crei54View();
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

#ifndef _DEBUG  // rei54View.cpp �̃f�o�b�O �o�[�W����
inline Crei54Doc* Crei54View::GetDocument() const
   { return reinterpret_cast<Crei54Doc*>(m_pDocument); }
#endif

