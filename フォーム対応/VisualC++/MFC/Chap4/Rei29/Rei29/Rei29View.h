// Rei29View.h : CRei29View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei29View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei29View();
	DECLARE_DYNCREATE(CRei29View)

public:
	enum{ IDD = IDD_REI29_FORM };

// 属性
public:
	CRei29Doc* GetDocument() const;

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
	virtual ~CRei29View();
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
	CEdit text1;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // Rei29View.cpp のデバッグ バージョン
inline CRei29Doc* CRei29View::GetDocument() const
   { return reinterpret_cast<CRei29Doc*>(m_pDocument); }
#endif

