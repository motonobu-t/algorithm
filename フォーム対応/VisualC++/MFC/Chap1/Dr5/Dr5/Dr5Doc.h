// Dr5Doc.h : CDr5Doc クラスのインターフェイス
//


#pragma once


class CDr5Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CDr5Doc();
	DECLARE_DYNCREATE(CDr5Doc)

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
	virtual ~CDr5Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


