// Rei28Doc.cpp : CRei28Doc クラスの実装
//

#include "stdafx.h"
#include "Rei28.h"

#include "Rei28Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei28Doc

IMPLEMENT_DYNCREATE(CRei28Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei28Doc, CDocument)
END_MESSAGE_MAP()


// CRei28Doc コンストラクション/デストラクション

CRei28Doc::CRei28Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei28Doc::~CRei28Doc()
{
}

BOOL CRei28Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei28Doc シリアル化

void CRei28Doc::Serialize(CArchive& ar)
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


// CRei28Doc 診断

#ifdef _DEBUG
void CRei28Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei28Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei28Doc コマンド
