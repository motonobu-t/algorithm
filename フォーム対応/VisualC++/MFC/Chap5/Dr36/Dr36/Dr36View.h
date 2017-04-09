// Dr36View.h : CDr36View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr36View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr36View();
	DECLARE_DYNCREATE(CDr36View)

public:
	enum{ IDD = IDD_DR36_FORM };

// 属性
public:
	CDr36Doc* GetDocument() const;

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
	virtual ~CDr36View();
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
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnBnClickedButton4();
};

#ifndef _DEBUG  // Dr36View.cpp のデバッグ バージョン
inline CDr36Doc* CDr36View::GetDocument() const
   { return reinterpret_cast<CDr36Doc*>(m_pDocument); }
#endif

