// Dr39Doc.cpp : CDr39Doc クラスの実装
//

#include "stdafx.h"
#include "Dr39.h"

#include "Dr39Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr39Doc

IMPLEMENT_DYNCREATE(CDr39Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr39Doc, CDocument)
END_MESSAGE_MAP()


// CDr39Doc コンストラクション/デストラクション

CDr39Doc::CDr39Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr39Doc::~CDr39Doc()
{
}

BOOL CDr39Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr39Doc シリアル化

void CDr39Doc::Serialize(CArchive& ar)
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


// CDr39Doc 診断

#ifdef _DEBUG
void CDr39Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr39Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr39Doc コマンド
