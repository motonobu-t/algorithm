// Dr48_2View.h : CDr48_2View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr48_2View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr48_2View();
	DECLARE_DYNCREATE(CDr48_2View)

public:
	enum{ IDD = IDD_DR48_2_FORM };

// 属性
public:
	CDr48_2Doc* GetDocument() const;

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
	virtual ~CDr48_2View();
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

#ifndef _DEBUG  // Dr48_2View.cpp のデバッグ バージョン
inline CDr48_2Doc* CDr48_2View::GetDocument() const
   { return reinterpret_cast<CDr48_2Doc*>(m_pDocument); }
#endif

