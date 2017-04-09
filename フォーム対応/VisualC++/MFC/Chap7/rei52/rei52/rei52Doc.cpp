// rei52Doc.cpp : Crei52Doc クラスの実装
//

#include "stdafx.h"
#include "rei52.h"

#include "rei52Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Crei52Doc

IMPLEMENT_DYNCREATE(Crei52Doc, CDocument)

BEGIN_MESSAGE_MAP(Crei52Doc, CDocument)
END_MESSAGE_MAP()


// Crei52Doc コンストラクション/デストラクション

Crei52Doc::Crei52Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

Crei52Doc::~Crei52Doc()
{
}

BOOL Crei52Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// Crei52Doc シリアル化

void Crei52Doc::Serialize(CArchive& ar)
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


// Crei52Doc 診断

#ifdef _DEBUG
void Crei52Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void Crei52Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Crei52Doc コマンド
