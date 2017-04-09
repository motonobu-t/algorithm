// Dr62_2Doc.cpp : CDr62_2Doc クラスの実装
//

#include "stdafx.h"
#include "Dr62_2.h"

#include "Dr62_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr62_2Doc

IMPLEMENT_DYNCREATE(CDr62_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr62_2Doc, CDocument)
END_MESSAGE_MAP()


// CDr62_2Doc コンストラクション/デストラクション

CDr62_2Doc::CDr62_2Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr62_2Doc::~CDr62_2Doc()
{
}

BOOL CDr62_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr62_2Doc シリアル化

void CDr62_2Doc::Serialize(CArchive& ar)
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


// CDr62_2Doc 診断

#ifdef _DEBUG
void CDr62_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr62_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr62_2Doc コマンド
