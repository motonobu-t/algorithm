// Rei8Doc.cpp : CRei8Doc クラスの実装
//

#include "stdafx.h"
#include "Rei8.h"

#include "Rei8Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei8Doc

IMPLEMENT_DYNCREATE(CRei8Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei8Doc, CDocument)
END_MESSAGE_MAP()


// CRei8Doc コンストラクション/デストラクション

CRei8Doc::CRei8Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei8Doc::~CRei8Doc()
{
}

BOOL CRei8Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei8Doc シリアル化

void CRei8Doc::Serialize(CArchive& ar)
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


// CRei8Doc 診断

#ifdef _DEBUG
void CRei8Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei8Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei8Doc コマンド
