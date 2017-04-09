// Dr9Doc.cpp : CDr9Doc クラスの実装
//

#include "stdafx.h"
#include "Dr9.h"

#include "Dr9Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr9Doc

IMPLEMENT_DYNCREATE(CDr9Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr9Doc, CDocument)
END_MESSAGE_MAP()


// CDr9Doc コンストラクション/デストラクション

CDr9Doc::CDr9Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr9Doc::~CDr9Doc()
{
}

BOOL CDr9Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr9Doc シリアル化

void CDr9Doc::Serialize(CArchive& ar)
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


// CDr9Doc 診断

#ifdef _DEBUG
void CDr9Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr9Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr9Doc コマンド
