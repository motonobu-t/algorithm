// Dr43Doc.h : CDr43Doc クラスのインターフェイス
//


#pragma once


class CDr43Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CDr43Doc();
	DECLARE_DYNCREATE(CDr43Doc)

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
	virtual ~CDr43Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


