// Dr65Doc.cpp : CDr65Doc クラスの実装
//

#include "stdafx.h"
#include "Dr65.h"

#include "Dr65Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr65Doc

IMPLEMENT_DYNCREATE(CDr65Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr65Doc, CDocument)
END_MESSAGE_MAP()


// CDr65Doc コンストラクション/デストラクション

CDr65Doc::CDr65Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr65Doc::~CDr65Doc()
{
}

BOOL CDr65Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr65Doc シリアル化

void CDr65Doc::Serialize(CArchive& ar)
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


// CDr65Doc 診断

#ifdef _DEBUG
void CDr65Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr65Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr65Doc コマンド
