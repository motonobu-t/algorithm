// Rei35View.h : CRei35View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei35View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei35View();
	DECLARE_DYNCREATE(CRei35View)

public:
	enum{ IDD = IDD_REI35_FORM };

// 属性
public:
	CRei35Doc* GetDocument() const;

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
	virtual ~CRei35View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	CStatic pict;
	CEdit text1;
	CEdit text2;
	CEdit text3;
};

#ifndef _DEBUG  // Rei35View.cpp のデバッグ バージョン
inline CRei35Doc* CRei35View::GetDocument() const
   { return reinterpret_cast<CRei35Doc*>(m_pDocument); }
#endif

