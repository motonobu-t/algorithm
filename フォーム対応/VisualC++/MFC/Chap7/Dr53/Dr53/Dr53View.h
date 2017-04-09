// Dr53View.h : CDr53View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr53View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr53View();
	DECLARE_DYNCREATE(CDr53View)

public:
	enum{ IDD = IDD_DR53_FORM };

// 属性
public:
	CDr53Doc* GetDocument() const;

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
	virtual ~CDr53View();
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
//	afx_msg void OnStnClickedPict();
};

#ifndef _DEBUG  // Dr53View.cpp のデバッグ バージョン
inline CDr53Doc* CDr53View::GetDocument() const
   { return reinterpret_cast<CDr53Doc*>(m_pDocument); }
#endif

