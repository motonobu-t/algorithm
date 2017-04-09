// Dr58Doc.cpp : CDr58Doc クラスの実装
//

#include "stdafx.h"
#include "Dr58.h"

#include "Dr58Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr58Doc

IMPLEMENT_DYNCREATE(CDr58Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr58Doc, CDocument)
END_MESSAGE_MAP()


// CDr58Doc コンストラクション/デストラクション

CDr58Doc::CDr58Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr58Doc::~CDr58Doc()
{
}

BOOL CDr58Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr58Doc シリアル化

void CDr58Doc::Serialize(CArchive& ar)
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


// CDr58Doc 診断

#ifdef _DEBUG
void CDr58Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr58Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr58Doc コマンド
