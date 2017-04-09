// Rei38Doc.cpp : CRei38Doc クラスの実装
//

#include "stdafx.h"
#include "Rei38.h"

#include "Rei38Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei38Doc

IMPLEMENT_DYNCREATE(CRei38Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei38Doc, CDocument)
END_MESSAGE_MAP()


// CRei38Doc コンストラクション/デストラクション

CRei38Doc::CRei38Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei38Doc::~CRei38Doc()
{
}

BOOL CRei38Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei38Doc シリアル化

void CRei38Doc::Serialize(CArchive& ar)
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


// CRei38Doc 診断

#ifdef _DEBUG
void CRei38Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei38Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei38Doc コマンド
