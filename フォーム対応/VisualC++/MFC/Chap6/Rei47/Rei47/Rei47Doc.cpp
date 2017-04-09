// Rei47Doc.cpp : CRei47Doc クラスの実装
//

#include "stdafx.h"
#include "Rei47.h"

#include "Rei47Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei47Doc

IMPLEMENT_DYNCREATE(CRei47Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei47Doc, CDocument)
END_MESSAGE_MAP()


// CRei47Doc コンストラクション/デストラクション

CRei47Doc::CRei47Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei47Doc::~CRei47Doc()
{
}

BOOL CRei47Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei47Doc シリアル化

void CRei47Doc::Serialize(CArchive& ar)
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


// CRei47Doc 診断

#ifdef _DEBUG
void CRei47Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei47Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei47Doc コマンド
