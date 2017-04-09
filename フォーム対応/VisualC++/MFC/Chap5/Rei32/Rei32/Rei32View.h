// Rei32View.h : CRei32View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei32View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei32View();
	DECLARE_DYNCREATE(CRei32View)

public:
	enum{ IDD = IDD_REI32_FORM };

// 属性
public:
	CRei32Doc* GetDocument() const;

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
	virtual ~CRei32View();
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

#ifndef _DEBUG  // Rei32View.cpp のデバッグ バージョン
inline CRei32Doc* CRei32View::GetDocument() const
   { return reinterpret_cast<CRei32Doc*>(m_pDocument); }
#endif

