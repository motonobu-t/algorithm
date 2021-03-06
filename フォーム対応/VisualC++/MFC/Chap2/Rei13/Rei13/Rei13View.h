// Rei13View.h : CRei13View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei13View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei13View();
	DECLARE_DYNCREATE(CRei13View)

public:
	enum{ IDD = IDD_REI13_FORM };

// 属性
public:
	CRei13Doc* GetDocument() const;

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
	virtual ~CRei13View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CStatic pict;
//	afx_msg void OnStnClickedPict();
};

#ifndef _DEBUG  // Rei13View.cpp のデバッグ バージョン
inline CRei13Doc* CRei13View::GetDocument() const
   { return reinterpret_cast<CRei13Doc*>(m_pDocument); }
#endif

