// Dr9View.h : CDr9View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr9View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr9View();
	DECLARE_DYNCREATE(CDr9View)

public:
	enum{ IDD = IDD_DR9_FORM };

// 属性
public:
	CDr9Doc* GetDocument() const;

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
	virtual ~CDr9View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CEdit text1;
	CEdit text2;
	afx_msg void OnBnClickedButton1();
	CStatic pict;
};

#ifndef _DEBUG  // Dr9View.cpp のデバッグ バージョン
inline CDr9Doc* CDr9View::GetDocument() const
   { return reinterpret_cast<CDr9Doc*>(m_pDocument); }
#endif

