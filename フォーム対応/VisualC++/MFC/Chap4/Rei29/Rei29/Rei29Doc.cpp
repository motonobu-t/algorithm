// Rei29Doc.cpp : CRei29Doc クラスの実装
//

#include "stdafx.h"
#include "Rei29.h"

#include "Rei29Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei29Doc

IMPLEMENT_DYNCREATE(CRei29Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei29Doc, CDocument)
END_MESSAGE_MAP()


// CRei29Doc コンストラクション/デストラクション

CRei29Doc::CRei29Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei29Doc::~CRei29Doc()
{
}

BOOL CRei29Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei29Doc シリアル化

void CRei29Doc::Serialize(CArchive& ar)
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


// CRei29Doc 診断

#ifdef _DEBUG
void CRei29Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei29Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei29Doc コマンド
