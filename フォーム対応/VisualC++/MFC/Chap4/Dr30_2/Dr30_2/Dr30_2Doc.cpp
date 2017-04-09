// Dr30_2Doc.cpp : CDr30_2Doc クラスの実装
//

#include "stdafx.h"
#include "Dr30_2.h"

#include "Dr30_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr30_2Doc

IMPLEMENT_DYNCREATE(CDr30_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr30_2Doc, CDocument)
END_MESSAGE_MAP()


// CDr30_2Doc コンストラクション/デストラクション

CDr30_2Doc::CDr30_2Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr30_2Doc::~CDr30_2Doc()
{
}

BOOL CDr30_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr30_2Doc シリアル化

void CDr30_2Doc::Serialize(CArchive& ar)
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


// CDr30_2Doc 診断

#ifdef _DEBUG
void CDr30_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr30_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr30_2Doc コマンド
