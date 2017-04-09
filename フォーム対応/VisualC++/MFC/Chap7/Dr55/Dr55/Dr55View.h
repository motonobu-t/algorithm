// Dr55View.h : CDr55View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr55View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr55View();
	DECLARE_DYNCREATE(CDr55View)

public:
	enum{ IDD = IDD_DR55_FORM };

// 属性
public:
	CDr55Doc* GetDocument() const;

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
	virtual ~CDr55View();
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

#ifndef _DEBUG  // Dr55View.cpp のデバッグ バージョン
inline CDr55Doc* CDr55View::GetDocument() const
   { return reinterpret_cast<CDr55Doc*>(m_pDocument); }
#endif

