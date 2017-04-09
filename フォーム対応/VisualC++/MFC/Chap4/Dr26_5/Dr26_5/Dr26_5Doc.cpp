// Dr26_5Doc.cpp : CDr26_5Doc クラスの実装
//

#include "stdafx.h"
#include "Dr26_5.h"

#include "Dr26_5Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr26_5Doc

IMPLEMENT_DYNCREATE(CDr26_5Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr26_5Doc, CDocument)
END_MESSAGE_MAP()


// CDr26_5Doc コンストラクション/デストラクション

CDr26_5Doc::CDr26_5Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr26_5Doc::~CDr26_5Doc()
{
}

BOOL CDr26_5Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr26_5Doc シリアル化

void CDr26_5Doc::Serialize(CArchive& ar)
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


// CDr26_5Doc 診断

#ifdef _DEBUG
void CDr26_5Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr26_5Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr26_5Doc コマンド
