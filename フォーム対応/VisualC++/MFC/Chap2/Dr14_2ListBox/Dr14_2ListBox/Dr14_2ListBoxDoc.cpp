// Dr14_2ListBoxDoc.cpp : CDr14_2ListBoxDoc クラスの実装
//

#include "stdafx.h"
#include "Dr14_2ListBox.h"

#include "Dr14_2ListBoxDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr14_2ListBoxDoc

IMPLEMENT_DYNCREATE(CDr14_2ListBoxDoc, CDocument)

BEGIN_MESSAGE_MAP(CDr14_2ListBoxDoc, CDocument)
END_MESSAGE_MAP()


// CDr14_2ListBoxDoc コンストラクション/デストラクション

CDr14_2ListBoxDoc::CDr14_2ListBoxDoc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr14_2ListBoxDoc::~CDr14_2ListBoxDoc()
{
}

BOOL CDr14_2ListBoxDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr14_2ListBoxDoc シリアル化

void CDr14_2ListBoxDoc::Serialize(CArchive& ar)
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


// CDr14_2ListBoxDoc 診断

#ifdef _DEBUG
void CDr14_2ListBoxDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr14_2ListBoxDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr14_2ListBoxDoc コマンド
