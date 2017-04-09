// Rei61View.cpp : CRei61View クラスの実装
//

#include "stdafx.h"
#include "Rei61.h"

#include "Rei61Doc.h"
#include "Rei61View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei61View

IMPLEMENT_DYNCREATE(CRei61View, CView)

BEGIN_MESSAGE_MAP(CRei61View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CRei61View コンストラクション/デストラクション

CRei61View::CRei61View()
{
	// TODO: 構築コードをここに追加します。

}

CRei61View::~CRei61View()
{
}

BOOL CRei61View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CRei61View 描画
/*
 * --------------------
 *     ３次元関数     *
 * --------------------
 */

#include "mfcglib.h"

void CRei61View::OnDraw(CDC* pDC)
{
	CRei61Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
    double x,y,z,px,py,ax,ay,rd=3.1415927/180;
    ax=30*rd;
    ay=-30*rd;

    ginit(); cls();
    window(-320,-200,320,200);

    for (z=200.0;z>=-200.0;z=z-10.0){
        for (x=-200.0;x<=200.0;x=x+5.0){
        y=30*(cos(sqrt(x*x+z*z)*rd)+cos(3*sqrt(x*x+z*z)*rd));
        px=x*cos(ay)+z*sin(ay);        /* 回転変換 */
        py=y*cos(ax)-(-x*sin(ay)+z*cos(ay))*sin(ax);
        if ((int)x==-200)
            setpoint(px,py);
        else
            moveto(px,py);
        }
    }
}


// CRei61View 印刷

BOOL CRei61View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CRei61View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CRei61View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CRei61View 診断

#ifdef _DEBUG
void CRei61View::AssertValid() const
{
	CView::AssertValid();
}

void CRei61View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRei61Doc* CRei61View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei61Doc)));
	return (CRei61Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei61View メッセージ ハンドラ
