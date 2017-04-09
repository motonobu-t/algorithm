// Dr62_2View.h : CDr62_2View クラスのインターフェイス
//


#pragma once


class CDr62_2View : public CView
{
protected: // シリアル化からのみ作成します。
	CDr62_2View();
	DECLARE_DYNCREATE(CDr62_2View)

// 属性
public:
	CDr62_2Doc* GetDocument() const;

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
	virtual ~CDr62_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Dr62_2View.cpp のデバッグ バージョン
inline CDr62_2Doc* CDr62_2View::GetDocument() const
   { return reinterpret_cast<CDr62_2Doc*>(m_pDocument); }
#endif

