// Dr66ListBoxDoc.cpp : CDr66ListBoxDoc クラスの実装
//

#include "stdafx.h"
#include "Dr66ListBox.h"

#include "Dr66ListBoxDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr66ListBoxDoc

IMPLEMENT_DYNCREATE(CDr66ListBoxDoc, CDocument)

BEGIN_MESSAGE_MAP(CDr66ListBoxDoc, CDocument)
END_MESSAGE_MAP()


// CDr66ListBoxDoc コンストラクション/デストラクション

CDr66ListBoxDoc::CDr66ListBoxDoc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr66ListBoxDoc::~CDr66ListBoxDoc()
{
}

BOOL CDr66ListBoxDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr66ListBoxDoc シリアル化

void CDr66ListBoxDoc::Serialize(CArchive& ar)
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


// CDr66ListBoxDoc 診断

#ifdef _DEBUG
void CDr66ListBoxDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr66ListBoxDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr66ListBoxDoc コマンド
