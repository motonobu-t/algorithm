// Rei2View.h : CRei2View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei2View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei2View();
	DECLARE_DYNCREATE(CRei2View)

public:
	enum{ IDD = IDD_REI2_FORM };

// 属性
public:
	CRei2Doc* GetDocument() const;

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
	virtual ~CRei2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CStatic pict;
};

#ifndef _DEBUG  // Rei2View.cpp のデバッグ バージョン
inline CRei2Doc* CRei2View::GetDocument() const
   { return reinterpret_cast<CRei2Doc*>(m_pDocument); }
#endif

