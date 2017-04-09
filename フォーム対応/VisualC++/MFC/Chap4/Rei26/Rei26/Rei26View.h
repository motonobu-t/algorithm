// Rei26View.h : CRei26View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei26View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei26View();
	DECLARE_DYNCREATE(CRei26View)

public:
	enum{ IDD = IDD_REI26_FORM };

// 属性
public:
	CRei26Doc* GetDocument() const;

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
	virtual ~CRei26View();
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

#ifndef _DEBUG  // Rei26View.cpp のデバッグ バージョン
inline CRei26Doc* CRei26View::GetDocument() const
   { return reinterpret_cast<CRei26Doc*>(m_pDocument); }
#endif

