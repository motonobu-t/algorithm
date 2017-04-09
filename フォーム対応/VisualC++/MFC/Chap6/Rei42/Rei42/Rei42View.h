// Rei42View.h : CRei42View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei42View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei42View();
	DECLARE_DYNCREATE(CRei42View)

public:
	enum{ IDD = IDD_REI42_FORM };

// 属性
public:
	CRei42Doc* GetDocument() const;

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
	virtual ~CRei42View();
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

#ifndef _DEBUG  // Rei42View.cpp のデバッグ バージョン
inline CRei42Doc* CRei42View::GetDocument() const
   { return reinterpret_cast<CRei42Doc*>(m_pDocument); }
#endif

