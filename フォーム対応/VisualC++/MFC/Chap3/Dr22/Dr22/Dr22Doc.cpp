// Dr22Doc.cpp : CDr22Doc クラスの実装
//

#include "stdafx.h"
#include "Dr22.h"

#include "Dr22Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr22Doc

IMPLEMENT_DYNCREATE(CDr22Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr22Doc, CDocument)
END_MESSAGE_MAP()


// CDr22Doc コンストラクション/デストラクション

CDr22Doc::CDr22Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr22Doc::~CDr22Doc()
{
}

BOOL CDr22Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr22Doc シリアル化

void CDr22Doc::Serialize(CArchive& ar)
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


// CDr22Doc 診断

#ifdef _DEBUG
void CDr22Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr22Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr22Doc コマンド
