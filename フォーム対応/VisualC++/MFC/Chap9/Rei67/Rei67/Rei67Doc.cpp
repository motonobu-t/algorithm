// Rei67Doc.cpp : CRei67Doc クラスの実装
//

#include "stdafx.h"
#include "Rei67.h"

#include "Rei67Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei67Doc

IMPLEMENT_DYNCREATE(CRei67Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei67Doc, CDocument)
END_MESSAGE_MAP()


// CRei67Doc コンストラクション/デストラクション

CRei67Doc::CRei67Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei67Doc::~CRei67Doc()
{
}

BOOL CRei67Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei67Doc シリアル化

void CRei67Doc::Serialize(CArchive& ar)
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


// CRei67Doc 診断

#ifdef _DEBUG
void CRei67Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei67Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei67Doc コマンド
