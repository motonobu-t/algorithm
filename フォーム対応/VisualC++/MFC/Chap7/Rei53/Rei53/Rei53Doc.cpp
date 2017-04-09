// Rei53Doc.cpp : CRei53Doc クラスの実装
//

#include "stdafx.h"
#include "Rei53.h"

#include "Rei53Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei53Doc

IMPLEMENT_DYNCREATE(CRei53Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei53Doc, CDocument)
END_MESSAGE_MAP()


// CRei53Doc コンストラクション/デストラクション

CRei53Doc::CRei53Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei53Doc::~CRei53Doc()
{
}

BOOL CRei53Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei53Doc シリアル化

void CRei53Doc::Serialize(CArchive& ar)
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


// CRei53Doc 診断

#ifdef _DEBUG
void CRei53Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei53Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei53Doc コマンド
