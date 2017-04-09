// Rei31View.h : CRei31View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei31View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei31View();
	DECLARE_DYNCREATE(CRei31View)

public:
	enum{ IDD = IDD_REI31_FORM };

// 属性
public:
	CRei31Doc* GetDocument() const;

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
	virtual ~CRei31View();
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

#ifndef _DEBUG  // Rei31View.cpp のデバッグ バージョン
inline CRei31Doc* CRei31View::GetDocument() const
   { return reinterpret_cast<CRei31Doc*>(m_pDocument); }
#endif

