// Dr24Doc.h : CDr24Doc クラスのインターフェイス
//


#pragma once


class CDr24Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CDr24Doc();
	DECLARE_DYNCREATE(CDr24Doc)

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
	virtual ~CDr24Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


