// Dr63_4Doc.cpp : CDr63_4Doc クラスの実装
//

#include "stdafx.h"
#include "Dr63_4.h"

#include "Dr63_4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr63_4Doc

IMPLEMENT_DYNCREATE(CDr63_4Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr63_4Doc, CDocument)
END_MESSAGE_MAP()


// CDr63_4Doc コンストラクション/デストラクション

CDr63_4Doc::CDr63_4Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr63_4Doc::~CDr63_4Doc()
{
}

BOOL CDr63_4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr63_4Doc シリアル化

void CDr63_4Doc::Serialize(CArchive& ar)
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


// CDr63_4Doc 診断

#ifdef _DEBUG
void CDr63_4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr63_4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr63_4Doc コマンド
