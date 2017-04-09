// Dr5Doc.cpp : CDr5Doc クラスの実装
//

#include "stdafx.h"
#include "Dr5.h"

#include "Dr5Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr5Doc

IMPLEMENT_DYNCREATE(CDr5Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr5Doc, CDocument)
END_MESSAGE_MAP()


// CDr5Doc コンストラクション/デストラクション

CDr5Doc::CDr5Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr5Doc::~CDr5Doc()
{
}

BOOL CDr5Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr5Doc シリアル化

void CDr5Doc::Serialize(CArchive& ar)
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


// CDr5Doc 診断

#ifdef _DEBUG
void CDr5Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr5Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr5Doc コマンド
