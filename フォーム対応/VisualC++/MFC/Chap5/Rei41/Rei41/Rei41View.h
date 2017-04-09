// Rei41View.h : CRei41View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei41View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei41View();
	DECLARE_DYNCREATE(CRei41View)

public:
	enum{ IDD = IDD_REI41_FORM };

// 属性
public:
	CRei41Doc* GetDocument() const;

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
	virtual ~CRei41View();
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
	CEdit text3;
	CStatic pict;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
};

#ifndef _DEBUG  // Rei41View.cpp のデバッグ バージョン
inline CRei41Doc* CRei41View::GetDocument() const
   { return reinterpret_cast<CRei41Doc*>(m_pDocument); }
#endif

