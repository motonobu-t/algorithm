// Rei26Doc.h : CRei26Doc クラスのインターフェイス
//


#pragma once


class CRei26Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CRei26Doc();
	DECLARE_DYNCREATE(CRei26Doc)

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
	virtual ~CRei26Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


