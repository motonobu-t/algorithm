// Rei35Doc.cpp : CRei35Doc クラスの実装
//

#include "stdafx.h"
#include "Rei35.h"

#include "Rei35Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei35Doc

IMPLEMENT_DYNCREATE(CRei35Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei35Doc, CDocument)
END_MESSAGE_MAP()


// CRei35Doc コンストラクション/デストラクション

CRei35Doc::CRei35Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei35Doc::~CRei35Doc()
{
}

BOOL CRei35Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei35Doc シリアル化

void CRei35Doc::Serialize(CArchive& ar)
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


// CRei35Doc 診断

#ifdef _DEBUG
void CRei35Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei35Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei35Doc コマンド
