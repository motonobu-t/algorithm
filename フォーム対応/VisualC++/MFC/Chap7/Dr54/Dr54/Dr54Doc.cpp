// Dr54Doc.cpp : CDr54Doc クラスの実装
//

#include "stdafx.h"
#include "Dr54.h"

#include "Dr54Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr54Doc

IMPLEMENT_DYNCREATE(CDr54Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr54Doc, CDocument)
END_MESSAGE_MAP()


// CDr54Doc コンストラクション/デストラクション

CDr54Doc::CDr54Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr54Doc::~CDr54Doc()
{
}

BOOL CDr54Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr54Doc シリアル化

void CDr54Doc::Serialize(CArchive& ar)
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


// CDr54Doc 診断

#ifdef _DEBUG
void CDr54Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr54Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr54Doc コマンド
