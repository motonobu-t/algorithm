// Rei10Doc.cpp : CRei10Doc クラスの実装
//

#include "stdafx.h"
#include "Rei10.h"

#include "Rei10Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei10Doc

IMPLEMENT_DYNCREATE(CRei10Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei10Doc, CDocument)
END_MESSAGE_MAP()


// CRei10Doc コンストラクション/デストラクション

CRei10Doc::CRei10Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei10Doc::~CRei10Doc()
{
}

BOOL CRei10Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei10Doc シリアル化

void CRei10Doc::Serialize(CArchive& ar)
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


// CRei10Doc 診断

#ifdef _DEBUG
void CRei10Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei10Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei10Doc コマンド
