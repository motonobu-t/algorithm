// Rei63Doc.cpp : CRei63Doc クラスの実装
//

#include "stdafx.h"
#include "Rei63.h"

#include "Rei63Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei63Doc

IMPLEMENT_DYNCREATE(CRei63Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei63Doc, CDocument)
END_MESSAGE_MAP()


// CRei63Doc コンストラクション/デストラクション

CRei63Doc::CRei63Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei63Doc::~CRei63Doc()
{
}

BOOL CRei63Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei63Doc シリアル化

void CRei63Doc::Serialize(CArchive& ar)
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


// CRei63Doc 診断

#ifdef _DEBUG
void CRei63Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei63Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei63Doc コマンド
