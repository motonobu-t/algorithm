// Dr50_1View.h : CDr50_1View �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr50_1View : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr50_1View();
	DECLARE_DYNCREATE(CDr50_1View)

public:
	enum{ IDD = IDD_DR50_1_FORM };

// ����
public:
	CDr50_1Doc* GetDocument() const;

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
	virtual ~CDr50_1View();
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

#ifndef _DEBUG  // Dr50_1View.cpp �̃f�o�b�O �o�[�W����
inline CDr50_1Doc* CDr50_1View::GetDocument() const
   { return reinterpret_cast<CDr50_1Doc*>(m_pDocument); }
#endif

