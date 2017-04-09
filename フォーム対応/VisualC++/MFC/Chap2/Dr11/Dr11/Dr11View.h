// Dr11View.h : CDr11View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr11View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr11View();
	DECLARE_DYNCREATE(CDr11View)

public:
	enum{ IDD = IDD_DR11_FORM };

// 属性
public:
	CDr11Doc* GetDocument() const;

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
	virtual ~CDr11View();
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

#ifndef _DEBUG  // Dr11View.cpp のデバッグ バージョン
inline CDr11Doc* CDr11View::GetDocument() const
   { return reinterpret_cast<CDr11Doc*>(m_pDocument); }
#endif

