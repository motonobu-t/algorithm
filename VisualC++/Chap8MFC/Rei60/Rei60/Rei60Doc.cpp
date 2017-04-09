// Rei60Doc.cpp : CRei60Doc クラスの実装
//

#include "stdafx.h"
#include "Rei60.h"

#include "Rei60Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei60Doc

IMPLEMENT_DYNCREATE(CRei60Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei60Doc, CDocument)
END_MESSAGE_MAP()


// CRei60Doc コンストラクション/デストラクション

CRei60Doc::CRei60Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei60Doc::~CRei60Doc()
{
}

BOOL CRei60Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei60Doc シリアル化

void CRei60Doc::Serialize(CArchive& ar)
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


// CRei60Doc 診断

#ifdef _DEBUG
void CRei60Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei60Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei60Doc コマンド
