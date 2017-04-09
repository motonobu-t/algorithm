// Dr18_3Doc.cpp : CDr18_3Doc クラスの実装
//

#include "stdafx.h"
#include "Dr18_3.h"

#include "Dr18_3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr18_3Doc

IMPLEMENT_DYNCREATE(CDr18_3Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr18_3Doc, CDocument)
END_MESSAGE_MAP()


// CDr18_3Doc コンストラクション/デストラクション

CDr18_3Doc::CDr18_3Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr18_3Doc::~CDr18_3Doc()
{
}

BOOL CDr18_3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr18_3Doc シリアル化

void CDr18_3Doc::Serialize(CArchive& ar)
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


// CDr18_3Doc 診断

#ifdef _DEBUG
void CDr18_3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr18_3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr18_3Doc コマンド
