// Dr49Doc.cpp : CDr49Doc クラスの実装
//

#include "stdafx.h"
#include "Dr49.h"

#include "Dr49Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr49Doc

IMPLEMENT_DYNCREATE(CDr49Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr49Doc, CDocument)
END_MESSAGE_MAP()


// CDr49Doc コンストラクション/デストラクション

CDr49Doc::CDr49Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr49Doc::~CDr49Doc()
{
}

BOOL CDr49Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr49Doc シリアル化

void CDr49Doc::Serialize(CArchive& ar)
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


// CDr49Doc 診断

#ifdef _DEBUG
void CDr49Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr49Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr49Doc コマンド
