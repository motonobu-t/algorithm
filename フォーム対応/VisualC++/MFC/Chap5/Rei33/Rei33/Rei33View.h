// Rei33View.h : CRei33View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei33View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei33View();
	DECLARE_DYNCREATE(CRei33View)

public:
	enum{ IDD = IDD_REI33_FORM };

// 属性
public:
	CRei33Doc* GetDocument() const;

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
	virtual ~CRei33View();
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

#ifndef _DEBUG  // Rei33View.cpp のデバッグ バージョン
inline CRei33Doc* CRei33View::GetDocument() const
   { return reinterpret_cast<CRei33Doc*>(m_pDocument); }
#endif

