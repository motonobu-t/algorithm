// Rei12Doc.h : CRei12Doc クラスのインターフェイス
//


#pragma once


class CRei12Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CRei12Doc();
	DECLARE_DYNCREATE(CRei12Doc)

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
	virtual ~CRei12Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


