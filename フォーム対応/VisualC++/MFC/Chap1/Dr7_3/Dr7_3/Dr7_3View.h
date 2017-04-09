// Dr7_3View.h : CDr7_3View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr7_3View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr7_3View();
	DECLARE_DYNCREATE(CDr7_3View)

public:
	enum{ IDD = IDD_DR7_3_FORM };

// 属性
public:
	CDr7_3Doc* GetDocument() const;

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
	virtual ~CDr7_3View();
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
	CEdit text1;
	CStatic pict;
};

#ifndef _DEBUG  // Dr7_3View.cpp のデバッグ バージョン
inline CDr7_3Doc* CDr7_3View::GetDocument() const
   { return reinterpret_cast<CDr7_3Doc*>(m_pDocument); }
#endif

