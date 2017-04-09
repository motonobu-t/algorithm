// Rei48Doc.cpp : CRei48Doc クラスの実装
//

#include "stdafx.h"
#include "Rei48.h"

#include "Rei48Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei48Doc

IMPLEMENT_DYNCREATE(CRei48Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei48Doc, CDocument)
END_MESSAGE_MAP()


// CRei48Doc コンストラクション/デストラクション

CRei48Doc::CRei48Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei48Doc::~CRei48Doc()
{
}

BOOL CRei48Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei48Doc シリアル化

void CRei48Doc::Serialize(CArchive& ar)
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


// CRei48Doc 診断

#ifdef _DEBUG
void CRei48Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei48Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei48Doc コマンド
