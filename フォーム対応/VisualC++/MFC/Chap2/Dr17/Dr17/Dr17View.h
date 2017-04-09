// Dr17View.h : CDr17View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr17View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr17View();
	DECLARE_DYNCREATE(CDr17View)

public:
	enum{ IDD = IDD_DR17_FORM };

// 属性
public:
	CDr17Doc* GetDocument() const;

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
	virtual ~CDr17View();
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

#ifndef _DEBUG  // Dr17View.cpp のデバッグ バージョン
inline CDr17Doc* CDr17View::GetDocument() const
   { return reinterpret_cast<CDr17Doc*>(m_pDocument); }
#endif

