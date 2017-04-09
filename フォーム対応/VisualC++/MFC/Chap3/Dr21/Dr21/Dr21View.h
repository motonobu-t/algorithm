// Dr21View.h : CDr21View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr21View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr21View();
	DECLARE_DYNCREATE(CDr21View)

public:
	enum{ IDD = IDD_DR21_FORM };

// 属性
public:
	CDr21Doc* GetDocument() const;

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
	virtual ~CDr21View();
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
	CEdit text1;
};

#ifndef _DEBUG  // Dr21View.cpp のデバッグ バージョン
inline CDr21Doc* CDr21View::GetDocument() const
   { return reinterpret_cast<CDr21Doc*>(m_pDocument); }
#endif

