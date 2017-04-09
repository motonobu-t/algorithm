// Dr60Doc.cpp : CDr60Doc クラスの実装
//

#include "stdafx.h"
#include "Dr60.h"

#include "Dr60Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr60Doc

IMPLEMENT_DYNCREATE(CDr60Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr60Doc, CDocument)
END_MESSAGE_MAP()


// CDr60Doc コンストラクション/デストラクション

CDr60Doc::CDr60Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr60Doc::~CDr60Doc()
{
}

BOOL CDr60Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr60Doc シリアル化

void CDr60Doc::Serialize(CArchive& ar)
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


// CDr60Doc 診断

#ifdef _DEBUG
void CDr60Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr60Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr60Doc コマンド
