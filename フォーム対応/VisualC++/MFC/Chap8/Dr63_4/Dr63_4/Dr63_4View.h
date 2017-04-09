// Dr63_4View.h : CDr63_4View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr63_4View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr63_4View();
	DECLARE_DYNCREATE(CDr63_4View)

public:
	enum{ IDD = IDD_DR63_4_FORM };

// 属性
public:
	CDr63_4Doc* GetDocument() const;

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
	virtual ~CDr63_4View();
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

#ifndef _DEBUG  // Dr63_4View.cpp のデバッグ バージョン
inline CDr63_4Doc* CDr63_4View::GetDocument() const
   { return reinterpret_cast<CDr63_4Doc*>(m_pDocument); }
#endif

