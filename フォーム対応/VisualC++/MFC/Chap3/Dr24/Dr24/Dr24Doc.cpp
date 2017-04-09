// Dr24Doc.cpp : CDr24Doc クラスの実装
//

#include "stdafx.h"
#include "Dr24.h"

#include "Dr24Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr24Doc

IMPLEMENT_DYNCREATE(CDr24Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr24Doc, CDocument)
END_MESSAGE_MAP()


// CDr24Doc コンストラクション/デストラクション

CDr24Doc::CDr24Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr24Doc::~CDr24Doc()
{
}

BOOL CDr24Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr24Doc シリアル化

void CDr24Doc::Serialize(CArchive& ar)
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


// CDr24Doc 診断

#ifdef _DEBUG
void CDr24Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr24Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr24Doc コマンド
