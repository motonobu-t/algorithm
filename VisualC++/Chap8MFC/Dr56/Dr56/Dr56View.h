// Dr56View.h : CDr56View クラスのインターフェイス
//


#pragma once


class CDr56View : public CView
{
protected: // シリアル化からのみ作成します。
	CDr56View();
	DECLARE_DYNCREATE(CDr56View)

// 属性
public:
	CDr56Doc* GetDocument() const;

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
	virtual ~CDr56View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Dr56View.cpp のデバッグ バージョン
inline CDr56Doc* CDr56View::GetDocument() const
   { return reinterpret_cast<CDr56Doc*>(m_pDocument); }
#endif

