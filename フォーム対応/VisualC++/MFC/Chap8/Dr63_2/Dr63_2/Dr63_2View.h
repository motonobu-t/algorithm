// Dr63_2View.h : CDr63_2View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr63_2View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr63_2View();
	DECLARE_DYNCREATE(CDr63_2View)

public:
	enum{ IDD = IDD_DR63_2_FORM };

// ����
public:
	CDr63_2Doc* GetDocument() const;

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
	virtual ~CDr63_2View();
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

#ifndef _DEBUG  // Dr63_2View.cpp �̃f�o�b�O �o�[�W����
inline CDr63_2Doc* CDr63_2View::GetDocument() const
   { return reinterpret_cast<CDr63_2Doc*>(m_pDocument); }
#endif

