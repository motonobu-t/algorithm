// Rei36Doc.cpp : CRei36Doc クラスの実装
//

#include "stdafx.h"
#include "Rei36.h"

#include "Rei36Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei36Doc

IMPLEMENT_DYNCREATE(CRei36Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei36Doc, CDocument)
END_MESSAGE_MAP()


// CRei36Doc コンストラクション/デストラクション

CRei36Doc::CRei36Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei36Doc::~CRei36Doc()
{
}

BOOL CRei36Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei36Doc シリアル化

void CRei36Doc::Serialize(CArchive& ar)
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


// CRei36Doc 診断

#ifdef _DEBUG
void CRei36Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei36Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei36Doc コマンド
