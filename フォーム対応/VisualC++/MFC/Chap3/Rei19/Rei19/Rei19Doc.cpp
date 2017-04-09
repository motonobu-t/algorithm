// Rei19Doc.cpp : CRei19Doc クラスの実装
//

#include "stdafx.h"
#include "Rei19.h"

#include "Rei19Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei19Doc

IMPLEMENT_DYNCREATE(CRei19Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei19Doc, CDocument)
END_MESSAGE_MAP()


// CRei19Doc コンストラクション/デストラクション

CRei19Doc::CRei19Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei19Doc::~CRei19Doc()
{
}

BOOL CRei19Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei19Doc シリアル化

void CRei19Doc::Serialize(CArchive& ar)
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


// CRei19Doc 診断

#ifdef _DEBUG
void CRei19Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei19Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei19Doc コマンド
