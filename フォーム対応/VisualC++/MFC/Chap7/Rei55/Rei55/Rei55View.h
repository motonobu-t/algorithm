// Rei55View.h : CRei55View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei55View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei55View();
	DECLARE_DYNCREATE(CRei55View)

public:
	enum{ IDD = IDD_REI55_FORM };

// 属性
public:
	CRei55Doc* GetDocument() const;

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
	virtual ~CRei55View();
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
	CEdit text1;
};

#ifndef _DEBUG  // Rei55View.cpp のデバッグ バージョン
inline CRei55Doc* CRei55View::GetDocument() const
   { return reinterpret_cast<CRei55Doc*>(m_pDocument); }
#endif

