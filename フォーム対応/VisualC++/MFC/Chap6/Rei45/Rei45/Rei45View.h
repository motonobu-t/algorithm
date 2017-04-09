// Rei45View.h : CRei45View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei45View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei45View();
	DECLARE_DYNCREATE(CRei45View)

public:
	enum{ IDD = IDD_REI45_FORM };

// 属性
public:
	CRei45Doc* GetDocument() const;

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
	virtual ~CRei45View();
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

#ifndef _DEBUG  // Rei45View.cpp のデバッグ バージョン
inline CRei45Doc* CRei45View::GetDocument() const
   { return reinterpret_cast<CRei45Doc*>(m_pDocument); }
#endif

