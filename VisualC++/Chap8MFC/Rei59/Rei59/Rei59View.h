// Rei59View.h : CRei59View �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CRei59View : public CView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CRei59View();
	DECLARE_DYNCREATE(CRei59View)

// ����
public:
	CRei59Doc* GetDocument() const;

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
	virtual ~CRei59View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Rei59View.cpp �̃f�o�b�O �o�[�W����
inline CRei59Doc* CRei59View::GetDocument() const
   { return reinterpret_cast<CRei59Doc*>(m_pDocument); }
#endif

