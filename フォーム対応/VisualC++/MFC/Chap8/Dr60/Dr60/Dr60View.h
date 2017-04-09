// Dr60View.h : CDr60View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr60View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr60View();
	DECLARE_DYNCREATE(CDr60View)

public:
	enum{ IDD = IDD_DR60_FORM };

// 属性
public:
	CDr60Doc* GetDocument() const;

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
	virtual ~CDr60View();
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

#ifndef _DEBUG  // Dr60View.cpp のデバッグ バージョン
inline CDr60Doc* CDr60View::GetDocument() const
   { return reinterpret_cast<CDr60Doc*>(m_pDocument); }
#endif

