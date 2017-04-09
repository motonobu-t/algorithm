// Dr29Doc.cpp : CDr29Doc クラスの実装
//

#include "stdafx.h"
#include "Dr29.h"

#include "Dr29Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr29Doc

IMPLEMENT_DYNCREATE(CDr29Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr29Doc, CDocument)
END_MESSAGE_MAP()


// CDr29Doc コンストラクション/デストラクション

CDr29Doc::CDr29Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr29Doc::~CDr29Doc()
{
}

BOOL CDr29Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr29Doc シリアル化

void CDr29Doc::Serialize(CArchive& ar)
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


// CDr29Doc 診断

#ifdef _DEBUG
void CDr29Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr29Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr29Doc コマンド
