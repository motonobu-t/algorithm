// Dr50_1Doc.cpp : CDr50_1Doc クラスの実装
//

#include "stdafx.h"
#include "Dr50_1.h"

#include "Dr50_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr50_1Doc

IMPLEMENT_DYNCREATE(CDr50_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr50_1Doc, CDocument)
END_MESSAGE_MAP()


// CDr50_1Doc コンストラクション/デストラクション

CDr50_1Doc::CDr50_1Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr50_1Doc::~CDr50_1Doc()
{
}

BOOL CDr50_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr50_1Doc シリアル化

void CDr50_1Doc::Serialize(CArchive& ar)
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


// CDr50_1Doc 診断

#ifdef _DEBUG
void CDr50_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr50_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr50_1Doc コマンド
