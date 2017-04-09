// Rei43View.h : CRei43View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei43View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei43View();
	DECLARE_DYNCREATE(CRei43View)

public:
	enum{ IDD = IDD_REI43_FORM };

// 属性
public:
	CRei43Doc* GetDocument() const;

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
	virtual ~CRei43View();
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
};

#ifndef _DEBUG  // Rei43View.cpp のデバッグ バージョン
inline CRei43Doc* CRei43View::GetDocument() const
   { return reinterpret_cast<CRei43Doc*>(m_pDocument); }
#endif

