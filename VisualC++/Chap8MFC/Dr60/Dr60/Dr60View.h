// Dr60View.h : CDr60View �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr60View : public CView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr60View();
	DECLARE_DYNCREATE(CDr60View)

// ����
public:
	CDr60Doc* GetDocument() const;

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
	virtual ~CDr60View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Dr60View.cpp �̃f�o�b�O �o�[�W����
inline CDr60Doc* CDr60View::GetDocument() const
   { return reinterpret_cast<CDr60Doc*>(m_pDocument); }
#endif

