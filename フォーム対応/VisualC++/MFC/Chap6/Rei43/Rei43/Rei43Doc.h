// Rei43Doc.h : CRei43Doc クラスのインターフェイス
//


#pragma once


class CRei43Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CRei43Doc();
	DECLARE_DYNCREATE(CRei43Doc)

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
	virtual ~CRei43Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


