// Rei31Doc.cpp : CRei31Doc クラスの実装
//

#include "stdafx.h"
#include "Rei31.h"

#include "Rei31Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei31Doc

IMPLEMENT_DYNCREATE(CRei31Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei31Doc, CDocument)
END_MESSAGE_MAP()


// CRei31Doc コンストラクション/デストラクション

CRei31Doc::CRei31Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei31Doc::~CRei31Doc()
{
}

BOOL CRei31Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei31Doc シリアル化

void CRei31Doc::Serialize(CArchive& ar)
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


// CRei31Doc 診断

#ifdef _DEBUG
void CRei31Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei31Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei31Doc コマンド
