// Dr47Doc.cpp : CDr47Doc クラスの実装
//

#include "stdafx.h"
#include "Dr47.h"

#include "Dr47Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr47Doc

IMPLEMENT_DYNCREATE(CDr47Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr47Doc, CDocument)
END_MESSAGE_MAP()


// CDr47Doc コンストラクション/デストラクション

CDr47Doc::CDr47Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr47Doc::~CDr47Doc()
{
}

BOOL CDr47Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr47Doc シリアル化

void CDr47Doc::Serialize(CArchive& ar)
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


// CDr47Doc 診断

#ifdef _DEBUG
void CDr47Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr47Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr47Doc コマンド
