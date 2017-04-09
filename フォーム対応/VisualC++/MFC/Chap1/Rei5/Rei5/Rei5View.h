// Rei5View.h : CRei5View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CRei5View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei5View();
	DECLARE_DYNCREATE(CRei5View)

public:
	enum{ IDD = IDD_REI5_FORM };

// 属性
public:
	CRei5Doc* GetDocument() const;

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
	virtual ~CRei5View();
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
//	afx_msg void OnStnClickedPict();
};

#ifndef _DEBUG  // Rei5View.cpp のデバッグ バージョン
inline CRei5Doc* CRei5View::GetDocument() const
   { return reinterpret_cast<CRei5Doc*>(m_pDocument); }
#endif

