// Rei12Doc.cpp : CRei12Doc クラスの実装
//

#include "stdafx.h"
#include "Rei12.h"

#include "Rei12Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei12Doc

IMPLEMENT_DYNCREATE(CRei12Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei12Doc, CDocument)
END_MESSAGE_MAP()


// CRei12Doc コンストラクション/デストラクション

CRei12Doc::CRei12Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei12Doc::~CRei12Doc()
{
}

BOOL CRei12Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei12Doc シリアル化

void CRei12Doc::Serialize(CArchive& ar)
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


// CRei12Doc 診断

#ifdef _DEBUG
void CRei12Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei12Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei12Doc コマンド
