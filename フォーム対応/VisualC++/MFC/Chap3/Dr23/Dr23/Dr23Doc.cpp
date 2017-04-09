// Dr23Doc.cpp : CDr23Doc クラスの実装
//

#include "stdafx.h"
#include "Dr23.h"

#include "Dr23Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr23Doc

IMPLEMENT_DYNCREATE(CDr23Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr23Doc, CDocument)
END_MESSAGE_MAP()


// CDr23Doc コンストラクション/デストラクション

CDr23Doc::CDr23Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr23Doc::~CDr23Doc()
{
}

BOOL CDr23Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr23Doc シリアル化

void CDr23Doc::Serialize(CArchive& ar)
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


// CDr23Doc 診断

#ifdef _DEBUG
void CDr23Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr23Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr23Doc コマンド
