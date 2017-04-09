// Dr50_2Doc.cpp : CDr50_2Doc クラスの実装
//

#include "stdafx.h"
#include "Dr50_2.h"

#include "Dr50_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr50_2Doc

IMPLEMENT_DYNCREATE(CDr50_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr50_2Doc, CDocument)
END_MESSAGE_MAP()


// CDr50_2Doc コンストラクション/デストラクション

CDr50_2Doc::CDr50_2Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr50_2Doc::~CDr50_2Doc()
{
}

BOOL CDr50_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr50_2Doc シリアル化

void CDr50_2Doc::Serialize(CArchive& ar)
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


// CDr50_2Doc 診断

#ifdef _DEBUG
void CDr50_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr50_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr50_2Doc コマンド
