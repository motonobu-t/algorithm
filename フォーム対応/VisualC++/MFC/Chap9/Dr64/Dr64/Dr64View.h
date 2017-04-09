// Dr64View.h : CDr64View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr64View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr64View();
	DECLARE_DYNCREATE(CDr64View)

public:
	enum{ IDD = IDD_DR64_FORM };

// 属性
public:
	CDr64Doc* GetDocument() const;

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
	virtual ~CDr64View();
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

#ifndef _DEBUG  // Dr64View.cpp のデバッグ バージョン
inline CDr64Doc* CDr64View::GetDocument() const
   { return reinterpret_cast<CDr64Doc*>(m_pDocument); }
#endif

