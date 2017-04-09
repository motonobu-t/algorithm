// Dr56View.cpp : CDr56View クラスの実装
//

#include "stdafx.h"
#include "Dr56.h"

#include "Dr56Doc.h"
#include "Dr56View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr56View

IMPLEMENT_DYNCREATE(CDr56View, CView)

BEGIN_MESSAGE_MAP(CDr56View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr56View コンストラクション/デストラクション

CDr56View::CDr56View()
{
	// TODO: 構築コードをここに追加します。

}

CDr56View::~CDr56View()
{
}

BOOL CDr56View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CDr56View 描画

/*
 * ----------------------
 *      渦巻き模様      *
 * ----------------------
 */

#include "mfcglib.h"

void CDr56View::OnDraw(CDC* pDC)
{
	CDr56Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
    double leng=200.0,    /* 辺の初期値 */
           angle=89.0,    /* 回転角 */
           step=1.0;      /* 辺の減少値 */

    ginit(); cls();

    setpoint(220,100);
    setangle(0);
    while (leng>10.0){
        move(leng);
        turn(angle);
        leng=leng-step;
    }
}


// CDr56View 印刷

BOOL CDr56View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CDr56View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CDr56View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CDr56View 診断

#ifdef _DEBUG
void CDr56View::AssertValid() const
{
	CView::AssertValid();
}

void CDr56View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr56Doc* CDr56View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr56Doc)));
	return (CDr56Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr56View メッセージ ハンドラ
