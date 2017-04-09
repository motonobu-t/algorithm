// Rei42Doc.cpp : CRei42Doc クラスの実装
//

#include "stdafx.h"
#include "Rei42.h"

#include "Rei42Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei42Doc

IMPLEMENT_DYNCREATE(CRei42Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei42Doc, CDocument)
END_MESSAGE_MAP()


// CRei42Doc コンストラクション/デストラクション

CRei42Doc::CRei42Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei42Doc::~CRei42Doc()
{
}

BOOL CRei42Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei42Doc シリアル化

void CRei42Doc::Serialize(CArchive& ar)
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


// CRei42Doc 診断

#ifdef _DEBUG
void CRei42Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei42Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei42Doc コマンド
