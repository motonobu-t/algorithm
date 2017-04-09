// Rei66ListBoxView.h : CRei66ListBoxView クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei66ListBoxView : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei66ListBoxView();
	DECLARE_DYNCREATE(CRei66ListBoxView)

public:
	enum{ IDD = IDD_REI66LISTBOX_FORM };

// 属性
public:
	CRei66ListBoxDoc* GetDocument() const;

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
	virtual ~CRei66ListBoxView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CListBox m_list1;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // Rei66ListBoxView.cpp のデバッグ バージョン
inline CRei66ListBoxDoc* CRei66ListBoxView::GetDocument() const
   { return reinterpret_cast<CRei66ListBoxDoc*>(m_pDocument); }
#endif

