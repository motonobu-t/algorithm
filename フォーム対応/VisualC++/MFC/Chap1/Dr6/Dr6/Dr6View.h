// Dr6View.h : CDr6View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr6View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr6View();
	DECLARE_DYNCREATE(CDr6View)

public:
	enum{ IDD = IDD_DR6_FORM };

// 属性
public:
	CDr6Doc* GetDocument() const;

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
	virtual ~CDr6View();
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
	CEdit text1;
	CEdit text2;
	CStatic pict;
//	afx_msg void OnStnClickedPict();
};

#ifndef _DEBUG  // Dr6View.cpp のデバッグ バージョン
inline CDr6Doc* CDr6View::GetDocument() const
   { return reinterpret_cast<CDr6Doc*>(m_pDocument); }
#endif

