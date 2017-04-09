// Rei14Doc.cpp : CRei14Doc クラスの実装
//

#include "stdafx.h"
#include "Rei14.h"

#include "Rei14Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei14Doc

IMPLEMENT_DYNCREATE(CRei14Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei14Doc, CDocument)
END_MESSAGE_MAP()


// CRei14Doc コンストラクション/デストラクション

CRei14Doc::CRei14Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei14Doc::~CRei14Doc()
{
}

BOOL CRei14Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei14Doc シリアル化

void CRei14Doc::Serialize(CArchive& ar)
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


// CRei14Doc 診断

#ifdef _DEBUG
void CRei14Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei14Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei14Doc コマンド
