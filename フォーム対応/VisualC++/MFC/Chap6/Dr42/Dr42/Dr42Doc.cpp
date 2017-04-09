// Dr42Doc.cpp : CDr42Doc クラスの実装
//

#include "stdafx.h"
#include "Dr42.h"

#include "Dr42Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr42Doc

IMPLEMENT_DYNCREATE(CDr42Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr42Doc, CDocument)
END_MESSAGE_MAP()


// CDr42Doc コンストラクション/デストラクション

CDr42Doc::CDr42Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr42Doc::~CDr42Doc()
{
}

BOOL CDr42Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr42Doc シリアル化

void CDr42Doc::Serialize(CArchive& ar)
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


// CDr42Doc 診断

#ifdef _DEBUG
void CDr42Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr42Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr42Doc コマンド
