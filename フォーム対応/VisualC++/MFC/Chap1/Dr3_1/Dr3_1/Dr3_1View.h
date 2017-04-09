// Dr3_1View.h : CDr3_1View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr3_1View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr3_1View();
	DECLARE_DYNCREATE(CDr3_1View)

public:
	enum{ IDD = IDD_DR3_1_FORM };

// 属性
public:
	CDr3_1Doc* GetDocument() const;

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
	virtual ~CDr3_1View();
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

#ifndef _DEBUG  // Dr3_1View.cpp のデバッグ バージョン
inline CDr3_1Doc* CDr3_1View::GetDocument() const
   { return reinterpret_cast<CDr3_1Doc*>(m_pDocument); }
#endif

