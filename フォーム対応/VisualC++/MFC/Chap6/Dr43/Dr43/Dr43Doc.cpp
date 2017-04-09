// Dr43Doc.cpp : CDr43Doc クラスの実装
//

#include "stdafx.h"
#include "Dr43.h"

#include "Dr43Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr43Doc

IMPLEMENT_DYNCREATE(CDr43Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr43Doc, CDocument)
END_MESSAGE_MAP()


// CDr43Doc コンストラクション/デストラクション

CDr43Doc::CDr43Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr43Doc::~CDr43Doc()
{
}

BOOL CDr43Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr43Doc シリアル化

void CDr43Doc::Serialize(CArchive& ar)
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


// CDr43Doc 診断

#ifdef _DEBUG
void CDr43Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr43Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr43Doc コマンド
