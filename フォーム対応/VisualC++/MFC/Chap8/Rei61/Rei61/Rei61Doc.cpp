// Rei61Doc.cpp : CRei61Doc クラスの実装
//

#include "stdafx.h"
#include "Rei61.h"

#include "Rei61Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei61Doc

IMPLEMENT_DYNCREATE(CRei61Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei61Doc, CDocument)
END_MESSAGE_MAP()


// CRei61Doc コンストラクション/デストラクション

CRei61Doc::CRei61Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei61Doc::~CRei61Doc()
{
}

BOOL CRei61Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei61Doc シリアル化

void CRei61Doc::Serialize(CArchive& ar)
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


// CRei61Doc 診断

#ifdef _DEBUG
void CRei61Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei61Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei61Doc コマンド
