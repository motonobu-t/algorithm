// Dr13Doc.cpp : CDr13Doc クラスの実装
//

#include "stdafx.h"
#include "Dr13.h"

#include "Dr13Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr13Doc

IMPLEMENT_DYNCREATE(CDr13Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr13Doc, CDocument)
END_MESSAGE_MAP()


// CDr13Doc コンストラクション/デストラクション

CDr13Doc::CDr13Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr13Doc::~CDr13Doc()
{
}

BOOL CDr13Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr13Doc シリアル化

void CDr13Doc::Serialize(CArchive& ar)
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


// CDr13Doc 診断

#ifdef _DEBUG
void CDr13Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr13Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr13Doc コマンド
