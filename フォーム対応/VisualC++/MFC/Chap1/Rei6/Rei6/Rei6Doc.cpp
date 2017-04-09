// Rei6Doc.cpp : CRei6Doc クラスの実装
//

#include "stdafx.h"
#include "Rei6.h"

#include "Rei6Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei6Doc

IMPLEMENT_DYNCREATE(CRei6Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei6Doc, CDocument)
END_MESSAGE_MAP()


// CRei6Doc コンストラクション/デストラクション

CRei6Doc::CRei6Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei6Doc::~CRei6Doc()
{
}

BOOL CRei6Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei6Doc シリアル化

void CRei6Doc::Serialize(CArchive& ar)
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


// CRei6Doc 診断

#ifdef _DEBUG
void CRei6Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei6Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei6Doc コマンド
