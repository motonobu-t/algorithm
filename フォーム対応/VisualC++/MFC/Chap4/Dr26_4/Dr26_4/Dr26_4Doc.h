// Dr26_4Doc.h : CDr26_4Doc クラスのインターフェイス
//


#pragma once


class CDr26_4Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CDr26_4Doc();
	DECLARE_DYNCREATE(CDr26_4Doc)

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
	virtual ~CDr26_4Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


