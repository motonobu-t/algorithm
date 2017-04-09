// Dr64Doc.cpp : CDr64Doc クラスの実装
//

#include "stdafx.h"
#include "Dr64.h"

#include "Dr64Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr64Doc

IMPLEMENT_DYNCREATE(CDr64Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr64Doc, CDocument)
END_MESSAGE_MAP()


// CDr64Doc コンストラクション/デストラクション

CDr64Doc::CDr64Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr64Doc::~CDr64Doc()
{
}

BOOL CDr64Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr64Doc シリアル化

void CDr64Doc::Serialize(CArchive& ar)
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


// CDr64Doc 診断

#ifdef _DEBUG
void CDr64Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr64Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr64Doc コマンド
