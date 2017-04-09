// Dr13View.h : CDr13View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr13View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr13View();
	DECLARE_DYNCREATE(CDr13View)

public:
	enum{ IDD = IDD_DR13_FORM };

// 属性
public:
	CDr13Doc* GetDocument() const;

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
	virtual ~CDr13View();
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

#ifndef _DEBUG  // Dr13View.cpp のデバッグ バージョン
inline CDr13Doc* CDr13View::GetDocument() const
   { return reinterpret_cast<CDr13Doc*>(m_pDocument); }
#endif

