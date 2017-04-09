// Dr66ListBoxDoc.h : CDr66ListBoxDoc クラスのインターフェイス
//


#pragma once


class CDr66ListBoxDoc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CDr66ListBoxDoc();
	DECLARE_DYNCREATE(CDr66ListBoxDoc)

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
	virtual ~CDr66ListBoxDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


