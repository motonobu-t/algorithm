// Rei62Doc.cpp : CRei62Doc クラスの実装
//

#include "stdafx.h"
#include "Rei62.h"

#include "Rei62Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei62Doc

IMPLEMENT_DYNCREATE(CRei62Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei62Doc, CDocument)
END_MESSAGE_MAP()


// CRei62Doc コンストラクション/デストラクション

CRei62Doc::CRei62Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei62Doc::~CRei62Doc()
{
}

BOOL CRei62Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei62Doc シリアル化

void CRei62Doc::Serialize(CArchive& ar)
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


// CRei62Doc 診断

#ifdef _DEBUG
void CRei62Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei62Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei62Doc コマンド
