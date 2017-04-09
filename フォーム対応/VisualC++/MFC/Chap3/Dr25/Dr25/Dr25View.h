// Dr25View.h : CDr25View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr25View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr25View();
	DECLARE_DYNCREATE(CDr25View)

public:
	enum{ IDD = IDD_DR25_FORM };

// 属性
public:
	CDr25Doc* GetDocument() const;

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
	virtual ~CDr25View();
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
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	CEdit text1;
	CEdit text2;
	CEdit text3;
};

#ifndef _DEBUG  // Dr25View.cpp のデバッグ バージョン
inline CDr25Doc* CDr25View::GetDocument() const
   { return reinterpret_cast<CDr25Doc*>(m_pDocument); }
#endif

