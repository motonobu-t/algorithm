// Rei61View.h : CRei61View クラスのインターフェイス
//


#pragma once


class CRei61View : public CView
{
protected: // シリアル化からのみ作成します。
	CRei61View();
	DECLARE_DYNCREATE(CRei61View)

// 属性
public:
	CRei61Doc* GetDocument() const;

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
	virtual ~CRei61View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Rei61View.cpp のデバッグ バージョン
inline CRei61Doc* CRei61View::GetDocument() const
   { return reinterpret_cast<CRei61Doc*>(m_pDocument); }
#endif

