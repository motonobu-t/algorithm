// Dr58View.h : CDr58View クラスのインターフェイス
//


#pragma once


class CDr58View : public CView
{
protected: // シリアル化からのみ作成します。
	CDr58View();
	DECLARE_DYNCREATE(CDr58View)

// 属性
public:
	CDr58Doc* GetDocument() const;

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
	virtual ~CDr58View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Dr58View.cpp のデバッグ バージョン
inline CDr58Doc* CDr58View::GetDocument() const
   { return reinterpret_cast<CDr58Doc*>(m_pDocument); }
#endif

