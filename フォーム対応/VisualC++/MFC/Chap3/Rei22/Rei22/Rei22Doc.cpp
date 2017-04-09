// Rei22Doc.cpp : CRei22Doc クラスの実装
//

#include "stdafx.h"
#include "Rei22.h"

#include "Rei22Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei22Doc

IMPLEMENT_DYNCREATE(CRei22Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei22Doc, CDocument)
END_MESSAGE_MAP()


// CRei22Doc コンストラクション/デストラクション

CRei22Doc::CRei22Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei22Doc::~CRei22Doc()
{
}

BOOL CRei22Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei22Doc シリアル化

void CRei22Doc::Serialize(CArchive& ar)
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


// CRei22Doc 診断

#ifdef _DEBUG
void CRei22Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei22Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei22Doc コマンド
