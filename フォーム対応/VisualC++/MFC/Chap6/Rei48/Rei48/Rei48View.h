// Rei48View.h : CRei48View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei48View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei48View();
	DECLARE_DYNCREATE(CRei48View)

public:
	enum{ IDD = IDD_REI48_FORM };

// 属性
public:
	CRei48Doc* GetDocument() const;

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
	virtual ~CRei48View();
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
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // Rei48View.cpp のデバッグ バージョン
inline CRei48Doc* CRei48View::GetDocument() const
   { return reinterpret_cast<CRei48Doc*>(m_pDocument); }
#endif

