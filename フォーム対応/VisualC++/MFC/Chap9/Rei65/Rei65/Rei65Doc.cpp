// Rei65Doc.cpp : CRei65Doc クラスの実装
//

#include "stdafx.h"
#include "Rei65.h"

#include "Rei65Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei65Doc

IMPLEMENT_DYNCREATE(CRei65Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei65Doc, CDocument)
END_MESSAGE_MAP()


// CRei65Doc コンストラクション/デストラクション

CRei65Doc::CRei65Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei65Doc::~CRei65Doc()
{
}

BOOL CRei65Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei65Doc シリアル化

void CRei65Doc::Serialize(CArchive& ar)
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


// CRei65Doc 診断

#ifdef _DEBUG
void CRei65Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei65Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei65Doc コマンド
