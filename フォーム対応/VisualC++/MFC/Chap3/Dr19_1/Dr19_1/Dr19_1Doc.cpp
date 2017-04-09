// Dr19_1Doc.cpp : CDr19_1Doc クラスの実装
//

#include "stdafx.h"
#include "Dr19_1.h"

#include "Dr19_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr19_1Doc

IMPLEMENT_DYNCREATE(CDr19_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr19_1Doc, CDocument)
END_MESSAGE_MAP()


// CDr19_1Doc コンストラクション/デストラクション

CDr19_1Doc::CDr19_1Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr19_1Doc::~CDr19_1Doc()
{
}

BOOL CDr19_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr19_1Doc シリアル化

void CDr19_1Doc::Serialize(CArchive& ar)
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


// CDr19_1Doc 診断

#ifdef _DEBUG
void CDr19_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr19_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr19_1Doc コマンド
