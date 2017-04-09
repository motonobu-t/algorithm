// Rei34View.h : CRei34View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei34View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei34View();
	DECLARE_DYNCREATE(CRei34View)

public:
	enum{ IDD = IDD_REI34_FORM };

// 属性
public:
	CRei34Doc* GetDocument() const;

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
	virtual ~CRei34View();
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
	CEdit text2;
};

#ifndef _DEBUG  // Rei34View.cpp のデバッグ バージョン
inline CRei34Doc* CRei34View::GetDocument() const
   { return reinterpret_cast<CRei34Doc*>(m_pDocument); }
#endif

