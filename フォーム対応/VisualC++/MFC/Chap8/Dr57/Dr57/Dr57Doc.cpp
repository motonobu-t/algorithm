// Dr57Doc.cpp : CDr57Doc クラスの実装
//

#include "stdafx.h"
#include "Dr57.h"

#include "Dr57Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr57Doc

IMPLEMENT_DYNCREATE(CDr57Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr57Doc, CDocument)
END_MESSAGE_MAP()


// CDr57Doc コンストラクション/デストラクション

CDr57Doc::CDr57Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr57Doc::~CDr57Doc()
{
}

BOOL CDr57Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr57Doc シリアル化

void CDr57Doc::Serialize(CArchive& ar)
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


// CDr57Doc 診断

#ifdef _DEBUG
void CDr57Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr57Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr57Doc コマンド
