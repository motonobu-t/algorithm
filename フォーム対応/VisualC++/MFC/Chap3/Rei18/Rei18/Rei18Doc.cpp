// Rei18Doc.cpp : CRei18Doc クラスの実装
//

#include "stdafx.h"
#include "Rei18.h"

#include "Rei18Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei18Doc

IMPLEMENT_DYNCREATE(CRei18Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei18Doc, CDocument)
END_MESSAGE_MAP()


// CRei18Doc コンストラクション/デストラクション

CRei18Doc::CRei18Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei18Doc::~CRei18Doc()
{
}

BOOL CRei18Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei18Doc シリアル化

void CRei18Doc::Serialize(CArchive& ar)
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


// CRei18Doc 診断

#ifdef _DEBUG
void CRei18Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei18Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei18Doc コマンド
