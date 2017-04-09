// Dr2View.h : CDr2View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr2View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr2View();
	DECLARE_DYNCREATE(CDr2View)

public:
	enum{ IDD = IDD_DR2_FORM };

// 属性
public:
	CDr2Doc* GetDocument() const;

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
	virtual ~CDr2View();
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

#ifndef _DEBUG  // Dr2View.cpp のデバッグ バージョン
inline CDr2Doc* CDr2View::GetDocument() const
   { return reinterpret_cast<CDr2Doc*>(m_pDocument); }
#endif

