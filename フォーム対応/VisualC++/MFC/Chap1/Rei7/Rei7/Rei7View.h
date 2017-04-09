// Rei7View.h : CRei7View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei7View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei7View();
	DECLARE_DYNCREATE(CRei7View)

public:
	enum{ IDD = IDD_REI7_FORM };

// 属性
public:
	CRei7Doc* GetDocument() const;

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
	virtual ~CRei7View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CEdit text1;
	afx_msg void OnBnClickedButton1();
	CStatic pict;
};

#ifndef _DEBUG  // Rei7View.cpp のデバッグ バージョン
inline CRei7Doc* CRei7View::GetDocument() const
   { return reinterpret_cast<CRei7Doc*>(m_pDocument); }
#endif

