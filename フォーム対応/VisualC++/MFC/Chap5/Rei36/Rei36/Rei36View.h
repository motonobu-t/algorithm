// Rei36View.h : CRei36View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei36View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei36View();
	DECLARE_DYNCREATE(CRei36View)

public:
	enum{ IDD = IDD_REI36_FORM };

// 属性
public:
	CRei36Doc* GetDocument() const;

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
	virtual ~CRei36View();
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
	CEdit text2;
	CEdit text3;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};

#ifndef _DEBUG  // Rei36View.cpp のデバッグ バージョン
inline CRei36Doc* CRei36View::GetDocument() const
   { return reinterpret_cast<CRei36Doc*>(m_pDocument); }
#endif

