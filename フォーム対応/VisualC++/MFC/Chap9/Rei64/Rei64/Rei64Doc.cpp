// Rei64Doc.cpp : CRei64Doc クラスの実装
//

#include "stdafx.h"
#include "Rei64.h"

#include "Rei64Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei64Doc

IMPLEMENT_DYNCREATE(CRei64Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei64Doc, CDocument)
END_MESSAGE_MAP()


// CRei64Doc コンストラクション/デストラクション

CRei64Doc::CRei64Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei64Doc::~CRei64Doc()
{
}

BOOL CRei64Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei64Doc シリアル化

void CRei64Doc::Serialize(CArchive& ar)
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


// CRei64Doc 診断

#ifdef _DEBUG
void CRei64Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei64Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei64Doc コマンド
