// Rei51Doc.cpp : CRei51Doc クラスの実装
//

#include "stdafx.h"
#include "Rei51.h"

#include "Rei51Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei51Doc

IMPLEMENT_DYNCREATE(CRei51Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei51Doc, CDocument)
END_MESSAGE_MAP()


// CRei51Doc コンストラクション/デストラクション

CRei51Doc::CRei51Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei51Doc::~CRei51Doc()
{
}

BOOL CRei51Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei51Doc シリアル化

void CRei51Doc::Serialize(CArchive& ar)
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


// CRei51Doc 診断

#ifdef _DEBUG
void CRei51Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei51Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei51Doc コマンド
