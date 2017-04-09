// Dr25Doc.cpp : CDr25Doc クラスの実装
//

#include "stdafx.h"
#include "Dr25.h"

#include "Dr25Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr25Doc

IMPLEMENT_DYNCREATE(CDr25Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr25Doc, CDocument)
END_MESSAGE_MAP()


// CDr25Doc コンストラクション/デストラクション

CDr25Doc::CDr25Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr25Doc::~CDr25Doc()
{
}

BOOL CDr25Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr25Doc シリアル化

void CDr25Doc::Serialize(CArchive& ar)
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


// CDr25Doc 診断

#ifdef _DEBUG
void CDr25Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr25Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr25Doc コマンド
