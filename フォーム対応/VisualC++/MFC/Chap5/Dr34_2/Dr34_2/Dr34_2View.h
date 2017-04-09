// Dr34_2View.h : CDr34_2View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr34_2View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr34_2View();
	DECLARE_DYNCREATE(CDr34_2View)

public:
	enum{ IDD = IDD_DR34_2_FORM };

// 属性
public:
	CDr34_2Doc* GetDocument() const;

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
	virtual ~CDr34_2View();
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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
//	afx_msg void OnActivate(UINT nState, CWnd* pWndOther, BOOL bMinimized);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // Dr34_2View.cpp のデバッグ バージョン
inline CDr34_2Doc* CDr34_2View::GetDocument() const
   { return reinterpret_cast<CDr34_2Doc*>(m_pDocument); }
#endif

