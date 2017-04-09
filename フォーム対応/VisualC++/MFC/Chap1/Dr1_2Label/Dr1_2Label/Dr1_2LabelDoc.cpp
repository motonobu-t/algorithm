// Dr1_2LabelDoc.cpp : CDr1_2LabelDoc クラスの実装
//

#include "stdafx.h"
#include "Dr1_2Label.h"

#include "Dr1_2LabelDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr1_2LabelDoc

IMPLEMENT_DYNCREATE(CDr1_2LabelDoc, CDocument)

BEGIN_MESSAGE_MAP(CDr1_2LabelDoc, CDocument)
END_MESSAGE_MAP()


// CDr1_2LabelDoc コンストラクション/デストラクション

CDr1_2LabelDoc::CDr1_2LabelDoc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr1_2LabelDoc::~CDr1_2LabelDoc()
{
}

BOOL CDr1_2LabelDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr1_2LabelDoc シリアル化

void CDr1_2LabelDoc::Serialize(CArchive& ar)
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


// CDr1_2LabelDoc 診断

#ifdef _DEBUG
void CDr1_2LabelDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr1_2LabelDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr1_2LabelDoc コマンド
