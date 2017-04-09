// Rei46Doc.cpp : CRei46Doc クラスの実装
//

#include "stdafx.h"
#include "Rei46.h"

#include "Rei46Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei46Doc

IMPLEMENT_DYNCREATE(CRei46Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei46Doc, CDocument)
END_MESSAGE_MAP()


// CRei46Doc コンストラクション/デストラクション

CRei46Doc::CRei46Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei46Doc::~CRei46Doc()
{
}

BOOL CRei46Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei46Doc シリアル化

void CRei46Doc::Serialize(CArchive& ar)
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


// CRei46Doc 診断

#ifdef _DEBUG
void CRei46Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei46Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei46Doc コマンド
