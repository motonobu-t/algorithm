// Rei51Doc.h : CRei51Doc クラスのインターフェイス
//


#pragma once


class CRei51Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CRei51Doc();
	DECLARE_DYNCREATE(CRei51Doc)

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
	virtual ~CRei51Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


