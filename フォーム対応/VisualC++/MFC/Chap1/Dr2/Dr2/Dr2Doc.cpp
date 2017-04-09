// Dr2Doc.cpp : CDr2Doc クラスの実装
//

#include "stdafx.h"
#include "Dr2.h"

#include "Dr2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr2Doc

IMPLEMENT_DYNCREATE(CDr2Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr2Doc, CDocument)
END_MESSAGE_MAP()


// CDr2Doc コンストラクション/デストラクション

CDr2Doc::CDr2Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr2Doc::~CDr2Doc()
{
}

BOOL CDr2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr2Doc シリアル化

void CDr2Doc::Serialize(CArchive& ar)
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


// CDr2Doc 診断

#ifdef _DEBUG
void CDr2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr2Doc コマンド
