// Dr66View.h : CDr66View �N���X�̃C���^�[�t�F�C�X
//


#pragma once
#include "afxwin.h"


class CDr66View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr66View();
	DECLARE_DYNCREATE(CDr66View)

public:
	enum{ IDD = IDD_DR66_FORM };

// ����
public:
	CDr66Doc* GetDocument() const;

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
	virtual ~CDr66View();
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

#ifndef _DEBUG  // Dr66View.cpp �̃f�o�b�O �o�[�W����
inline CDr66Doc* CDr66View::GetDocument() const
   { return reinterpret_cast<CDr66Doc*>(m_pDocument); }
#endif

