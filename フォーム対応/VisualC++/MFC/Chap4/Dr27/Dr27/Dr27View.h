// Dr27View.h : CDr27View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr27View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr27View();
	DECLARE_DYNCREATE(CDr27View)

public:
	enum{ IDD = IDD_DR27_FORM };

// 属性
public:
	CDr27Doc* GetDocument() const;

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
	virtual ~CDr27View();
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

#ifndef _DEBUG  // Dr27View.cpp のデバッグ バージョン
inline CDr27Doc* CDr27View::GetDocument() const
   { return reinterpret_cast<CDr27Doc*>(m_pDocument); }
#endif

