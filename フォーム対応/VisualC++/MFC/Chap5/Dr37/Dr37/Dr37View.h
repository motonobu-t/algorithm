// Dr37View.h : CDr37View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr37View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr37View();
	DECLARE_DYNCREATE(CDr37View)

public:
	enum{ IDD = IDD_DR37_FORM };

// 属性
public:
	CDr37Doc* GetDocument() const;

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
	virtual ~CDr37View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CEdit text1;
	CEdit text2;
	CStatic pict;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // Dr37View.cpp のデバッグ バージョン
inline CDr37Doc* CDr37View::GetDocument() const
   { return reinterpret_cast<CDr37Doc*>(m_pDocument); }
#endif

