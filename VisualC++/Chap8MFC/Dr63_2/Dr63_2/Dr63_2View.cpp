// Dr63_2View.cpp : CDr63_2View クラスの実装
//

#include "stdafx.h"
#include "Dr63_2.h"

#include "Dr63_2Doc.h"
#include "Dr63_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr63_2View

IMPLEMENT_DYNCREATE(CDr63_2View, CView)

BEGIN_MESSAGE_MAP(CDr63_2View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr63_2View コンストラクション/デストラクション

CDr63_2View::CDr63_2View()
{
	// TODO: 構築コードをここに追加します。

}

CDr63_2View::~CDr63_2View()
{
}

BOOL CDr63_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CDr63_2View 描画
/*
 * -----------------
 *      Ｃ曲線     *
 * -----------------
 */

#include "mfcglib.h"

void ccurve(int n)
{
    if (n==0){
        move(5);
    }
    else {
        ccurve(n-1);
        turn(90);
        ccurve(n-1);
        turn(-90);
    }
}

void CDr63_2View::OnDraw(CDC* pDC)
{
	CDr63_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
    int n=10;       /* 次数 */

    ginit(); cls();

    setpoint(200,100);
    ccurve(n);
}


// CDr63_2View 印刷

BOOL CDr63_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CDr63_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CDr63_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CDr63_2View 診断

#ifdef _DEBUG
void CDr63_2View::AssertValid() const
{
	CView::AssertValid();
}

void CDr63_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr63_2Doc* CDr63_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr63_2Doc)));
	return (CDr63_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr63_2View メッセージ ハンドラ
