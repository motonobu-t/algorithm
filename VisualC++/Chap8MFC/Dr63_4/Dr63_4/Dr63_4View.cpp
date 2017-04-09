// Dr63_4View.cpp : CDr63_4View クラスの実装
//

#include "stdafx.h"
#include "Dr63_4.h"

#include "Dr63_4Doc.h"
#include "Dr63_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr63_4View

IMPLEMENT_DYNCREATE(CDr63_4View, CView)

BEGIN_MESSAGE_MAP(CDr63_4View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr63_4View コンストラクション/デストラクション

CDr63_4View::CDr63_4View()
{
	// TODO: 構築コードをここに追加します。

}

CDr63_4View::~CDr63_4View()
{
}

BOOL CDr63_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CDr63_4View 描画
/*
 * -------------------------
 *      ヒルベルト曲線     *
 * -------------------------
 */

#include "mfcglib.h"

void hilbert(int n,double l,double angle)
{
    if (n==0)
        return;
    turn(angle);hilbert(n-1,l,-angle);move(l);
    turn(-angle);hilbert(n-1,l,angle);move(l);
    hilbert(n-1,l,angle);turn(-angle);move(l);
    hilbert(n-1,l,-angle);turn(angle);
}

void CDr63_4View::OnDraw(CDC* pDC)
{
	CDr63_4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
    int n=4;         /* 次数 */

    ginit(); cls();

    setpoint(200,100);
    hilbert(n,10,90);
}


// CDr63_4View 印刷

BOOL CDr63_4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CDr63_4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CDr63_4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CDr63_4View 診断

#ifdef _DEBUG
void CDr63_4View::AssertValid() const
{
	CView::AssertValid();
}

void CDr63_4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr63_4Doc* CDr63_4View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr63_4Doc)));
	return (CDr63_4Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr63_4View メッセージ ハンドラ
