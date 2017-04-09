// Rei57View.h : CRei57View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei57View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei57View();
	DECLARE_DYNCREATE(CRei57View)

public:
	enum{ IDD = IDD_REI57_FORM };

// 属性
public:
	CRei57Doc* GetDocument() const;

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
	virtual ~CRei57View();
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

#ifndef _DEBUG  // Rei57View.cpp のデバッグ バージョン
inline CRei57Doc* CRei57View::GetDocument() const
   { return reinterpret_cast<CRei57Doc*>(m_pDocument); }
#endif

