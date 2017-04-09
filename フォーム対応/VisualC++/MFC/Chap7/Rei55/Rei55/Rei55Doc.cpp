// Rei55Doc.cpp : CRei55Doc クラスの実装
//

#include "stdafx.h"
#include "Rei55.h"

#include "Rei55Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei55Doc

IMPLEMENT_DYNCREATE(CRei55Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei55Doc, CDocument)
END_MESSAGE_MAP()


// CRei55Doc コンストラクション/デストラクション

CRei55Doc::CRei55Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei55Doc::~CRei55Doc()
{
}

BOOL CRei55Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei55Doc シリアル化

void CRei55Doc::Serialize(CArchive& ar)
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


// CRei55Doc 診断

#ifdef _DEBUG
void CRei55Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei55Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei55Doc コマンド
