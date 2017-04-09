// Rei65View.h : CRei65View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei65View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei65View();
	DECLARE_DYNCREATE(CRei65View)

public:
	enum{ IDD = IDD_REI65_FORM };

// 属性
public:
	CRei65Doc* GetDocument() const;

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
	virtual ~CRei65View();
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
};

#ifndef _DEBUG  // Rei65View.cpp のデバッグ バージョン
inline CRei65Doc* CRei65View::GetDocument() const
   { return reinterpret_cast<CRei65Doc*>(m_pDocument); }
#endif

