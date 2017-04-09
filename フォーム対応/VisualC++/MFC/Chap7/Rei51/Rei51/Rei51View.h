// Rei51View.h : CRei51View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei51View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei51View();
	DECLARE_DYNCREATE(CRei51View)

public:
	enum{ IDD = IDD_REI51_FORM };

// 属性
public:
	CRei51Doc* GetDocument() const;

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
	virtual ~CRei51View();
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
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // Rei51View.cpp のデバッグ バージョン
inline CRei51Doc* CRei51View::GetDocument() const
   { return reinterpret_cast<CRei51Doc*>(m_pDocument); }
#endif

