// Rei33Doc.cpp : CRei33Doc クラスの実装
//

#include "stdafx.h"
#include "Rei33.h"

#include "Rei33Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei33Doc

IMPLEMENT_DYNCREATE(CRei33Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei33Doc, CDocument)
END_MESSAGE_MAP()


// CRei33Doc コンストラクション/デストラクション

CRei33Doc::CRei33Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei33Doc::~CRei33Doc()
{
}

BOOL CRei33Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei33Doc シリアル化

void CRei33Doc::Serialize(CArchive& ar)
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


// CRei33Doc 診断

#ifdef _DEBUG
void CRei33Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei33Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei33Doc コマンド
