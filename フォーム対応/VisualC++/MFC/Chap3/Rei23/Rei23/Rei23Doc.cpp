// Rei23Doc.cpp : CRei23Doc クラスの実装
//

#include "stdafx.h"
#include "Rei23.h"

#include "Rei23Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei23Doc

IMPLEMENT_DYNCREATE(CRei23Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei23Doc, CDocument)
END_MESSAGE_MAP()


// CRei23Doc コンストラクション/デストラクション

CRei23Doc::CRei23Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei23Doc::~CRei23Doc()
{
}

BOOL CRei23Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei23Doc シリアル化

void CRei23Doc::Serialize(CArchive& ar)
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


// CRei23Doc 診断

#ifdef _DEBUG
void CRei23Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei23Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei23Doc コマンド
