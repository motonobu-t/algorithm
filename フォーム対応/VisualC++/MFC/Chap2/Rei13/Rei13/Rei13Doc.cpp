// Rei13Doc.cpp : CRei13Doc クラスの実装
//

#include "stdafx.h"
#include "Rei13.h"

#include "Rei13Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei13Doc

IMPLEMENT_DYNCREATE(CRei13Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei13Doc, CDocument)
END_MESSAGE_MAP()


// CRei13Doc コンストラクション/デストラクション

CRei13Doc::CRei13Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei13Doc::~CRei13Doc()
{
}

BOOL CRei13Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei13Doc シリアル化

void CRei13Doc::Serialize(CArchive& ar)
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


// CRei13Doc 診断

#ifdef _DEBUG
void CRei13Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei13Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei13Doc コマンド
