// Rei58View.cpp : CRei58View クラスの実装
//

#include "stdafx.h"
#include "Rei58.h"

#include "Rei58Doc.h"
#include "Rei58View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei58View

IMPLEMENT_DYNCREATE(CRei58View, CView)

BEGIN_MESSAGE_MAP(CRei58View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CRei58View コンストラクション/デストラクション

CRei58View::CRei58View()
{
	// TODO: 構築コードをここに追加します。

}

CRei58View::~CRei58View()
{
}

BOOL CRei58View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CRei58View 描画
/*
 * --------------------
 *       対称模様     *
 * --------------------
 */

#include "mfcglib.h"

#define N 9     /* データ数 */

void CRei58View::OnDraw(CDC* pDC)
{
	CRei58Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
    double x[]={ 35, 19,10, 3,0,-3,-10,-19,-35},
           y[]={-20,-20,-5,-5,0,-5, -5,-20,-20};
    int a,b,j,k;
    double rd=3.14159/180,
           m,h,vy,vx,px,py;

    ginit(); cls();
    m=70.0; h=m*sqrt(3.0)/2;      /* 正３角形の辺の長さ、高さ */
    window(-m/2,-h/3,m/2,h*2/3);
    b=1;
    for (vy=0.0;vy<=310.0;vy=vy+h){
        a=1;
        for (vx=50.0;vx<=500.0;vx=vx+m/2){
            view(vx,vy,vx+m,vy+h);        /* ビューポートの設定 */
            for (j=0;j<3;j++){
                for (k=0;k<N;k++){
                    px=x[k]*cos(120*j*rd)-y[k]*sin(120*j*rd);
                    py=x[k]*sin(120*j*rd)+y[k]*cos(120*j*rd);
                    if (a*b==-1)
                        py=-py+h/3;        /* 逆像補正 */
                    if (k==0)
                        setpoint(px,py);
                    else
                        moveto(px,py);
                }
            }
            a=-a;
        }
        b=-b;
    }
}


// CRei58View 印刷

BOOL CRei58View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CRei58View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CRei58View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CRei58View 診断

#ifdef _DEBUG
void CRei58View::AssertValid() const
{
	CView::AssertValid();
}

void CRei58View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRei58Doc* CRei58View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei58Doc)));
	return (CRei58Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei58View メッセージ ハンドラ
