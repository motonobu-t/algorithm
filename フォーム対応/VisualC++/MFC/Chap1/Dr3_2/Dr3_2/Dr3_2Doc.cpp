// Dr3_2Doc.cpp : CDr3_2Doc クラスの実装
//

#include "stdafx.h"
#include "Dr3_2.h"

#include "Dr3_2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr3_2Doc

IMPLEMENT_DYNCREATE(CDr3_2Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr3_2Doc, CDocument)
END_MESSAGE_MAP()


// CDr3_2Doc コンストラクション/デストラクション

CDr3_2Doc::CDr3_2Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr3_2Doc::~CDr3_2Doc()
{
}

BOOL CDr3_2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr3_2Doc シリアル化

void CDr3_2Doc::Serialize(CArchive& ar)
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


// CDr3_2Doc 診断

#ifdef _DEBUG
void CDr3_2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr3_2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr3_2Doc コマンド
