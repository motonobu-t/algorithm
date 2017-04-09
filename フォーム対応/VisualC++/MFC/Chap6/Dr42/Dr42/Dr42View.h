// Dr42View.h : CDr42View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr42View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr42View();
	DECLARE_DYNCREATE(CDr42View)

public:
	enum{ IDD = IDD_DR42_FORM };

// 属性
public:
	CDr42Doc* GetDocument() const;

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
	virtual ~CDr42View();
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

#ifndef _DEBUG  // Dr42View.cpp のデバッグ バージョン
inline CDr42Doc* CDr42View::GetDocument() const
   { return reinterpret_cast<CDr42Doc*>(m_pDocument); }
#endif

