// Dr1_2LabelDoc.h : CDr1_2LabelDoc クラスのインターフェイス
//


#pragma once


class CDr1_2LabelDoc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CDr1_2LabelDoc();
	DECLARE_DYNCREATE(CDr1_2LabelDoc)

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
	virtual ~CDr1_2LabelDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


