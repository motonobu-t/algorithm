// Dr17MFCDoc.cpp : CDr17MFCDoc クラスの実装
//

#include "stdafx.h"
#include "Dr17MFC.h"

#include "Dr17MFCDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr17MFCDoc

IMPLEMENT_DYNCREATE(CDr17MFCDoc, CDocument)

BEGIN_MESSAGE_MAP(CDr17MFCDoc, CDocument)
END_MESSAGE_MAP()


// CDr17MFCDoc コンストラクション/デストラクション

CDr17MFCDoc::CDr17MFCDoc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr17MFCDoc::~CDr17MFCDoc()
{
}

BOOL CDr17MFCDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr17MFCDoc シリアル化

void CDr17MFCDoc::Serialize(CArchive& ar)
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


// CDr17MFCDoc 診断

#ifdef _DEBUG
void CDr17MFCDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr17MFCDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr17MFCDoc コマンド
