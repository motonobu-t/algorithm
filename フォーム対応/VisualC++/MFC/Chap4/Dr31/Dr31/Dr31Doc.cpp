// Dr31Doc.cpp : CDr31Doc クラスの実装
//

#include "stdafx.h"
#include "Dr31.h"

#include "Dr31Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr31Doc

IMPLEMENT_DYNCREATE(CDr31Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr31Doc, CDocument)
END_MESSAGE_MAP()


// CDr31Doc コンストラクション/デストラクション

CDr31Doc::CDr31Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr31Doc::~CDr31Doc()
{
}

BOOL CDr31Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr31Doc シリアル化

void CDr31Doc::Serialize(CArchive& ar)
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


// CDr31Doc 診断

#ifdef _DEBUG
void CDr31Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr31Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr31Doc コマンド
