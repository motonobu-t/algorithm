// Rei39Doc.cpp : CRei39Doc クラスの実装
//

#include "stdafx.h"
#include "Rei39.h"

#include "Rei39Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei39Doc

IMPLEMENT_DYNCREATE(CRei39Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei39Doc, CDocument)
END_MESSAGE_MAP()


// CRei39Doc コンストラクション/デストラクション

CRei39Doc::CRei39Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei39Doc::~CRei39Doc()
{
}

BOOL CRei39Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei39Doc シリアル化

void CRei39Doc::Serialize(CArchive& ar)
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


// CRei39Doc 診断

#ifdef _DEBUG
void CRei39Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei39Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei39Doc コマンド
