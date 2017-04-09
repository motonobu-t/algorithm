// Rei24View.h : CRei24View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei24View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei24View();
	DECLARE_DYNCREATE(CRei24View)

public:
	enum{ IDD = IDD_REI24_FORM };

// 属性
public:
	CRei24Doc* GetDocument() const;

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
	virtual ~CRei24View();
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

#ifndef _DEBUG  // Rei24View.cpp のデバッグ バージョン
inline CRei24Doc* CRei24View::GetDocument() const
   { return reinterpret_cast<CRei24Doc*>(m_pDocument); }
#endif

