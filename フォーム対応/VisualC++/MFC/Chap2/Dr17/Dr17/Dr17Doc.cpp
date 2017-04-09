// Dr17Doc.cpp : CDr17Doc クラスの実装
//

#include "stdafx.h"
#include "Dr17.h"

#include "Dr17Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr17Doc

IMPLEMENT_DYNCREATE(CDr17Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr17Doc, CDocument)
END_MESSAGE_MAP()


// CDr17Doc コンストラクション/デストラクション

CDr17Doc::CDr17Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr17Doc::~CDr17Doc()
{
}

BOOL CDr17Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr17Doc シリアル化

void CDr17Doc::Serialize(CArchive& ar)
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


// CDr17Doc 診断

#ifdef _DEBUG
void CDr17Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr17Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr17Doc コマンド
