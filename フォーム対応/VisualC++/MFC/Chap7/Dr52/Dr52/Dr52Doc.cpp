// Dr52Doc.cpp : CDr52Doc クラスの実装
//

#include "stdafx.h"
#include "Dr52.h"

#include "Dr52Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr52Doc

IMPLEMENT_DYNCREATE(CDr52Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr52Doc, CDocument)
END_MESSAGE_MAP()


// CDr52Doc コンストラクション/デストラクション

CDr52Doc::CDr52Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr52Doc::~CDr52Doc()
{
}

BOOL CDr52Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr52Doc シリアル化

void CDr52Doc::Serialize(CArchive& ar)
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


// CDr52Doc 診断

#ifdef _DEBUG
void CDr52Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr52Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr52Doc コマンド
