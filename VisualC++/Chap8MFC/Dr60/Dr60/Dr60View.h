// Dr60View.h : CDr60View クラスのインターフェイス
//


#pragma once


class CDr60View : public CView
{
protected: // シリアル化からのみ作成します。
	CDr60View();
	DECLARE_DYNCREATE(CDr60View)

// 属性
public:
	CDr60Doc* GetDocument() const;

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
	virtual ~CDr60View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Dr60View.cpp のデバッグ バージョン
inline CDr60Doc* CDr60View::GetDocument() const
   { return reinterpret_cast<CDr60Doc*>(m_pDocument); }
#endif

