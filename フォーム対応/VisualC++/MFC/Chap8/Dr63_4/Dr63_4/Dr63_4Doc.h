// Dr63_4Doc.h : CDr63_4Doc クラスのインターフェイス
//


#pragma once


class CDr63_4Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CDr63_4Doc();
	DECLARE_DYNCREATE(CDr63_4Doc)

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
	virtual ~CDr63_4Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


