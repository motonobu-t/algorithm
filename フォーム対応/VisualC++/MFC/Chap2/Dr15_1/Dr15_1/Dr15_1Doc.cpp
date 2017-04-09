// Dr15_1Doc.cpp : CDr15_1Doc クラスの実装
//

#include "stdafx.h"
#include "Dr15_1.h"

#include "Dr15_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr15_1Doc

IMPLEMENT_DYNCREATE(CDr15_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr15_1Doc, CDocument)
END_MESSAGE_MAP()


// CDr15_1Doc コンストラクション/デストラクション

CDr15_1Doc::CDr15_1Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr15_1Doc::~CDr15_1Doc()
{
}

BOOL CDr15_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr15_1Doc シリアル化

void CDr15_1Doc::Serialize(CArchive& ar)
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


// CDr15_1Doc 診断

#ifdef _DEBUG
void CDr15_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr15_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr15_1Doc コマンド
