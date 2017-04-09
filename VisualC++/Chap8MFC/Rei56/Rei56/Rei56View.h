// Rei56View.h : CRei56View クラスのインターフェイス
//


#pragma once


class CRei56View : public CView
{
protected: // シリアル化からのみ作成します。
	CRei56View();
	DECLARE_DYNCREATE(CRei56View)

// 属性
public:
	CRei56Doc* GetDocument() const;

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
	virtual ~CRei56View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Rei56View.cpp のデバッグ バージョン
inline CRei56Doc* CRei56View::GetDocument() const
   { return reinterpret_cast<CRei56Doc*>(m_pDocument); }
#endif

