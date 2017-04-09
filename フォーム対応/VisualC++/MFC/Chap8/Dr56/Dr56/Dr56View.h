// Dr56View.h : CDr56View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr56View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr56View();
	DECLARE_DYNCREATE(CDr56View)

public:
	enum{ IDD = IDD_DR56_FORM };

// 属性
public:
	CDr56Doc* GetDocument() const;

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
	virtual ~CDr56View();
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

#ifndef _DEBUG  // Dr56View.cpp のデバッグ バージョン
inline CDr56Doc* CDr56View::GetDocument() const
   { return reinterpret_cast<CDr56Doc*>(m_pDocument); }
#endif

