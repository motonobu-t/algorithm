// Dr42Doc.h : CDr42Doc クラスのインターフェイス
//


#pragma once


class CDr42Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CDr42Doc();
	DECLARE_DYNCREATE(CDr42Doc)

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
	virtual ~CDr42Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


