// Rei58Doc.cpp : CRei58Doc クラスの実装
//

#include "stdafx.h"
#include "Rei58.h"

#include "Rei58Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei58Doc

IMPLEMENT_DYNCREATE(CRei58Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei58Doc, CDocument)
END_MESSAGE_MAP()


// CRei58Doc コンストラクション/デストラクション

CRei58Doc::CRei58Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei58Doc::~CRei58Doc()
{
}

BOOL CRei58Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei58Doc シリアル化

void CRei58Doc::Serialize(CArchive& ar)
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


// CRei58Doc 診断

#ifdef _DEBUG
void CRei58Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei58Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei58Doc コマンド
