// Dr26_1Doc.cpp : CDr26_1Doc クラスの実装
//

#include "stdafx.h"
#include "Dr26_1.h"

#include "Dr26_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr26_1Doc

IMPLEMENT_DYNCREATE(CDr26_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr26_1Doc, CDocument)
END_MESSAGE_MAP()


// CDr26_1Doc コンストラクション/デストラクション

CDr26_1Doc::CDr26_1Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr26_1Doc::~CDr26_1Doc()
{
}

BOOL CDr26_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr26_1Doc シリアル化

void CDr26_1Doc::Serialize(CArchive& ar)
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


// CDr26_1Doc 診断

#ifdef _DEBUG
void CDr26_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr26_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr26_1Doc コマンド
