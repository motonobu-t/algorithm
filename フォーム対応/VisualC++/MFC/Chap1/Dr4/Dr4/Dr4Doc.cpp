// Dr4Doc.cpp : CDr4Doc クラスの実装
//

#include "stdafx.h"
#include "Dr4.h"

#include "Dr4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr4Doc

IMPLEMENT_DYNCREATE(CDr4Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr4Doc, CDocument)
END_MESSAGE_MAP()


// CDr4Doc コンストラクション/デストラクション

CDr4Doc::CDr4Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr4Doc::~CDr4Doc()
{
}

BOOL CDr4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr4Doc シリアル化

void CDr4Doc::Serialize(CArchive& ar)
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


// CDr4Doc 診断

#ifdef _DEBUG
void CDr4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr4Doc コマンド
