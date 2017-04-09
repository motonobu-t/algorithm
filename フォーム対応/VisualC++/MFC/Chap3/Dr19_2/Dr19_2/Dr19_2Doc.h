// Dr19_2Doc.h : CDr19_2Doc クラスのインターフェイス
//


#pragma once


class CDr19_2Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CDr19_2Doc();
	DECLARE_DYNCREATE(CDr19_2Doc)

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
	virtual ~CDr19_2Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


