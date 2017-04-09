// rei54View.h : Crei54View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class Crei54View : public CFormView
{
protected: // シリアル化からのみ作成します。
	Crei54View();
	DECLARE_DYNCREATE(Crei54View)

public:
	enum{ IDD = IDD_REI54_FORM };

// 属性
public:
	Crei54Doc* GetDocument() const;

// 操作
public:

// オーバーライド
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV サポート
	virtual void OnInitialUpdate(); // 構築後に初めて呼び出されます。

// 実装
public:
	virtual ~Crei54View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CStatic pict;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // rei54View.cpp のデバッグ バージョン
inline Crei54Doc* Crei54View::GetDocument() const
   { return reinterpret_cast<Crei54Doc*>(m_pDocument); }
#endif

