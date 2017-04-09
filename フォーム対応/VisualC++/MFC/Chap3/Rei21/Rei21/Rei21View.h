// Rei21View.h : CRei21View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei21View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei21View();
	DECLARE_DYNCREATE(CRei21View)

public:
	enum{ IDD = IDD_REI21_FORM };

// 属性
public:
	CRei21Doc* GetDocument() const;

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
	virtual ~CRei21View();
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
//	afx_msg void OnEnChangeEdit1();
};

#ifndef _DEBUG  // Rei21View.cpp のデバッグ バージョン
inline CRei21Doc* CRei21View::GetDocument() const
   { return reinterpret_cast<CRei21Doc*>(m_pDocument); }
#endif

