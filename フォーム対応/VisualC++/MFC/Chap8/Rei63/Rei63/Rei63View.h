// Rei63View.h : CRei63View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei63View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei63View();
	DECLARE_DYNCREATE(CRei63View)

public:
	enum{ IDD = IDD_REI63_FORM };

// 属性
public:
	CRei63Doc* GetDocument() const;

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
	virtual ~CRei63View();
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

#ifndef _DEBUG  // Rei63View.cpp のデバッグ バージョン
inline CRei63Doc* CRei63View::GetDocument() const
   { return reinterpret_cast<CRei63Doc*>(m_pDocument); }
#endif

