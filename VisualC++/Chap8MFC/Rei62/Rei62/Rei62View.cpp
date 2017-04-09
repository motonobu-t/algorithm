// Rei62View.cpp : CRei62View クラスの実装
//

#include "stdafx.h"
#include "Rei62.h"

#include "Rei62Doc.h"
#include "Rei62View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei62View

IMPLEMENT_DYNCREATE(CRei62View, CView)

BEGIN_MESSAGE_MAP(CRei62View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CRei62View コンストラクション/デストラクション

CRei62View::CRei62View()
{
	// TODO: 構築コードをここに追加します。

}

CRei62View::~CRei62View()
{
}

BOOL CRei62View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CRei62View 描画
/*
 * -----------------------
 *       コッホ曲線      *
 * -----------------------
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

void CRei62View::OnDraw(CDC* pDC)
{
	CRei62Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
    int    n=4;         /* コッホ次数 */
    double leng=4.0;    /* ０次の長さ */

    ginit(); cls();
    setpoint(100,200);
    setangle(0);

    koch(n,leng);

}


// CRei62View 印刷

BOOL CRei62View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CRei62View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CRei62View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CRei62View 診断

#ifdef _DEBUG
void CRei62View::AssertValid() const
{
	CView::AssertValid();
}

void CRei62View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRei62Doc* CRei62View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei62Doc)));
	return (CRei62Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei62View メッセージ ハンドラ
