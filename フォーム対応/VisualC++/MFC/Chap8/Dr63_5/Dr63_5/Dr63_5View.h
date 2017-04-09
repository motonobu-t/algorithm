// Dr63_5View.h : CDr63_5View クラスのインターフェイス
//


#pragma once
#include "afxwin.h"


class CDr63_5View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr63_5View();
	DECLARE_DYNCREATE(CDr63_5View)

public:
	enum{ IDD = IDD_DR63_5_FORM };

// 属性
public:
	CDr63_5Doc* GetDocument() const;

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
	virtual ~CDr63_5View();
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

#ifndef _DEBUG  // Dr63_5View.cpp のデバッグ バージョン
inline CDr63_5Doc* CDr63_5View::GetDocument() const
   { return reinterpret_cast<CDr63_5Doc*>(m_pDocument); }
#endif

