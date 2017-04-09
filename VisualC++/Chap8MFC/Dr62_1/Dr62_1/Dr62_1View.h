// Dr62_1View.h : CDr62_1View クラスのインターフェイス
//


#pragma once


class CDr62_1View : public CView
{
protected: // シリアル化からのみ作成します。
	CDr62_1View();
	DECLARE_DYNCREATE(CDr62_1View)

// 属性
public:
	CDr62_1Doc* GetDocument() const;

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
	virtual ~CDr62_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Dr62_1View.cpp のデバッグ バージョン
inline CDr62_1Doc* CDr62_1View::GetDocument() const
   { return reinterpret_cast<CDr62_1Doc*>(m_pDocument); }
#endif

