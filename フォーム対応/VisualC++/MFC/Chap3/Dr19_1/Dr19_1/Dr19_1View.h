// Dr19_1View.h : CDr19_1View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr19_1View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr19_1View();
	DECLARE_DYNCREATE(CDr19_1View)

public:
	enum{ IDD = IDD_DR19_1_FORM };

// 属性
public:
	CDr19_1Doc* GetDocument() const;

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
	virtual ~CDr19_1View();
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

#ifndef _DEBUG  // Dr19_1View.cpp のデバッグ バージョン
inline CDr19_1Doc* CDr19_1View::GetDocument() const
   { return reinterpret_cast<CDr19_1Doc*>(m_pDocument); }
#endif

