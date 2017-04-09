// Rei24Doc.cpp : CRei24Doc クラスの実装
//

#include "stdafx.h"
#include "Rei24.h"

#include "Rei24Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei24Doc

IMPLEMENT_DYNCREATE(CRei24Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei24Doc, CDocument)
END_MESSAGE_MAP()


// CRei24Doc コンストラクション/デストラクション

CRei24Doc::CRei24Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei24Doc::~CRei24Doc()
{
}

BOOL CRei24Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei24Doc シリアル化

void CRei24Doc::Serialize(CArchive& ar)
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


// CRei24Doc 診断

#ifdef _DEBUG
void CRei24Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei24Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei24Doc コマンド
