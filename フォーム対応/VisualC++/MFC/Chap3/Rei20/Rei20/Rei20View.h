// Rei20View.h : CRei20View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei20View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei20View();
	DECLARE_DYNCREATE(CRei20View)

public:
	enum{ IDD = IDD_REI20_FORM };

// 属性
public:
	CRei20Doc* GetDocument() const;

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
	virtual ~CRei20View();
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
	CEdit text1;
};

#ifndef _DEBUG  // Rei20View.cpp のデバッグ バージョン
inline CRei20Doc* CRei20View::GetDocument() const
   { return reinterpret_cast<CRei20Doc*>(m_pDocument); }
#endif

