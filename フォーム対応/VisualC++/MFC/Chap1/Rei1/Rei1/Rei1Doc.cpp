// Rei1Doc.cpp : CRei1Doc クラスの実装
//

#include "stdafx.h"
#include "Rei1.h"

#include "Rei1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei1Doc

IMPLEMENT_DYNCREATE(CRei1Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei1Doc, CDocument)
END_MESSAGE_MAP()


// CRei1Doc コンストラクション/デストラクション

CRei1Doc::CRei1Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei1Doc::~CRei1Doc()
{
}

BOOL CRei1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei1Doc シリアル化

void CRei1Doc::Serialize(CArchive& ar)
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


// CRei1Doc 診断

#ifdef _DEBUG
void CRei1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei1Doc コマンド
