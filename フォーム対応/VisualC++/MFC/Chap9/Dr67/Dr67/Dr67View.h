// Dr67View.h : CDr67View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr67View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr67View();
	DECLARE_DYNCREATE(CDr67View)

public:
	enum{ IDD = IDD_DR67_FORM };

// ����
public:
	CDr67Doc* GetDocument() const;

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
	virtual ~CDr67View();
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

#ifndef _DEBUG  // Dr67View.cpp �̃f�o�b�O �o�[�W����
inline CDr67Doc* CDr67View::GetDocument() const
   { return reinterpret_cast<CDr67Doc*>(m_pDocument); }
#endif

