// Dr32View.h : CDr32View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr32View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr32View();
	DECLARE_DYNCREATE(CDr32View)

public:
	enum{ IDD = IDD_DR32_FORM };

// 属性
public:
	CDr32Doc* GetDocument() const;

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
	virtual ~CDr32View();
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

#ifndef _DEBUG  // Dr32View.cpp のデバッグ バージョン
inline CDr32Doc* CDr32View::GetDocument() const
   { return reinterpret_cast<CDr32Doc*>(m_pDocument); }
#endif

