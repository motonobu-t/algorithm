// Dr27Doc.h : CDr27Doc クラスのインターフェイス
//


#pragma once


class CDr27Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CDr27Doc();
	DECLARE_DYNCREATE(CDr27Doc)

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
	virtual ~CDr27Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


