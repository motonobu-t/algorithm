// Dr17MFCView.h : CDr17MFCView �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr17MFCView : public CView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr17MFCView();
	DECLARE_DYNCREATE(CDr17MFCView)

// ����
public:
	CDr17MFCDoc* GetDocument() const;

// ����
public:

// �I�[�o�[���C�h
public:
	virtual void OnDraw(CDC* pDC);  // ���̃r���[��`�悷�邽�߂ɃI�[�o�[���C�h����܂��B
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ����
public:
	virtual ~CDr17MFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Dr17MFCView.cpp �̃f�o�b�O �o�[�W����
inline CDr17MFCDoc* CDr17MFCView::GetDocument() const
   { return reinterpret_cast<CDr17MFCDoc*>(m_pDocument); }
#endif

