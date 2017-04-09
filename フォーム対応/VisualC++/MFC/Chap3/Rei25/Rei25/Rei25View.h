// Rei25View.h : CRei25View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei25View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei25View();
	DECLARE_DYNCREATE(CRei25View)

public:
	enum{ IDD = IDD_REI25_FORM };

// 属性
public:
	CRei25Doc* GetDocument() const;

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
	virtual ~CRei25View();
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
};

#ifndef _DEBUG  // Rei25View.cpp のデバッグ バージョン
inline CRei25Doc* CRei25View::GetDocument() const
   { return reinterpret_cast<CRei25Doc*>(m_pDocument); }
#endif

