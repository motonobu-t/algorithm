// Dr43View.h : CDr43View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr43View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr43View();
	DECLARE_DYNCREATE(CDr43View)

public:
	enum{ IDD = IDD_DR43_FORM };

// 属性
public:
	CDr43Doc* GetDocument() const;

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
	virtual ~CDr43View();
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
};

#ifndef _DEBUG  // Dr43View.cpp のデバッグ バージョン
inline CDr43Doc* CDr43View::GetDocument() const
   { return reinterpret_cast<CDr43Doc*>(m_pDocument); }
#endif

