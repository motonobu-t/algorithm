// Dr35_1Doc.h : CDr35_1Doc クラスのインターフェイス
//


#pragma once


class CDr35_1Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CDr35_1Doc();
	DECLARE_DYNCREATE(CDr35_1Doc)

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
	virtual ~CDr35_1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


