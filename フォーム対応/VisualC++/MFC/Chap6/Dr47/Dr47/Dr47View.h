// Dr47View.h : CDr47View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr47View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr47View();
	DECLARE_DYNCREATE(CDr47View)

public:
	enum{ IDD = IDD_DR47_FORM };

// 属性
public:
	CDr47Doc* GetDocument() const;

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
	virtual ~CDr47View();
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

#ifndef _DEBUG  // Dr47View.cpp のデバッグ バージョン
inline CDr47Doc* CDr47View::GetDocument() const
   { return reinterpret_cast<CDr47Doc*>(m_pDocument); }
#endif

