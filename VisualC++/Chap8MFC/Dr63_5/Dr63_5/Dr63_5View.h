// Dr63_5View.h : CDr63_5View クラスのインターフェイス
//


#pragma once


class CDr63_5View : public CView
{
protected: // シリアル化からのみ作成します。
	CDr63_5View();
	DECLARE_DYNCREATE(CDr63_5View)

// 属性
public:
	CDr63_5Doc* GetDocument() const;

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
	virtual ~CDr63_5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Dr63_5View.cpp のデバッグ バージョン
inline CDr63_5Doc* CDr63_5View::GetDocument() const
   { return reinterpret_cast<CDr63_5Doc*>(m_pDocument); }
#endif

