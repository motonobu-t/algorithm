// Dr26_3Doc.cpp : CDr26_3Doc クラスの実装
//

#include "stdafx.h"
#include "Dr26_3.h"

#include "Dr26_3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr26_3Doc

IMPLEMENT_DYNCREATE(CDr26_3Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr26_3Doc, CDocument)
END_MESSAGE_MAP()


// CDr26_3Doc コンストラクション/デストラクション

CDr26_3Doc::CDr26_3Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr26_3Doc::~CDr26_3Doc()
{
}

BOOL CDr26_3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr26_3Doc シリアル化

void CDr26_3Doc::Serialize(CArchive& ar)
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


// CDr26_3Doc 診断

#ifdef _DEBUG
void CDr26_3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr26_3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr26_3Doc コマンド
