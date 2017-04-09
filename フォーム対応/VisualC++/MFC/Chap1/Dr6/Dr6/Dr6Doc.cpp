// Dr6Doc.cpp : CDr6Doc クラスの実装
//

#include "stdafx.h"
#include "Dr6.h"

#include "Dr6Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr6Doc

IMPLEMENT_DYNCREATE(CDr6Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr6Doc, CDocument)
END_MESSAGE_MAP()


// CDr6Doc コンストラクション/デストラクション

CDr6Doc::CDr6Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr6Doc::~CDr6Doc()
{
}

BOOL CDr6Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr6Doc シリアル化

void CDr6Doc::Serialize(CArchive& ar)
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


// CDr6Doc 診断

#ifdef _DEBUG
void CDr6Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr6Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr6Doc コマンド
