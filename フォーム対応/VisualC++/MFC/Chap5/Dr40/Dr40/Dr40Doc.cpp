// Dr40Doc.cpp : CDr40Doc クラスの実装
//

#include "stdafx.h"
#include "Dr40.h"

#include "Dr40Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr40Doc

IMPLEMENT_DYNCREATE(CDr40Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr40Doc, CDocument)
END_MESSAGE_MAP()


// CDr40Doc コンストラクション/デストラクション

CDr40Doc::CDr40Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr40Doc::~CDr40Doc()
{
}

BOOL CDr40Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr40Doc シリアル化

void CDr40Doc::Serialize(CArchive& ar)
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


// CDr40Doc 診断

#ifdef _DEBUG
void CDr40Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr40Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr40Doc コマンド
