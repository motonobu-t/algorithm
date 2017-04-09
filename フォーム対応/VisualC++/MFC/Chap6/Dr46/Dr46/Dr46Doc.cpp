// Dr46Doc.cpp : CDr46Doc クラスの実装
//

#include "stdafx.h"
#include "Dr46.h"

#include "Dr46Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr46Doc

IMPLEMENT_DYNCREATE(CDr46Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr46Doc, CDocument)
END_MESSAGE_MAP()


// CDr46Doc コンストラクション/デストラクション

CDr46Doc::CDr46Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr46Doc::~CDr46Doc()
{
}

BOOL CDr46Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr46Doc シリアル化

void CDr46Doc::Serialize(CArchive& ar)
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


// CDr46Doc 診断

#ifdef _DEBUG
void CDr46Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr46Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr46Doc コマンド
