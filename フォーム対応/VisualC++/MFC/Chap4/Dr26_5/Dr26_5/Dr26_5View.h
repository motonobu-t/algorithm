// Dr26_5View.h : CDr26_5View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr26_5View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr26_5View();
	DECLARE_DYNCREATE(CDr26_5View)

public:
	enum{ IDD = IDD_DR26_5_FORM };

// 属性
public:
	CDr26_5Doc* GetDocument() const;

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
	virtual ~CDr26_5View();
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
	CEdit text2;
	afx_msg void OnBnClickedButton1();
};

#ifndef _DEBUG  // Dr26_5View.cpp のデバッグ バージョン
inline CDr26_5Doc* CDr26_5View::GetDocument() const
   { return reinterpret_cast<CDr26_5Doc*>(m_pDocument); }
#endif

