// Rei9View.h : CRei9View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei9View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei9View();
	DECLARE_DYNCREATE(CRei9View)

public:
	enum{ IDD = IDD_REI9_FORM };

// 属性
public:
	CRei9Doc* GetDocument() const;

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
	virtual ~CRei9View();
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
	CEdit text1;
	CEdit text2;
	CStatic pict;
};

#ifndef _DEBUG  // Rei9View.cpp のデバッグ バージョン
inline CRei9Doc* CRei9View::GetDocument() const
   { return reinterpret_cast<CRei9Doc*>(m_pDocument); }
#endif

