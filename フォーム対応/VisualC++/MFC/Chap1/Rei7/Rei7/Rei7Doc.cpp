// Rei7Doc.cpp : CRei7Doc クラスの実装
//

#include "stdafx.h"
#include "Rei7.h"

#include "Rei7Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei7Doc

IMPLEMENT_DYNCREATE(CRei7Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei7Doc, CDocument)
END_MESSAGE_MAP()


// CRei7Doc コンストラクション/デストラクション

CRei7Doc::CRei7Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei7Doc::~CRei7Doc()
{
}

BOOL CRei7Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei7Doc シリアル化

void CRei7Doc::Serialize(CArchive& ar)
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


// CRei7Doc 診断

#ifdef _DEBUG
void CRei7Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei7Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei7Doc コマンド
