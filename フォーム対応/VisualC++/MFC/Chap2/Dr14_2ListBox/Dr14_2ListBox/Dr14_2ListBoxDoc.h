// Dr14_2ListBoxDoc.h : CDr14_2ListBoxDoc クラスのインターフェイス
//


#pragma once


class CDr14_2ListBoxDoc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CDr14_2ListBoxDoc();
	DECLARE_DYNCREATE(CDr14_2ListBoxDoc)

// 属性
public:

// 操作
public:

// オーバーライド
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// 実装
public:
	virtual ~CDr14_2ListBoxDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


