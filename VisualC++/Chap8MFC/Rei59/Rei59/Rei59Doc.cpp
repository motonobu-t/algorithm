// Rei59Doc.cpp : CRei59Doc クラスの実装
//

#include "stdafx.h"
#include "Rei59.h"

#include "Rei59Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei59Doc

IMPLEMENT_DYNCREATE(CRei59Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei59Doc, CDocument)
END_MESSAGE_MAP()


// CRei59Doc コンストラクション/デストラクション

CRei59Doc::CRei59Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei59Doc::~CRei59Doc()
{
}

BOOL CRei59Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei59Doc シリアル化

void CRei59Doc::Serialize(CArchive& ar)
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


// CRei59Doc 診断

#ifdef _DEBUG
void CRei59Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei59Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei59Doc コマンド
