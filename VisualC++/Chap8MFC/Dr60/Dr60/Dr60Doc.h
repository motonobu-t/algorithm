// Dr60Doc.h : CDr60Doc クラスのインターフェイス
//


#pragma once


class CDr60Doc : public CDocument
{
protected: // シリアル化からのみ作成します。
	CDr60Doc();
	DECLARE_DYNCREATE(CDr60Doc)

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
	virtual ~CDr60Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成された、メッセージ割り当て関数
protected:
	DECLARE_MESSAGE_MAP()
};


