// Dr52Doc.h : CDr52Doc クラスのインターフェイス
//


#pragma once


class CDr52Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CDr52Doc();
	DECLARE_DYNCREATE(CDr52Doc)

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
	virtual ~CDr52Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


