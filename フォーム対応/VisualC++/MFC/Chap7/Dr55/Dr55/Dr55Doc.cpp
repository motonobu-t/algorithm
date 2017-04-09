// Dr55Doc.cpp : CDr55Doc クラスの実装
//

#include "stdafx.h"
#include "Dr55.h"

#include "Dr55Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr55Doc

IMPLEMENT_DYNCREATE(CDr55Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr55Doc, CDocument)
END_MESSAGE_MAP()


// CDr55Doc コンストラクション/デストラクション

CDr55Doc::CDr55Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr55Doc::~CDr55Doc()
{
}

BOOL CDr55Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr55Doc シリアル化

void CDr55Doc::Serialize(CArchive& ar)
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


// CDr55Doc 診断

#ifdef _DEBUG
void CDr55Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr55Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr55Doc コマンド
