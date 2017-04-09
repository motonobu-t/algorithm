// Rei41Doc.cpp : CRei41Doc クラスの実装
//

#include "stdafx.h"
#include "Rei41.h"

#include "Rei41Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei41Doc

IMPLEMENT_DYNCREATE(CRei41Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei41Doc, CDocument)
END_MESSAGE_MAP()


// CRei41Doc コンストラクション/デストラクション

CRei41Doc::CRei41Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei41Doc::~CRei41Doc()
{
}

BOOL CRei41Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei41Doc シリアル化

void CRei41Doc::Serialize(CArchive& ar)
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


// CRei41Doc 診断

#ifdef _DEBUG
void CRei41Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei41Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei41Doc コマンド
