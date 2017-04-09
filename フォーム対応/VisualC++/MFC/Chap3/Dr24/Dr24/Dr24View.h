// Dr24View.h : CDr24View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr24View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr24View();
	DECLARE_DYNCREATE(CDr24View)

public:
	enum{ IDD = IDD_DR24_FORM };

// 属性
public:
	CDr24Doc* GetDocument() const;

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
	virtual ~CDr24View();
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

#ifndef _DEBUG  // Dr24View.cpp のデバッグ バージョン
inline CDr24Doc* CDr24View::GetDocument() const
   { return reinterpret_cast<CDr24Doc*>(m_pDocument); }
#endif

