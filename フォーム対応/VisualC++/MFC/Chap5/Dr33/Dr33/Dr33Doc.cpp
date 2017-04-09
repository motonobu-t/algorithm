// Dr33Doc.cpp : CDr33Doc クラスの実装
//

#include "stdafx.h"
#include "Dr33.h"

#include "Dr33Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr33Doc

IMPLEMENT_DYNCREATE(CDr33Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr33Doc, CDocument)
END_MESSAGE_MAP()


// CDr33Doc コンストラクション/デストラクション

CDr33Doc::CDr33Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr33Doc::~CDr33Doc()
{
}

BOOL CDr33Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr33Doc シリアル化

void CDr33Doc::Serialize(CArchive& ar)
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


// CDr33Doc 診断

#ifdef _DEBUG
void CDr33Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr33Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr33Doc コマンド
