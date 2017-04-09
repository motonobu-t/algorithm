// Dr30_3Doc.cpp : CDr30_3Doc クラスの実装
//

#include "stdafx.h"
#include "Dr30_3.h"

#include "Dr30_3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr30_3Doc

IMPLEMENT_DYNCREATE(CDr30_3Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr30_3Doc, CDocument)
END_MESSAGE_MAP()


// CDr30_3Doc コンストラクション/デストラクション

CDr30_3Doc::CDr30_3Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr30_3Doc::~CDr30_3Doc()
{
}

BOOL CDr30_3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr30_3Doc シリアル化

void CDr30_3Doc::Serialize(CArchive& ar)
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


// CDr30_3Doc 診断

#ifdef _DEBUG
void CDr30_3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr30_3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr30_3Doc コマンド
