// Dr61View.h : CDr61View �N���X�̃C���^�[�t�F�C�X
//


#pragma once


class CDr61View : public CView
{
protected: // �V���A��������̂ݍ쐬���܂��B
	CDr61View();
	DECLARE_DYNCREATE(CDr61View)

// ����
public:
	CDr61Doc* GetDocument() const;

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
	virtual ~CDr61View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// �������ꂽ�A���b�Z�[�W���蓖�Ċ֐�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Dr61View.cpp �̃f�o�b�O �o�[�W����
inline CDr61Doc* CDr61View::GetDocument() const
   { return reinterpret_cast<CDr61Doc*>(m_pDocument); }
#endif

