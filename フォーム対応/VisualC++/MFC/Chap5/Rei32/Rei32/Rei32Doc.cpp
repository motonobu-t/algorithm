// Rei32Doc.cpp : CRei32Doc クラスの実装
//

#include "stdafx.h"
#include "Rei32.h"

#include "Rei32Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei32Doc

IMPLEMENT_DYNCREATE(CRei32Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei32Doc, CDocument)
END_MESSAGE_MAP()


// CRei32Doc コンストラクション/デストラクション

CRei32Doc::CRei32Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei32Doc::~CRei32Doc()
{
}

BOOL CRei32Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei32Doc シリアル化

void CRei32Doc::Serialize(CArchive& ar)
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


// CRei32Doc 診断

#ifdef _DEBUG
void CRei32Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei32Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei32Doc コマンド
