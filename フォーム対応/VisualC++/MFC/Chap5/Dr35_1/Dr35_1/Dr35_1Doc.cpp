// Dr35_1Doc.cpp : CDr35_1Doc クラスの実装
//

#include "stdafx.h"
#include "Dr35_1.h"

#include "Dr35_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr35_1Doc

IMPLEMENT_DYNCREATE(CDr35_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr35_1Doc, CDocument)
END_MESSAGE_MAP()


// CDr35_1Doc コンストラクション/デストラクション

CDr35_1Doc::CDr35_1Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr35_1Doc::~CDr35_1Doc()
{
}

BOOL CDr35_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr35_1Doc シリアル化

void CDr35_1Doc::Serialize(CArchive& ar)
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


// CDr35_1Doc 診断

#ifdef _DEBUG
void CDr35_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr35_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr35_1Doc コマンド
