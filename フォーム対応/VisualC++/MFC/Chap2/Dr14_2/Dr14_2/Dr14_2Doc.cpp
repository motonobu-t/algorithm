// Dr14_2Doc.cpp : CDr14_2Doc クラスの実装
//

#include "stdafx.h"
#include "Dr14_2.h"

#include "Dr14_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr14_2Doc

IMPLEMENT_DYNCREATE(CDr14_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr14_2Doc, CDocument)
END_MESSAGE_MAP()


// CDr14_2Doc コンストラクション/デストラクション

CDr14_2Doc::CDr14_2Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr14_2Doc::~CDr14_2Doc()
{
}

BOOL CDr14_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr14_2Doc シリアル化

void CDr14_2Doc::Serialize(CArchive& ar)
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


// CDr14_2Doc 診断

#ifdef _DEBUG
void CDr14_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr14_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr14_2Doc コマンド
