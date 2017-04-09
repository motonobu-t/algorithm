// Dr38_1Doc.cpp : CDr38_1Doc クラスの実装
//

#include "stdafx.h"
#include "Dr38_1.h"

#include "Dr38_1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr38_1Doc

IMPLEMENT_DYNCREATE(CDr38_1Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr38_1Doc, CDocument)
END_MESSAGE_MAP()


// CDr38_1Doc コンストラクション/デストラクション

CDr38_1Doc::CDr38_1Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr38_1Doc::~CDr38_1Doc()
{
}

BOOL CDr38_1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr38_1Doc シリアル化

void CDr38_1Doc::Serialize(CArchive& ar)
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


// CDr38_1Doc 診断

#ifdef _DEBUG
void CDr38_1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr38_1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr38_1Doc コマンド
