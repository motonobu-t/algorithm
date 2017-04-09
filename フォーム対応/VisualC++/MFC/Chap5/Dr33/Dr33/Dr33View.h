// Dr33View.h : CDr33View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr33View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr33View();
	DECLARE_DYNCREATE(CDr33View)

public:
	enum{ IDD = IDD_DR33_FORM };

// 属性
public:
	CDr33Doc* GetDocument() const;

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
	virtual ~CDr33View();
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
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};

#ifndef _DEBUG  // Dr33View.cpp のデバッグ バージョン
inline CDr33Doc* CDr33View::GetDocument() const
   { return reinterpret_cast<CDr33Doc*>(m_pDocument); }
#endif

