// Rei25Doc.cpp : CRei25Doc クラスの実装
//

#include "stdafx.h"
#include "Rei25.h"

#include "Rei25Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei25Doc

IMPLEMENT_DYNCREATE(CRei25Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei25Doc, CDocument)
END_MESSAGE_MAP()


// CRei25Doc コンストラクション/デストラクション

CRei25Doc::CRei25Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei25Doc::~CRei25Doc()
{
}

BOOL CRei25Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei25Doc シリアル化

void CRei25Doc::Serialize(CArchive& ar)
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


// CRei25Doc 診断

#ifdef _DEBUG
void CRei25Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei25Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei25Doc コマンド
