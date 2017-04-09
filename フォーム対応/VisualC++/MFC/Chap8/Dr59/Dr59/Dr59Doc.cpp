// Dr59Doc.cpp : CDr59Doc クラスの実装
//

#include "stdafx.h"
#include "Dr59.h"

#include "Dr59Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr59Doc

IMPLEMENT_DYNCREATE(CDr59Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr59Doc, CDocument)
END_MESSAGE_MAP()


// CDr59Doc コンストラクション/デストラクション

CDr59Doc::CDr59Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr59Doc::~CDr59Doc()
{
}

BOOL CDr59Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr59Doc シリアル化

void CDr59Doc::Serialize(CArchive& ar)
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


// CDr59Doc 診断

#ifdef _DEBUG
void CDr59Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr59Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr59Doc コマンド
