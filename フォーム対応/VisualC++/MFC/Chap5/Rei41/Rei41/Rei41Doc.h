// Rei41Doc.h : CRei41Doc クラスのインターフェイス
//


#pragma once


class CRei41Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CRei41Doc();
	DECLARE_DYNCREATE(CRei41Doc)

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
	virtual ~CRei41Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


