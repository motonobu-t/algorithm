// Dr26_4Doc.cpp : CDr26_4Doc クラスの実装
//

#include "stdafx.h"
#include "Dr26_4.h"

#include "Dr26_4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr26_4Doc

IMPLEMENT_DYNCREATE(CDr26_4Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr26_4Doc, CDocument)
END_MESSAGE_MAP()


// CDr26_4Doc コンストラクション/デストラクション

CDr26_4Doc::CDr26_4Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr26_4Doc::~CDr26_4Doc()
{
}

BOOL CDr26_4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr26_4Doc シリアル化

void CDr26_4Doc::Serialize(CArchive& ar)
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


// CDr26_4Doc 診断

#ifdef _DEBUG
void CDr26_4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr26_4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr26_4Doc コマンド
