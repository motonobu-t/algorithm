// Dr63_4View.h : CDr63_4View クラスのインターフェイス
//


#pragma once


class CDr63_4View : public CView
{
protected: // シリアル化からのみ作成します。
	CDr63_4View();
	DECLARE_DYNCREATE(CDr63_4View)

// 属性
public:
	CDr63_4Doc* GetDocument() const;

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
	virtual ~CDr63_4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Dr63_4View.cpp のデバッグ バージョン
inline CDr63_4Doc* CDr63_4View::GetDocument() const
   { return reinterpret_cast<CDr63_4Doc*>(m_pDocument); }
#endif

