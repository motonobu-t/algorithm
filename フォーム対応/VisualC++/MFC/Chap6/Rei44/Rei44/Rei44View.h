// Rei44View.h : CRei44View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei44View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei44View();
	DECLARE_DYNCREATE(CRei44View)

public:
	enum{ IDD = IDD_REI44_FORM };

// 属性
public:
	CRei44Doc* GetDocument() const;

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
	virtual ~CRei44View();
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

#ifndef _DEBUG  // Rei44View.cpp のデバッグ バージョン
inline CRei44Doc* CRei44View::GetDocument() const
   { return reinterpret_cast<CRei44Doc*>(m_pDocument); }
#endif

