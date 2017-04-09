// Rei18View.h : CRei18View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei18View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei18View();
	DECLARE_DYNCREATE(CRei18View)

public:
	enum{ IDD = IDD_REI18_FORM };

// 属性
public:
	CRei18Doc* GetDocument() const;

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
	virtual ~CRei18View();
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
};

#ifndef _DEBUG  // Rei18View.cpp のデバッグ バージョン
inline CRei18Doc* CRei18View::GetDocument() const
   { return reinterpret_cast<CRei18Doc*>(m_pDocument); }
#endif

