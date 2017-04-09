// Rei30View.h : CRei30View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei30View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei30View();
	DECLARE_DYNCREATE(CRei30View)

public:
	enum{ IDD = IDD_REI30_FORM };

// 属性
public:
	CRei30Doc* GetDocument() const;

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
	virtual ~CRei30View();
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

#ifndef _DEBUG  // Rei30View.cpp のデバッグ バージョン
inline CRei30Doc* CRei30View::GetDocument() const
   { return reinterpret_cast<CRei30Doc*>(m_pDocument); }
#endif

