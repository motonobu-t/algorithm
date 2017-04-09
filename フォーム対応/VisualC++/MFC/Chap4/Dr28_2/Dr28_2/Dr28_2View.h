// Dr28_2View.h : CDr28_2View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr28_2View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr28_2View();
	DECLARE_DYNCREATE(CDr28_2View)

public:
	enum{ IDD = IDD_DR28_2_FORM };

// 属性
public:
	CDr28_2Doc* GetDocument() const;

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
	virtual ~CDr28_2View();
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

#ifndef _DEBUG  // Dr28_2View.cpp のデバッグ バージョン
inline CDr28_2Doc* CDr28_2View::GetDocument() const
   { return reinterpret_cast<CDr28_2Doc*>(m_pDocument); }
#endif

