// Rei61View.h : CRei61View �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CRei61View : public CView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei61View();
	DECLARE_DYNCREATE(CRei61View)

// ����
public:
	CRei61Doc* GetDocument() const;

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
	virtual ~CRei61View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Rei61View.cpp �̃f�o�b�O �o�[�W����
inline CRei61Doc* CRei61View::GetDocument() const
   { return reinterpret_cast<CRei61Doc*>(m_pDocument); }
#endif

