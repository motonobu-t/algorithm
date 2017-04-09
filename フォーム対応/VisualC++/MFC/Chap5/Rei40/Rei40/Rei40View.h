// Rei40View.h : CRei40View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei40View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei40View();
	DECLARE_DYNCREATE(CRei40View)

public:
	enum{ IDD = IDD_REI40_FORM };

// 属性
public:
	CRei40Doc* GetDocument() const;

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
	virtual ~CRei40View();
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
};

#ifndef _DEBUG  // Rei40View.cpp のデバッグ バージョン
inline CRei40Doc* CRei40View::GetDocument() const
   { return reinterpret_cast<CRei40Doc*>(m_pDocument); }
#endif

