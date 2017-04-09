// Dr61Doc.cpp : CDr61Doc クラスの実装
//

#include "stdafx.h"
#include "Dr61.h"

#include "Dr61Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr61Doc

IMPLEMENT_DYNCREATE(CDr61Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr61Doc, CDocument)
END_MESSAGE_MAP()


// CDr61Doc コンストラクション/デストラクション

CDr61Doc::CDr61Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr61Doc::~CDr61Doc()
{
}

BOOL CDr61Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr61Doc シリアル化

void CDr61Doc::Serialize(CArchive& ar)
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


// CDr61Doc 診断

#ifdef _DEBUG
void CDr61Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr61Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr61Doc コマンド
