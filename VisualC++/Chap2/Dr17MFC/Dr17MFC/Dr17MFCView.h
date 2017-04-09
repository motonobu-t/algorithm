// Dr17MFCView.h : CDr17MFCView クラスのインターフェイス
//


#pragma once


class CDr17MFCView : public CView
{
protected: // シリアル化からのみ作成します。
	CDr17MFCView();
	DECLARE_DYNCREATE(CDr17MFCView)

// 属性
public:
	CDr17MFCDoc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual void OnDraw(CDC* pDC);  // このビューを描画するためにオーバーライドされます。
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 実装
public:
	virtual ~CDr17MFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Dr17MFCView.cpp のデバッグ バージョン
inline CDr17MFCDoc* CDr17MFCView::GetDocument() const
   { return reinterpret_cast<CDr17MFCDoc*>(m_pDocument); }
#endif

