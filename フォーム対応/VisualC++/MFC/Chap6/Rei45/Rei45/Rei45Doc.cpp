// Rei45Doc.cpp : CRei45Doc クラスの実装
//

#include "stdafx.h"
#include "Rei45.h"

#include "Rei45Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei45Doc

IMPLEMENT_DYNCREATE(CRei45Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei45Doc, CDocument)
END_MESSAGE_MAP()


// CRei45Doc コンストラクション/デストラクション

CRei45Doc::CRei45Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei45Doc::~CRei45Doc()
{
}

BOOL CRei45Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei45Doc シリアル化

void CRei45Doc::Serialize(CArchive& ar)
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


// CRei45Doc 診断

#ifdef _DEBUG
void CRei45Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei45Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei45Doc コマンド
