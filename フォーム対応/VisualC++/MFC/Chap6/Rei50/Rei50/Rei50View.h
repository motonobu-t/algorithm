// Rei50View.h : CRei50View �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CRei50View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei50View();
	DECLARE_DYNCREATE(CRei50View)

public:
	enum{ IDD = IDD_REI50_FORM };

// ����
public:
	CRei50Doc* GetDocument() const;

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
	virtual ~CRei50View();
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
};

#ifndef _DEBUG  // Rei50View.cpp �̃f�o�b�O �o�[�W����
inline CRei50Doc* CRei50View::GetDocument() const
   { return reinterpret_cast<CRei50Doc*>(m_pDocument); }
#endif

