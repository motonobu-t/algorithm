// Rei50Doc.cpp : CRei50Doc クラスの実装
//

#include "stdafx.h"
#include "Rei50.h"

#include "Rei50Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei50Doc

IMPLEMENT_DYNCREATE(CRei50Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei50Doc, CDocument)
END_MESSAGE_MAP()


// CRei50Doc コンストラクション/デストラクション

CRei50Doc::CRei50Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei50Doc::~CRei50Doc()
{
}

BOOL CRei50Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei50Doc シリアル化

void CRei50Doc::Serialize(CArchive& ar)
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


// CRei50Doc 診断

#ifdef _DEBUG
void CRei50Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei50Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei50Doc コマンド
