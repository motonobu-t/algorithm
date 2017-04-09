// Dr29View.h : CDr29View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr29View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr29View();
	DECLARE_DYNCREATE(CDr29View)

public:
	enum{ IDD = IDD_DR29_FORM };

// 属性
public:
	CDr29Doc* GetDocument() const;

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
	virtual ~CDr29View();
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

#ifndef _DEBUG  // Dr29View.cpp のデバッグ バージョン
inline CDr29Doc* CDr29View::GetDocument() const
   { return reinterpret_cast<CDr29Doc*>(m_pDocument); }
#endif

