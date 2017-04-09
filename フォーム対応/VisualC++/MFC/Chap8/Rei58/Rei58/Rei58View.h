// Rei58View.h : CRei58View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei58View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei58View();
	DECLARE_DYNCREATE(CRei58View)

public:
	enum{ IDD = IDD_REI58_FORM };

// 属性
public:
	CRei58Doc* GetDocument() const;

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
	virtual ~CRei58View();
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

#ifndef _DEBUG  // Rei58View.cpp のデバッグ バージョン
inline CRei58Doc* CRei58View::GetDocument() const
   { return reinterpret_cast<CRei58Doc*>(m_pDocument); }
#endif

