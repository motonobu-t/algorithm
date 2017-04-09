// Rei12View.h : CRei12View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei12View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei12View();
	DECLARE_DYNCREATE(CRei12View)

public:
	enum{ IDD = IDD_REI12_FORM };

// 属性
public:
	CRei12Doc* GetDocument() const;

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
	virtual ~CRei12View();
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

#ifndef _DEBUG  // Rei12View.cpp のデバッグ バージョン
inline CRei12Doc* CRei12View::GetDocument() const
   { return reinterpret_cast<CRei12Doc*>(m_pDocument); }
#endif

