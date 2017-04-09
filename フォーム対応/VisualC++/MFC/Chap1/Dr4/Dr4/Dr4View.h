// Dr4View.h : CDr4View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr4View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr4View();
	DECLARE_DYNCREATE(CDr4View)

public:
	enum{ IDD = IDD_DR4_FORM };

// 属性
public:
	CDr4Doc* GetDocument() const;

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
	virtual ~CDr4View();
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

#ifndef _DEBUG  // Dr4View.cpp のデバッグ バージョン
inline CDr4Doc* CDr4View::GetDocument() const
   { return reinterpret_cast<CDr4Doc*>(m_pDocument); }
#endif

