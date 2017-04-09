// Rei44Doc.cpp : CRei44Doc クラスの実装
//

#include "stdafx.h"
#include "Rei44.h"

#include "Rei44Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei44Doc

IMPLEMENT_DYNCREATE(CRei44Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei44Doc, CDocument)
END_MESSAGE_MAP()


// CRei44Doc コンストラクション/デストラクション

CRei44Doc::CRei44Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei44Doc::~CRei44Doc()
{
}

BOOL CRei44Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei44Doc シリアル化

void CRei44Doc::Serialize(CArchive& ar)
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


// CRei44Doc 診断

#ifdef _DEBUG
void CRei44Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei44Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei44Doc コマンド
