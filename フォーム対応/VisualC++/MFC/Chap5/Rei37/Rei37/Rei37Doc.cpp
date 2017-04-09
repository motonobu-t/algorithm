// Rei37Doc.cpp : CRei37Doc クラスの実装
//

#include "stdafx.h"
#include "Rei37.h"

#include "Rei37Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei37Doc

IMPLEMENT_DYNCREATE(CRei37Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei37Doc, CDocument)
END_MESSAGE_MAP()


// CRei37Doc コンストラクション/デストラクション

CRei37Doc::CRei37Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei37Doc::~CRei37Doc()
{
}

BOOL CRei37Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei37Doc シリアル化

void CRei37Doc::Serialize(CArchive& ar)
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


// CRei37Doc 診断

#ifdef _DEBUG
void CRei37Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei37Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei37Doc コマンド
