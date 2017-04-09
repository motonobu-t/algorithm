// Rei9Doc.cpp : CRei9Doc クラスの実装
//

#include "stdafx.h"
#include "Rei9.h"

#include "Rei9Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei9Doc

IMPLEMENT_DYNCREATE(CRei9Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei9Doc, CDocument)
END_MESSAGE_MAP()


// CRei9Doc コンストラクション/デストラクション

CRei9Doc::CRei9Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei9Doc::~CRei9Doc()
{
}

BOOL CRei9Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei9Doc シリアル化

void CRei9Doc::Serialize(CArchive& ar)
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


// CRei9Doc 診断

#ifdef _DEBUG
void CRei9Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei9Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei9Doc コマンド
