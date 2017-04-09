// Dr41Doc.cpp : CDr41Doc クラスの実装
//

#include "stdafx.h"
#include "Dr41.h"

#include "Dr41Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr41Doc

IMPLEMENT_DYNCREATE(CDr41Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr41Doc, CDocument)
END_MESSAGE_MAP()


// CDr41Doc コンストラクション/デストラクション

CDr41Doc::CDr41Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr41Doc::~CDr41Doc()
{
}

BOOL CDr41Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr41Doc シリアル化

void CDr41Doc::Serialize(CArchive& ar)
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


// CDr41Doc 診断

#ifdef _DEBUG
void CDr41Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr41Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr41Doc コマンド
