// Dr35_1View.h : CDr35_1View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr35_1View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr35_1View();
	DECLARE_DYNCREATE(CDr35_1View)

public:
	enum{ IDD = IDD_DR35_1_FORM };

// 属性
public:
	CDr35_1Doc* GetDocument() const;

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
	virtual ~CDr35_1View();
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
	CEdit text2;
	CEdit text3;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};

#ifndef _DEBUG  // Dr35_1View.cpp のデバッグ バージョン
inline CDr35_1Doc* CDr35_1View::GetDocument() const
   { return reinterpret_cast<CDr35_1Doc*>(m_pDocument); }
#endif

