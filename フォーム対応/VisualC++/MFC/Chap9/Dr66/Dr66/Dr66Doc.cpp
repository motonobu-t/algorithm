// Dr66Doc.cpp : CDr66Doc クラスの実装
//

#include "stdafx.h"
#include "Dr66.h"

#include "Dr66Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr66Doc

IMPLEMENT_DYNCREATE(CDr66Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr66Doc, CDocument)
END_MESSAGE_MAP()


// CDr66Doc コンストラクション/デストラクション

CDr66Doc::CDr66Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr66Doc::~CDr66Doc()
{
}

BOOL CDr66Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr66Doc シリアル化

void CDr66Doc::Serialize(CArchive& ar)
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


// CDr66Doc 診断

#ifdef _DEBUG
void CDr66Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr66Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr66Doc コマンド
