// Dr27Doc.cpp : CDr27Doc クラスの実装
//

#include "stdafx.h"
#include "Dr27.h"

#include "Dr27Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr27Doc

IMPLEMENT_DYNCREATE(CDr27Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr27Doc, CDocument)
END_MESSAGE_MAP()


// CDr27Doc コンストラクション/デストラクション

CDr27Doc::CDr27Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr27Doc::~CDr27Doc()
{
}

BOOL CDr27Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr27Doc シリアル化

void CDr27Doc::Serialize(CArchive& ar)
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


// CDr27Doc 診断

#ifdef _DEBUG
void CDr27Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr27Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr27Doc コマンド
