// Dr66ListBoxView.h : CDr66ListBoxView �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr66ListBoxView : public CFormView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr66ListBoxView();
	DECLARE_DYNCREATE(CDr66ListBoxView)

public:
	enum{ IDD = IDD_DR66LISTBOX_FORM };

// ����
public:
	CDr66ListBoxDoc* GetDocument() const;

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
	virtual ~CDr66ListBoxView();
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

#ifndef _DEBUG  // Dr66ListBoxView.cpp �̃f�o�b�O �o�[�W����
inline CDr66ListBoxDoc* CDr66ListBoxView::GetDocument() const
   { return reinterpret_cast<CDr66ListBoxDoc*>(m_pDocument); }
#endif

