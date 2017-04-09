// Dr66ListBoxView.h : CDr66ListBoxView クラスのインターフェイス
//


#pragma once


class CDr66ListBoxView : public CFormView
{
protected: // シリアル化からのみ作成します。
	CDr66ListBoxView();
	DECLARE_DYNCREATE(CDr66ListBoxView)

public:
	enum{ IDD = IDD_DR66LISTBOX_FORM };

// 属性
public:
	CDr66ListBoxDoc* GetDocument() const;

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
	virtual ~CDr66ListBoxView();
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

#ifndef _DEBUG  // Dr66ListBoxView.cpp のデバッグ バージョン
inline CDr66ListBoxDoc* CDr66ListBoxView::GetDocument() const
   { return reinterpret_cast<CDr66ListBoxDoc*>(m_pDocument); }
#endif

