// Rei20Doc.cpp : CRei20Doc クラスの実装
//

#include "stdafx.h"
#include "Rei20.h"

#include "Rei20Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei20Doc

IMPLEMENT_DYNCREATE(CRei20Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei20Doc, CDocument)
END_MESSAGE_MAP()


// CRei20Doc コンストラクション/デストラクション

CRei20Doc::CRei20Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei20Doc::~CRei20Doc()
{
}

BOOL CRei20Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei20Doc シリアル化

void CRei20Doc::Serialize(CArchive& ar)
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


// CRei20Doc 診断

#ifdef _DEBUG
void CRei20Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei20Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei20Doc コマンド
