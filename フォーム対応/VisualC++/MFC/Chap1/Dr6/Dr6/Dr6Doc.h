// Dr6Doc.h : CDr6Doc クラスのインターフェイス
//


#pragma once


class CDr6Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CDr6Doc();
	DECLARE_DYNCREATE(CDr6Doc)

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
	virtual ~CDr6Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


