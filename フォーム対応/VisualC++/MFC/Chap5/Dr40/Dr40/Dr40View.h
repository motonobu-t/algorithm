// Dr40View.h : CDr40View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr40View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr40View();
	DECLARE_DYNCREATE(CDr40View)

public:
	enum{ IDD = IDD_DR40_FORM };

// 属性
public:
	CDr40Doc* GetDocument() const;

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
	virtual ~CDr40View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
public:
	CEdit text1;
	CEdit text2;
	CEdit text3;
	CStatic pict;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};

#ifndef _DEBUG  // Dr40View.cpp のデバッグ バージョン
inline CDr40Doc* CDr40View::GetDocument() const
   { return reinterpret_cast<CDr40Doc*>(m_pDocument); }
#endif

