// Dr1_2LabelView.h : CDr1_2LabelView �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr1_2LabelView : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr1_2LabelView();
	DECLARE_DYNCREATE(CDr1_2LabelView)

public:
	enum{ IDD = IDD_DR1_2LABEL_FORM };

// ����
public:
	CDr1_2LabelDoc* GetDocument() const;

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
	virtual ~CDr1_2LabelView();
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

#ifndef _DEBUG  // Dr1_2LabelView.cpp �̃f�o�b�O �o�[�W����
inline CDr1_2LabelDoc* CDr1_2LabelView::GetDocument() const
   { return reinterpret_cast<CDr1_2LabelDoc*>(m_pDocument); }
#endif

