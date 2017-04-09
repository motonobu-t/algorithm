// rei52View.h : Crei52View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class Crei52View : public CFormView
{
protected: // シリアル化からのみ作成します。
	Crei52View();
	DECLARE_DYNCREATE(Crei52View)

public:
	enum{ IDD = IDD_REI52_FORM };

// 属性
public:
	Crei52Doc* GetDocument() const;

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
	virtual ~Crei52View();
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

#ifndef _DEBUG  // rei52View.cpp のデバッグ バージョン
inline Crei52Doc* Crei52View::GetDocument() const
   { return reinterpret_cast<Crei52Doc*>(m_pDocument); }
#endif

