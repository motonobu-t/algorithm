// Dr67View.h : CDr67View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr67View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr67View();
	DECLARE_DYNCREATE(CDr67View)

public:
	enum{ IDD = IDD_DR67_FORM };

// 属性
public:
	CDr67Doc* GetDocument() const;

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
	virtual ~CDr67View();
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

#ifndef _DEBUG  // Dr67View.cpp のデバッグ バージョン
inline CDr67Doc* CDr67View::GetDocument() const
   { return reinterpret_cast<CDr67Doc*>(m_pDocument); }
#endif

