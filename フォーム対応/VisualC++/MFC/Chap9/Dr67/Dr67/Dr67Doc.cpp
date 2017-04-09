// Dr67Doc.cpp : CDr67Doc クラスの実装
//

#include "stdafx.h"
#include "Dr67.h"

#include "Dr67Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr67Doc

IMPLEMENT_DYNCREATE(CDr67Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr67Doc, CDocument)
END_MESSAGE_MAP()


// CDr67Doc コンストラクション/デストラクション

CDr67Doc::CDr67Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr67Doc::~CDr67Doc()
{
}

BOOL CDr67Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr67Doc シリアル化

void CDr67Doc::Serialize(CArchive& ar)
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


// CDr67Doc 診断

#ifdef _DEBUG
void CDr67Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr67Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr67Doc コマンド
