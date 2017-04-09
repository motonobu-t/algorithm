// Rei30Doc.cpp : CRei30Doc クラスの実装
//

#include "stdafx.h"
#include "Rei30.h"

#include "Rei30Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei30Doc

IMPLEMENT_DYNCREATE(CRei30Doc, CDocument)

BEGIN_MESSAGE_MAP(CRei30Doc, CDocument)
END_MESSAGE_MAP()


// CRei30Doc コンストラクション/デストラクション

CRei30Doc::CRei30Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CRei30Doc::~CRei30Doc()
{
}

BOOL CRei30Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CRei30Doc シリアル化

void CRei30Doc::Serialize(CArchive& ar)
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


// CRei30Doc 診断

#ifdef _DEBUG
void CRei30Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRei30Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRei30Doc コマンド
