// Rei15Doc.cpp : CRei15Doc クラスの実装
//

#include "stdafx.h"
#include "Rei15.h"

#include "Rei15Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei15Doc

IMPLEMENT_DYNCREATE(CRei15Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei15Doc, CDocument)
END_MESSAGE_MAP()


// CRei15Doc コンストラクション/デストラクション

CRei15Doc::CRei15Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei15Doc::~CRei15Doc()
{
}

BOOL CRei15Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei15Doc シリアル化

void CRei15Doc::Serialize(CArchive& ar)
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


// CRei15Doc 診断

#ifdef _DEBUG
void CRei15Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei15Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei15Doc コマンド
