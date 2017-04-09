// Dr20_1View.h : CDr20_1View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr20_1View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr20_1View();
	DECLARE_DYNCREATE(CDr20_1View)

public:
	enum{ IDD = IDD_DR20_1_FORM };

// 属性
public:
	CDr20_1Doc* GetDocument() const;

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
	virtual ~CDr20_1View();
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
	CEdit text1;
	afx_msg void OnBnClickedButton1();
//	afx_msg void OnStnClickedPict();
};

#ifndef _DEBUG  // Dr20_1View.cpp のデバッグ バージョン
inline CDr20_1Doc* CDr20_1View::GetDocument() const
   { return reinterpret_cast<CDr20_1Doc*>(m_pDocument); }
#endif

