// Rei23View.h : CRei23View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei23View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei23View();
	DECLARE_DYNCREATE(CRei23View)

public:
	enum{ IDD = IDD_REI23_FORM };

// 属性
public:
	CRei23Doc* GetDocument() const;

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
	virtual ~CRei23View();
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

#ifndef _DEBUG  // Rei23View.cpp のデバッグ バージョン
inline CRei23Doc* CRei23View::GetDocument() const
   { return reinterpret_cast<CRei23Doc*>(m_pDocument); }
#endif

