// Rei2Doc.cpp : CRei2Doc クラスの実装
//

#include "stdafx.h"
#include "Rei2.h"

#include "Rei2Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei2Doc

IMPLEMENT_DYNCREATE(CRei2Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei2Doc, CDocument)
END_MESSAGE_MAP()


// CRei2Doc コンストラクション/デストラクション

CRei2Doc::CRei2Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei2Doc::~CRei2Doc()
{
}

BOOL CRei2Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei2Doc シリアル化

void CRei2Doc::Serialize(CArchive& ar)
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


// CRei2Doc 診断

#ifdef _DEBUG
void CRei2Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei2Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei2Doc コマンド
