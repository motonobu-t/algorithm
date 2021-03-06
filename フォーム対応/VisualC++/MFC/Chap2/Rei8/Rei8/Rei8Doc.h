// Rei8Doc.h : CRei8Doc クラスのインターフェイス
//


#pragma once


class CRei8Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CRei8Doc();
	DECLARE_DYNCREATE(CRei8Doc)

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
	virtual ~CRei8Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


