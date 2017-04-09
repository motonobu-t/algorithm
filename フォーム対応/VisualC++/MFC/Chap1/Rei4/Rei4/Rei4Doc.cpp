// Rei4Doc.cpp : CRei4Doc クラスの実装
//

#include "stdafx.h"
#include "Rei4.h"

#include "Rei4Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei4Doc

IMPLEMENT_DYNCREATE(CRei4Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei4Doc, CDocument)
END_MESSAGE_MAP()


// CRei4Doc コンストラクション/デストラクション

CRei4Doc::CRei4Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei4Doc::~CRei4Doc()
{
}

BOOL CRei4Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei4Doc シリアル化

void CRei4Doc::Serialize(CArchive& ar)
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


// CRei4Doc 診断

#ifdef _DEBUG
void CRei4Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei4Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei4Doc コマンド
