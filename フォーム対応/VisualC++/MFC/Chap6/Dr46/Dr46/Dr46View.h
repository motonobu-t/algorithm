// Dr46View.h : CDr46View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr46View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr46View();
	DECLARE_DYNCREATE(CDr46View)

public:
	enum{ IDD = IDD_DR46_FORM };

// 属性
public:
	CDr46Doc* GetDocument() const;

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
	virtual ~CDr46View();
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
	afx_msg void OnBnClickedButton2();
};

#ifndef _DEBUG  // Dr46View.cpp のデバッグ バージョン
inline CDr46Doc* CDr46View::GetDocument() const
   { return reinterpret_cast<CDr46Doc*>(m_pDocument); }
#endif

