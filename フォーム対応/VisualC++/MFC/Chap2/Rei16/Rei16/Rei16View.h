// Rei16View.h : CRei16View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CRei16View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei16View();
	DECLARE_DYNCREATE(CRei16View)

public:
	enum{ IDD = IDD_REI16_FORM };

// ����
public:
	CRei16Doc* GetDocument() const;

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
	virtual ~CRei16View();
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

#ifndef _DEBUG  // Rei16View.cpp �̃f�o�b�O �o�[�W����
inline CRei16Doc* CRei16View::GetDocument() const
   { return reinterpret_cast<CRei16Doc*>(m_pDocument); }
#endif

