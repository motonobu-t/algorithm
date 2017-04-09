// Dr18_1Doc.cpp : CDr18_1Doc クラスの実装
//

#include "stdafx.h"
#include "Dr18_1.h"

#include "Dr18_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr18_1Doc

IMPLEMENT_DYNCREATE(CDr18_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr18_1Doc, CDocument)
END_MESSAGE_MAP()


// CDr18_1Doc コンストラクション/デストラクション

CDr18_1Doc::CDr18_1Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr18_1Doc::~CDr18_1Doc()
{
}

BOOL CDr18_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr18_1Doc シリアル化

void CDr18_1Doc::Serialize(CArchive& ar)
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


// CDr18_1Doc 診断

#ifdef _DEBUG
void CDr18_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr18_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr18_1Doc コマンド
