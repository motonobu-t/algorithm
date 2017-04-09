// Rei5Doc.cpp : CRei5Doc クラスの実装
//

#include "stdafx.h"
#include "Rei5.h"

#include "Rei5Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei5Doc

IMPLEMENT_DYNCREATE(CRei5Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei5Doc, CDocument)
END_MESSAGE_MAP()


// CRei5Doc コンストラクション/デストラクション

CRei5Doc::CRei5Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei5Doc::~CRei5Doc()
{
}

BOOL CRei5Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei5Doc シリアル化

void CRei5Doc::Serialize(CArchive& ar)
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


// CRei5Doc 診断

#ifdef _DEBUG
void CRei5Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei5Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei5Doc コマンド
