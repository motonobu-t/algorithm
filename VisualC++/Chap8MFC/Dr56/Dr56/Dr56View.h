// Dr56View.h : CDr56View �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr56View : public CView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr56View();
	DECLARE_DYNCREATE(CDr56View)

// ����
public:
	CDr56Doc* GetDocument() const;

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
	virtual ~CDr56View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Dr56View.cpp �̃f�o�b�O �o�[�W����
inline CDr56Doc* CDr56View::GetDocument() const
   { return reinterpret_cast<CDr56Doc*>(m_pDocument); }
#endif

