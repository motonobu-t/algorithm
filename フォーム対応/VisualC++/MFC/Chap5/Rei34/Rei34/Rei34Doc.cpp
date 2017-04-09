// Rei34Doc.cpp : CRei34Doc クラスの実装
//

#include "stdafx.h"
#include "Rei34.h"

#include "Rei34Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei34Doc

IMPLEMENT_DYNCREATE(CRei34Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei34Doc, CDocument)
END_MESSAGE_MAP()


// CRei34Doc コンストラクション/デストラクション

CRei34Doc::CRei34Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei34Doc::~CRei34Doc()
{
}

BOOL CRei34Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei34Doc シリアル化

void CRei34Doc::Serialize(CArchive& ar)
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


// CRei34Doc 診断

#ifdef _DEBUG
void CRei34Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei34Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei34Doc コマンド
