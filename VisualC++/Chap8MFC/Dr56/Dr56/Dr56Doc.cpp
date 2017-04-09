// Dr56Doc.cpp : CDr56Doc クラスの実装
//

#include "stdafx.h"
#include "Dr56.h"

#include "Dr56Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr56Doc

IMPLEMENT_DYNCREATE(CDr56Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr56Doc, CDocument)
END_MESSAGE_MAP()


// CDr56Doc コンストラクション/デストラクション

CDr56Doc::CDr56Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr56Doc::~CDr56Doc()
{
}

BOOL CDr56Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr56Doc シリアル化

void CDr56Doc::Serialize(CArchive& ar)
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


// CDr56Doc 診断

#ifdef _DEBUG
void CDr56Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr56Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr56Doc コマンド
