// Rei50View.h : CRei50View クラスのインターフェイス
//


#pragma once


class CRei50View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CRei50View();
	DECLARE_DYNCREATE(CRei50View)

public:
	enum{ IDD = IDD_REI50_FORM };

// 属性
public:
	CRei50Doc* GetDocument() const;

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
	virtual ~CRei50View();
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
};

#ifndef _DEBUG  // Rei50View.cpp のデバッグ バージョン
inline CRei50Doc* CRei50View::GetDocument() const
   { return reinterpret_cast<CRei50Doc*>(m_pDocument); }
#endif

