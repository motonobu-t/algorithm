// Dr52View.h : CDr52View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr52View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr52View();
	DECLARE_DYNCREATE(CDr52View)

public:
	enum{ IDD = IDD_DR52_FORM };

// 属性
public:
	CDr52Doc* GetDocument() const;

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
	virtual ~CDr52View();
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

#ifndef _DEBUG  // Dr52View.cpp のデバッグ バージョン
inline CDr52Doc* CDr52View::GetDocument() const
   { return reinterpret_cast<CDr52Doc*>(m_pDocument); }
#endif

