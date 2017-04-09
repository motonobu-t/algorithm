// Dr61Doc.h : CDr61Doc クラスのインターフェイス
//


#pragma once


class CDr61Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CDr61Doc();
	DECLARE_DYNCREATE(CDr61Doc)

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
	virtual ~CDr61Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


