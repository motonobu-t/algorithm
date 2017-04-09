// Dr62_2View.cpp : CDr62_2View クラスの実装
//

#include "stdafx.h"
#include "Dr62_2.h"

#include "Dr62_2Doc.h"
#include "Dr62_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr62_2View

IMPLEMENT_DYNCREATE(CDr62_2View, CView)

BEGIN_MESSAGE_MAP(CDr62_2View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr62_2View コンストラクション/デストラクション

CDr62_2View::CDr62_2View()
{
	// TODO: 構築コードをここに追加します。

}

CDr62_2View::~CDr62_2View()
{
}

BOOL CDr62_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CDr62_2View 描画
/*
 * ------------------------------
 *       クロス・ステッチ       *
 * ------------------------------
 */

#include "mfcglib.h"

void stech(int n,double leng)       /* ステッチの再帰手続き */
{
    if (n==0)
        move(leng);
    else {
        stech(n-1,leng); turn(-90);
        stech(n-1,leng); turn(90);
        stech(n-1,leng); turn(90);
        stech(n-1,leng); turn(-90);
        stech(n-1,leng);
    }
}

void CDr62_2View::OnDraw(CDC* pDC)
{
	CDr62_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
    int    k,
           n=4;         /* ステッチの次数 */
    double leng=2.0;    /* ０次の長さ */

    ginit(); cls();
    setpoint(200,150); setangle(0);
    for (k=1;k<=4;k++){
        stech(n,leng);
        turn(90);
    }
}


// CDr62_2View 印刷

BOOL CDr62_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CDr62_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CDr62_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CDr62_2View 診断

#ifdef _DEBUG
void CDr62_2View::AssertValid() const
{
	CView::AssertValid();
}

void CDr62_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr62_2Doc* CDr62_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr62_2Doc)));
	return (CDr62_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr62_2View メッセージ ハンドラ
