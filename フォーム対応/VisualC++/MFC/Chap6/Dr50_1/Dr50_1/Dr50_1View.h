// Dr50_1View.h : CDr50_1View クラスのインターフェイス
//


#pragma once


class CDr50_1View : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr50_1View();
	DECLARE_DYNCREATE(CDr50_1View)

public:
	enum{ IDD = IDD_DR50_1_FORM };

// 属性
public:
	CDr50_1Doc* GetDocument() const;

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
	virtual ~CDr50_1View();
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

#ifndef _DEBUG  // Dr50_1View.cpp のデバッグ バージョン
inline CDr50_1Doc* CDr50_1View::GetDocument() const
   { return reinterpret_cast<CDr50_1Doc*>(m_pDocument); }
#endif

