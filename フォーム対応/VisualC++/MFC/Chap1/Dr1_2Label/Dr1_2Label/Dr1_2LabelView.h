// Dr1_2LabelView.h : CDr1_2LabelView クラスのインターフェイス
//


#pragma once


class CDr1_2LabelView : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr1_2LabelView();
	DECLARE_DYNCREATE(CDr1_2LabelView)

public:
	enum{ IDD = IDD_DR1_2LABEL_FORM };

// 属性
public:
	CDr1_2LabelDoc* GetDocument() const;

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
	virtual ~CDr1_2LabelView();
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

#ifndef _DEBUG  // Dr1_2LabelView.cpp のデバッグ バージョン
inline CDr1_2LabelDoc* CDr1_2LabelView::GetDocument() const
   { return reinterpret_cast<CDr1_2LabelDoc*>(m_pDocument); }
#endif

