// Rei63View.h : CRei63View クラスのインターフェイス
//


#pragma once


class CRei63View : public CView
{
protected: // シリアル化からのみ作成します。
	CRei63View();
	DECLARE_DYNCREATE(CRei63View)

// 属性
public:
	CRei63Doc* GetDocument() const;

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
	virtual ~CRei63View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // Rei63View.cpp のデバッグ バージョン
inline CRei63Doc* CRei63View::GetDocument() const
   { return reinterpret_cast<CRei63Doc*>(m_pDocument); }
#endif

