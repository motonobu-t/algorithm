// Rei56Doc.cpp : CRei56Doc クラスの実装
//

#include "stdafx.h"
#include "Rei56.h"

#include "Rei56Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei56Doc

IMPLEMENT_DYNCREATE(CRei56Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei56Doc, CDocument)
END_MESSAGE_MAP()


// CRei56Doc コンストラクション/デストラクション

CRei56Doc::CRei56Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei56Doc::~CRei56Doc()
{
}

BOOL CRei56Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei56Doc シリアル化

void CRei56Doc::Serialize(CArchive& ar)
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


// CRei56Doc 診断

#ifdef _DEBUG
void CRei56Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei56Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei56Doc コマンド
