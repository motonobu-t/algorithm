// Dr37Doc.cpp : CDr37Doc クラスの実装
//

#include "stdafx.h"
#include "Dr37.h"

#include "Dr37Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr37Doc

IMPLEMENT_DYNCREATE(CDr37Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr37Doc, CDocument)
END_MESSAGE_MAP()


// CDr37Doc コンストラクション/デストラクション

CDr37Doc::CDr37Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr37Doc::~CDr37Doc()
{
}

BOOL CDr37Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr37Doc シリアル化

void CDr37Doc::Serialize(CArchive& ar)
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


// CDr37Doc 診断

#ifdef _DEBUG
void CDr37Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr37Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr37Doc コマンド
