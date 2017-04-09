// Rei17Doc.cpp : CRei17Doc クラスの実装
//

#include "stdafx.h"
#include "Rei17.h"

#include "Rei17Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei17Doc

IMPLEMENT_DYNCREATE(CRei17Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei17Doc, CDocument)
END_MESSAGE_MAP()


// CRei17Doc コンストラクション/デストラクション

CRei17Doc::CRei17Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei17Doc::~CRei17Doc()
{
}

BOOL CRei17Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei17Doc シリアル化

void CRei17Doc::Serialize(CArchive& ar)
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


// CRei17Doc 診断

#ifdef _DEBUG
void CRei17Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei17Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei17Doc コマンド
