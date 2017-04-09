// Rei57View.h : CRei57View クラスのインターフェイス
//


#pragma once


class CRei57View : public CView
{
protected: // シリアル化からのみ作成します。
	CRei57View();
	DECLARE_DYNCREATE(CRei57View)

// 属性
public:
	CRei57Doc* GetDocument() const;

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
	virtual ~CRei57View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Rei57View.cpp のデバッグ バージョン
inline CRei57Doc* CRei57View::GetDocument() const
   { return reinterpret_cast<CRei57Doc*>(m_pDocument); }
#endif

