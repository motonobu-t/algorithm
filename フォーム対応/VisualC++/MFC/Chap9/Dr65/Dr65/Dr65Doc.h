// Dr65Doc.h : CDr65Doc クラスのインターフェイス
//


#pragma once


class CDr65Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CDr65Doc();
	DECLARE_DYNCREATE(CDr65Doc)

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
	virtual ~CDr65Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


