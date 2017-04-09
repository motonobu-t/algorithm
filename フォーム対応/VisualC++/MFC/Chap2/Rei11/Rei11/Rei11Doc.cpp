// Rei11Doc.cpp : CRei11Doc クラスの実装
//

#include "stdafx.h"
#include "Rei11.h"

#include "Rei11Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei11Doc

IMPLEMENT_DYNCREATE(CRei11Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei11Doc, CDocument)
END_MESSAGE_MAP()


// CRei11Doc コンストラクション/デストラクション

CRei11Doc::CRei11Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei11Doc::~CRei11Doc()
{
}

BOOL CRei11Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei11Doc シリアル化

void CRei11Doc::Serialize(CArchive& ar)
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


// CRei11Doc 診断

#ifdef _DEBUG
void CRei11Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei11Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei11Doc コマンド
