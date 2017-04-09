// Dr20_3Doc.cpp : CDr20_3Doc クラスの実装
//

#include "stdafx.h"
#include "Dr20_3.h"

#include "Dr20_3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr20_3Doc

IMPLEMENT_DYNCREATE(CDr20_3Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr20_3Doc, CDocument)
END_MESSAGE_MAP()


// CDr20_3Doc コンストラクション/デストラクション

CDr20_3Doc::CDr20_3Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr20_3Doc::~CDr20_3Doc()
{
}

BOOL CDr20_3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr20_3Doc シリアル化

void CDr20_3Doc::Serialize(CArchive& ar)
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


// CDr20_3Doc 診断

#ifdef _DEBUG
void CDr20_3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr20_3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr20_3Doc コマンド
