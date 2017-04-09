// Dr12Doc.cpp : CDr12Doc クラスの実装
//

#include "stdafx.h"
#include "Dr12.h"

#include "Dr12Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr12Doc

IMPLEMENT_DYNCREATE(CDr12Doc, CDocument)

BEGIN_MESSAGE_MAP(CDr12Doc, CDocument)
END_MESSAGE_MAP()


// CDr12Doc コンストラクション/デストラクション

CDr12Doc::CDr12Doc()
{
	// TODO: この位置に 1 度だけ呼ばれる構築用のコードを追加してください。

}

CDr12Doc::~CDr12Doc()
{
}

BOOL CDr12Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: この位置に再初期化処理を追加してください。
	// (SDI ドキュメントはこのドキュメントを再利用します。)

	return TRUE;
}




// CDr12Doc シリアル化

void CDr12Doc::Serialize(CArchive& ar)
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


// CDr12Doc 診断

#ifdef _DEBUG
void CDr12Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDr12Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDr12Doc コマンド
