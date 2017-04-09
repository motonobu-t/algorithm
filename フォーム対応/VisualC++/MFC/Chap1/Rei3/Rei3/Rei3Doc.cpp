// Rei3Doc.cpp : CRei3Doc クラスの実装
//

#include "stdafx.h"
#include "Rei3.h"

#include "Rei3Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei3Doc

IMPLEMENT_DYNCREATE(CRei3Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei3Doc, CDocument)
END_MESSAGE_MAP()


// CRei3Doc コンストラクション/デストラクション

CRei3Doc::CRei3Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei3Doc::~CRei3Doc()
{
}

BOOL CRei3Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei3Doc シリアル化

void CRei3Doc::Serialize(CArchive& ar)
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


// CRei3Doc 診断

#ifdef _DEBUG
void CRei3Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei3Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei3Doc コマンド
