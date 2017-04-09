// rei54Doc.cpp : Crei54Doc クラスの実装
//

#include "stdafx.h"
#include "rei54.h"

#include "rei54Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Crei54Doc

IMPLEMENT_DYNCREATE(Crei54Doc, CDocument)

BEGIN_MESSAGE_MAP(Crei54Doc, CDocument)
END_MESSAGE_MAP()


// Crei54Doc コンストラクション/デストラクション

Crei54Doc::Crei54Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

Crei54Doc::~Crei54Doc()
{
}

BOOL Crei54Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// Crei54Doc シリアル化

void Crei54Doc::Serialize(CArchive& ar)
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


// Crei54Doc 診断

#ifdef _DEBUG
void Crei54Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Crei54Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Crei54Doc コマンド
