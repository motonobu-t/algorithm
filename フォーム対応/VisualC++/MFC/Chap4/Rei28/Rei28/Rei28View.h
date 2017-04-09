// Rei28View.h : CRei28View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei28View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei28View();
	DECLARE_DYNCREATE(CRei28View)

public:
	enum{ IDD = IDD_REI28_FORM };

// 属性
public:
	CRei28Doc* GetDocument() const;

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
	virtual ~CRei28View();
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
};

#ifndef _DEBUG  // Rei28View.cpp のデバッグ バージョン
inline CRei28Doc* CRei28View::GetDocument() const
   { return reinterpret_cast<CRei28Doc*>(m_pDocument); }
#endif

