// Dr62_1View.cpp : CDr62_1View クラスの実装
//

#include "stdafx.h"
#include "Dr62_1.h"

#include "Dr62_1Doc.h"
#include "Dr62_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr62_1View

IMPLEMENT_DYNCREATE(CDr62_1View, CView)

BEGIN_MESSAGE_MAP(CDr62_1View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr62_1View コンストラクション/デストラクション

CDr62_1View::CDr62_1View()
{
	// TODO: 構築コードをここに追加します。

}

CDr62_1View::~CDr62_1View()
{
}

BOOL CDr62_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CDr62_1View 描画
/*
 * ---------------------
 *       コッホ島      *
 * ---------------------
 */

#include "mfcglib.h"

void koch(int n,double leng)        /* コッホ曲線の再帰手続き */
{
    if (n==0){
        move(leng);
    }
    else {
        koch(n-1,leng);
        turn(60);
        koch(n-1,leng);
        turn(-120);
        koch(n-1,leng);
        turn(60);
        koch(n-1,leng);
    }
}

void CDr62_1View::OnDraw(CDC* pDC)
{
	CDr62_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
    int    i,
           n=4;         /* コッホ次数 */
    double leng=4.0;    /* ０次の長さ */

    ginit(); cls();
    setpoint(150,300);
    setangle(0);
    for (i=0;i<3;i++){
          koch(n,leng);
        turn(-120);
    }

}


// CDr62_1View 印刷

BOOL CDr62_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CDr62_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CDr62_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CDr62_1View 診断

#ifdef _DEBUG
void CDr62_1View::AssertValid() const
{
	CView::AssertValid();
}

void CDr62_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr62_1Doc* CDr62_1View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr62_1Doc)));
	return (CDr62_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr62_1View メッセージ ハンドラ
