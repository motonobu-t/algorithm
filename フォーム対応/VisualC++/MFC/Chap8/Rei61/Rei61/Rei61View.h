// Rei61View.h : CRei61View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei61View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei61View();
	DECLARE_DYNCREATE(CRei61View)

public:
	enum{ IDD = IDD_REI61_FORM };

// 属性
public:
	CRei61Doc* GetDocument() const;

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
	virtual ~CRei61View();
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

#ifndef _DEBUG  // Rei61View.cpp のデバッグ バージョン
inline CRei61Doc* CRei61View::GetDocument() const
   { return reinterpret_cast<CRei61Doc*>(m_pDocument); }
#endif

