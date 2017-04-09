// Dr10_2Doc.cpp : CDr10_2Doc クラスの実装
//

#include "stdafx.h"
#include "Dr10_2.h"

#include "Dr10_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr10_2Doc

IMPLEMENT_DYNCREATE(CDr10_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr10_2Doc, CDocument)
END_MESSAGE_MAP()


// CDr10_2Doc コンストラクション/デストラクション

CDr10_2Doc::CDr10_2Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr10_2Doc::~CDr10_2Doc()
{
}

BOOL CDr10_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr10_2Doc シリアル化

void CDr10_2Doc::Serialize(CArchive& ar)
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


// CDr10_2Doc 診断

#ifdef _DEBUG
void CDr10_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr10_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr10_2Doc コマンド
