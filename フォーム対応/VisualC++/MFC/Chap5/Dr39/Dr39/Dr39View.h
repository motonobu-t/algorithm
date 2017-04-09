// Dr39View.h : CDr39View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr39View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr39View();
	DECLARE_DYNCREATE(CDr39View)

public:
	enum{ IDD = IDD_DR39_FORM };

// 属性
public:
	CDr39Doc* GetDocument() const;

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
	virtual ~CDr39View();
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

#ifndef _DEBUG  // Dr39View.cpp のデバッグ バージョン
inline CDr39Doc* CDr39View::GetDocument() const
   { return reinterpret_cast<CDr39Doc*>(m_pDocument); }
#endif

