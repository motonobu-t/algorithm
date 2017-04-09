// Rei63Doc.h : CRei63Doc クラスのインターフェイス
//


#pragma once


class CRei63Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CRei63Doc();
	DECLARE_DYNCREATE(CRei63Doc)

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
	virtual ~CRei63Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


