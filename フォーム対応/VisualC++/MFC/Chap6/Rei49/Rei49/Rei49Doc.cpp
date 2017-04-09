// Rei49Doc.cpp : CRei49Doc クラスの実装
//

#include "stdafx.h"
#include "Rei49.h"

#include "Rei49Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei49Doc

IMPLEMENT_DYNCREATE(CRei49Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei49Doc, CDocument)
END_MESSAGE_MAP()


// CRei49Doc コンストラクション/デストラクション

CRei49Doc::CRei49Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei49Doc::~CRei49Doc()
{
}

BOOL CRei49Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei49Doc シリアル化

void CRei49Doc::Serialize(CArchive& ar)
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


// CRei49Doc 診断

#ifdef _DEBUG
void CRei49Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei49Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei49Doc コマンド
