// Rei57Doc.cpp : CRei57Doc クラスの実装
//

#include "stdafx.h"
#include "Rei57.h"

#include "Rei57Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei57Doc

IMPLEMENT_DYNCREATE(CRei57Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei57Doc, CDocument)
END_MESSAGE_MAP()


// CRei57Doc コンストラクション/デストラクション

CRei57Doc::CRei57Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei57Doc::~CRei57Doc()
{
}

BOOL CRei57Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei57Doc シリアル化

void CRei57Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 格納するコードをここに追加してください。
	}
	else
	{
		// TODO: 読み込むコードをここに追加してください。
	}
}


// CRei57Doc 診断

#ifdef _DEBUG
void CRei57Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei57Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei57Doc コマンド
