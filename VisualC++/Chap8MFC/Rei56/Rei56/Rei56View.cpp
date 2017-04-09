// Rei56View.cpp : CRei56View クラスの実装
//

#include "stdafx.h"
#include "Rei56.h"

#include "Rei56Doc.h"
#include "Rei56View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei56View

IMPLEMENT_DYNCREATE(CRei56View, CView)

BEGIN_MESSAGE_MAP(CRei56View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CRei56View コンストラクション/デストラクション

CRei56View::CRei56View()
{
	// TODO: 構築コードをここに追加します。

}

CRei56View::~CRei56View()
{
}

BOOL CRei56View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CRei56View 描画

/*
 * -------------------------------
 *      正Ｎ角形（ポリゴン）     *
 * -------------------------------
 */

#include "mfcglib.h"

void CRei56View::OnDraw(CDC* pDC)
{
	CRei56Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
    int j,n;

    ginit();cls();

    for (n=3;n<=9;n++){
        setpoint(200,50);
        setangle(0);
        for (j=0;j<n;j++){
            move(80);
            turn(360/n);
        }
    }
}


// CRei56View 印刷

BOOL CRei56View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CRei56View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CRei56View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CRei56View 診断

#ifdef _DEBUG
void CRei56View::AssertValid() const
{
	CView::AssertValid();
}

void CRei56View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRei56Doc* CRei56View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei56Doc)));
	return (CRei56Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei56View メッセージ ハンドラ
