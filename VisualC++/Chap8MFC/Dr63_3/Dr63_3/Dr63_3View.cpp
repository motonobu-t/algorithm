// Dr63_3View.cpp : CDr63_3View クラスの実装
//

#include "stdafx.h"
#include "Dr63_3.h"

#include "Dr63_3Doc.h"
#include "Dr63_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr63_3View

IMPLEMENT_DYNCREATE(CDr63_3View, CView)

BEGIN_MESSAGE_MAP(CDr63_3View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr63_3View コンストラクション/デストラクション

CDr63_3View::CDr63_3View()
{
	// TODO: 構築コードをここに追加します。

}

CDr63_3View::~CDr63_3View()
{
}

BOOL CDr63_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CDr63_3View 描画
/*
 * ---------------------------
 *      ドラゴン・カーブ     *
 * ---------------------------
 */

#include "mfcglib.h"

void dragon(int n,double a)
{
    if (n==0){
        move(5);
    }
    else {
        dragon(n-1,90);
        turn(a);
        dragon(n-1,-90);
    }
}

void CDr63_3View::OnDraw(CDC* pDC)
{
	CDr63_3Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
    int n=10;       /* 次数 */

    ginit(); cls();

    setpoint(200,100);
    dragon(n,90);
}


// CDr63_3View 印刷

BOOL CDr63_3View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CDr63_3View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CDr63_3View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CDr63_3View 診断

#ifdef _DEBUG
void CDr63_3View::AssertValid() const
{
	CView::AssertValid();
}

void CDr63_3View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr63_3Doc* CDr63_3View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr63_3Doc)));
	return (CDr63_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr63_3View メッセージ ハンドラ
