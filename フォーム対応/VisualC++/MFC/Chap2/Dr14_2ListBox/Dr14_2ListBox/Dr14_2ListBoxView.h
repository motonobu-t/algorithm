// Dr14_2ListBoxView.h : CDr14_2ListBoxView クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr14_2ListBoxView : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr14_2ListBoxView();
	DECLARE_DYNCREATE(CDr14_2ListBoxView)

public:
	enum{ IDD = IDD_DR14_2LISTBOX_FORM };

// 属性
public:
	CDr14_2ListBoxDoc* GetDocument() const;

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
	virtual ~CDr14_2ListBoxView();
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

#ifndef _DEBUG  // Dr14_2ListBoxView.cpp のデバッグ バージョン
inline CDr14_2ListBoxDoc* CDr14_2ListBoxView::GetDocument() const
   { return reinterpret_cast<CDr14_2ListBoxDoc*>(m_pDocument); }
#endif

