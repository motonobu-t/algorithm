// Rei56View.h : CRei56View �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CRei56View : public CView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei56View();
	DECLARE_DYNCREATE(CRei56View)

// ����
public:
	CRei56Doc* GetDocument() const;

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
	virtual ~CRei56View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Rei56View.cpp �̃f�o�b�O �o�[�W����
inline CRei56Doc* CRei56View::GetDocument() const
   { return reinterpret_cast<CRei56Doc*>(m_pDocument); }
#endif

