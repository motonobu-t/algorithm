// Rei38View.h : CRei38View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei38View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei38View();
	DECLARE_DYNCREATE(CRei38View)

public:
	enum{ IDD = IDD_REI38_FORM };

// 属性
public:
	CRei38Doc* GetDocument() const;

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
	virtual ~CRei38View();
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

#ifndef _DEBUG  // Rei38View.cpp のデバッグ バージョン
inline CRei38Doc* CRei38View::GetDocument() const
   { return reinterpret_cast<CRei38Doc*>(m_pDocument); }
#endif

