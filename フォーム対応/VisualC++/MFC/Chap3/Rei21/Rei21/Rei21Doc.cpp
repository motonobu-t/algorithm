// Rei21Doc.cpp : CRei21Doc クラスの実装
//

#include "stdafx.h"
#include "Rei21.h"

#include "Rei21Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei21Doc

IMPLEMENT_DYNCREATE(CRei21Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei21Doc, CDocument)
END_MESSAGE_MAP()


// CRei21Doc コンストラクション/デストラクション

CRei21Doc::CRei21Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei21Doc::~CRei21Doc()
{
}

BOOL CRei21Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei21Doc シリアル化

void CRei21Doc::Serialize(CArchive& ar)
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


// CRei21Doc 診断

#ifdef _DEBUG
void CRei21Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei21Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei21Doc コマンド
