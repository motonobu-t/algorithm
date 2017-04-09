// Rei40Doc.cpp : CRei40Doc クラスの実装
//

#include "stdafx.h"
#include "Rei40.h"

#include "Rei40Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei40Doc

IMPLEMENT_DYNCREATE(CRei40Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei40Doc, CDocument)
END_MESSAGE_MAP()


// CRei40Doc コンストラクション/デストラクション

CRei40Doc::CRei40Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei40Doc::~CRei40Doc()
{
}

BOOL CRei40Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei40Doc シリアル化

void CRei40Doc::Serialize(CArchive& ar)
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


// CRei40Doc 診断

#ifdef _DEBUG
void CRei40Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei40Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei40Doc コマンド
