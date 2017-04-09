// Rei27Doc.cpp : CRei27Doc クラスの実装
//

#include "stdafx.h"
#include "Rei27.h"

#include "Rei27Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei27Doc

IMPLEMENT_DYNCREATE(CRei27Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei27Doc, CDocument)
END_MESSAGE_MAP()


// CRei27Doc コンストラクション/デストラクション

CRei27Doc::CRei27Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei27Doc::~CRei27Doc()
{
}

BOOL CRei27Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei27Doc シリアル化

void CRei27Doc::Serialize(CArchive& ar)
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


// CRei27Doc 診断

#ifdef _DEBUG
void CRei27Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei27Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei27Doc コマンド
