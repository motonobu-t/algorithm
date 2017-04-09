// Dr53Doc.cpp : CDr53Doc クラスの実装
//

#include "stdafx.h"
#include "Dr53.h"

#include "Dr53Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr53Doc

IMPLEMENT_DYNCREATE(CDr53Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr53Doc, CDocument)
END_MESSAGE_MAP()


// CDr53Doc コンストラクション/デストラクション

CDr53Doc::CDr53Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr53Doc::~CDr53Doc()
{
}

BOOL CDr53Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr53Doc シリアル化

void CDr53Doc::Serialize(CArchive& ar)
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


// CDr53Doc 診断

#ifdef _DEBUG
void CDr53Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr53Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr53Doc コマンド
