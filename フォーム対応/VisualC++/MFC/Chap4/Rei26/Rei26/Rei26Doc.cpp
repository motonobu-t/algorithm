// Rei26Doc.cpp : CRei26Doc クラスの実装
//

#include "stdafx.h"
#include "Rei26.h"

#include "Rei26Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei26Doc

IMPLEMENT_DYNCREATE(CRei26Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei26Doc, CDocument)
END_MESSAGE_MAP()


// CRei26Doc コンストラクション/デストラクション

CRei26Doc::CRei26Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei26Doc::~CRei26Doc()
{
}

BOOL CRei26Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei26Doc シリアル化

void CRei26Doc::Serialize(CArchive& ar)
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


// CRei26Doc 診断

#ifdef _DEBUG
void CRei26Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei26Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei26Doc コマンド
