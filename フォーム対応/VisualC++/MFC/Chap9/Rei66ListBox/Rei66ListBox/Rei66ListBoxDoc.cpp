// Rei66ListBoxDoc.cpp : CRei66ListBoxDoc クラスの実装
//

#include "stdafx.h"
#include "Rei66ListBox.h"

#include "Rei66ListBoxDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei66ListBoxDoc

IMPLEMENT_DYNCREATE(CRei66ListBoxDoc, CDocument)

BEGIN_MESSAGE_MAP(CRei66ListBoxDoc, CDocument)
END_MESSAGE_MAP()


// CRei66ListBoxDoc コンストラクション/デストラクション

CRei66ListBoxDoc::CRei66ListBoxDoc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei66ListBoxDoc::~CRei66ListBoxDoc()
{
}

BOOL CRei66ListBoxDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei66ListBoxDoc シリアル化

void CRei66ListBoxDoc::Serialize(CArchive& ar)
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


// CRei66ListBoxDoc 診断

#ifdef _DEBUG
void CRei66ListBoxDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei66ListBoxDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei66ListBoxDoc コマンド
