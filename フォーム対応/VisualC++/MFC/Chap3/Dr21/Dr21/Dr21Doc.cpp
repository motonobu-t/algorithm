// Dr21Doc.cpp : CDr21Doc クラスの実装
//

#include "stdafx.h"
#include "Dr21.h"

#include "Dr21Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr21Doc

IMPLEMENT_DYNCREATE(CDr21Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr21Doc, CDocument)
END_MESSAGE_MAP()


// CDr21Doc コンストラクション/デストラクション

CDr21Doc::CDr21Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr21Doc::~CDr21Doc()
{
}

BOOL CDr21Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr21Doc シリアル化

void CDr21Doc::Serialize(CArchive& ar)
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


// CDr21Doc 診断

#ifdef _DEBUG
void CDr21Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr21Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr21Doc コマンド
