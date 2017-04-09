// Rei8View.h : CRei8View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei8View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei8View();
	DECLARE_DYNCREATE(CRei8View)

public:
	enum{ IDD = IDD_REI8_FORM };

// 属性
public:
	CRei8Doc* GetDocument() const;

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
	virtual ~CRei8View();
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

#ifndef _DEBUG  // Rei8View.cpp のデバッグ バージョン
inline CRei8Doc* CRei8View::GetDocument() const
   { return reinterpret_cast<CRei8Doc*>(m_pDocument); }
#endif

