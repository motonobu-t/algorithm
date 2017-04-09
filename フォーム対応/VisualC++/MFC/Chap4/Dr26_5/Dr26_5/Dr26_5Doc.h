// Dr26_5Doc.h : CDr26_5Doc クラスのインターフェイス
//


#pragma once


class CDr26_5Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CDr26_5Doc();
	DECLARE_DYNCREATE(CDr26_5Doc)

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
	virtual ~CDr26_5Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


