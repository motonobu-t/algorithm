// Dr63_2View.h : CDr63_2View �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr63_2View : public CView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr63_2View();
	DECLARE_DYNCREATE(CDr63_2View)

// ����
public:
	CDr63_2Doc* GetDocument() const;

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
	virtual ~CDr63_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Dr63_2View.cpp �̃f�o�b�O �o�[�W����
inline CDr63_2Doc* CDr63_2View::GetDocument() const
   { return reinterpret_cast<CDr63_2Doc*>(m_pDocument); }
#endif

