// Rei66Doc.cpp : CRei66Doc クラスの実装
//

#include "stdafx.h"
#include "Rei66.h"

#include "Rei66Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei66Doc

IMPLEMENT_DYNCREATE(CRei66Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei66Doc, CDocument)
END_MESSAGE_MAP()


// CRei66Doc コンストラクション/デストラクション

CRei66Doc::CRei66Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei66Doc::~CRei66Doc()
{
}

BOOL CRei66Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei66Doc シリアル化

void CRei66Doc::Serialize(CArchive& ar)
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


// CRei66Doc 診断

#ifdef _DEBUG
void CRei66Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei66Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei66Doc コマンド
