// Rei15View.h : CRei15View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei15View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei15View();
	DECLARE_DYNCREATE(CRei15View)

public:
	enum{ IDD = IDD_REI15_FORM };

// 属性
public:
	CRei15Doc* GetDocument() const;

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
	virtual ~CRei15View();
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

#ifndef _DEBUG  // Rei15View.cpp のデバッグ バージョン
inline CRei15Doc* CRei15View::GetDocument() const
   { return reinterpret_cast<CRei15Doc*>(m_pDocument); }
#endif

