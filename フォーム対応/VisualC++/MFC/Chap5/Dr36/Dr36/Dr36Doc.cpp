// Dr36Doc.cpp : CDr36Doc クラスの実装
//

#include "stdafx.h"
#include "Dr36.h"

#include "Dr36Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr36Doc

IMPLEMENT_DYNCREATE(CDr36Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr36Doc, CDocument)
END_MESSAGE_MAP()


// CDr36Doc コンストラクション/デストラクション

CDr36Doc::CDr36Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr36Doc::~CDr36Doc()
{
}

BOOL CDr36Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr36Doc シリアル化

void CDr36Doc::Serialize(CArchive& ar)
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


// CDr36Doc 診断

#ifdef _DEBUG
void CDr36Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr36Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr36Doc コマンド
