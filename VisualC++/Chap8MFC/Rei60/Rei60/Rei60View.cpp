// Rei60View.cpp : CRei60View クラスの実装
//

#include "stdafx.h"
#include "Rei60.h"

#include "Rei60Doc.h"
#include "Rei60View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei60View

IMPLEMENT_DYNCREATE(CRei60View, CView)

BEGIN_MESSAGE_MAP(CRei60View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CRei60View コンストラクション/デストラクション

CRei60View::CRei60View()
{
	// TODO: 構築コードをここに追加します。

}

CRei60View::~CRei60View()
{
}

BOOL CRei60View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CRei60View 描画
/*
 * -------------------------------------
 *      回転体モデル（ワイングラス）   *
 * -------------------------------------
 */

#include "mfcglib.h"

void rotate(double ax,double ay,double az,double x,double y,double z,
            double *px,double *py)   /* ３次元回転変換 */
{
    double x1,y1,z1,x2,y2;
    x1=x*cos(ay)+z*sin(ay);          /* ｙ軸回り */
    y1=y;
    z1=-x*sin(ay)+z*cos(ay);
    x2=x1;                           /* ｘ軸回り */
    y2=y1*cos(ax)-z1*sin(ax);
    *px=x2*cos(az)-y2*sin(az);       /* ｚ軸回り */
    *py=x2*sin(az)+y2*cos(az);
}

void CRei60View::OnDraw(CDC* pDC)
{
	CRei60Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
    int n,k;
    double x,z,px,py,ax,ay,az,rd=3.14159/180;
    double y[]={180,140,100,60,20,10,4,0,-999},   /* 高さ */
           r[]={100,55,10,10,10,50,80,80,-999};   /* 半径 */
    ax=35*rd;   /* ｘ軸回りの回転角 */
    ay=0;       /* ｙ軸回りの回転角 */
    az=20*rd;   /* ｚ軸回りの回転角 */

    ginit(); cls();
    window(-320,-100,320,300);

    for (k=0;(int)y[k]!=-999;k++){    /* ｙ軸回りの回転軌跡 */
        for (n=0;n<=360;n=n+10){
            x=r[k]*cos(n*rd);
            z=r[k]*sin(n*rd);
            rotate(ax,ay,az,x,y[k],z,&px,&py);
            if (n==0)
                setpoint(px,py);
            else
                moveto(px,py);
        }
    }
    for (n=0;n<=360;n=n+60){        /* 稜線 */
        for (k=0;(int)y[k]!=-999;k++){
            x=r[k]*cos(n*rd);
            z=r[k]*sin(n*rd);
            rotate(ax,ay,az,x,y[k],z,&px,&py);
            if (k==0)
                setpoint(px,py);
            else
                moveto(px,py);
        }
    }

}


// CRei60View 印刷

BOOL CRei60View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CRei60View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CRei60View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CRei60View 診断

#ifdef _DEBUG
void CRei60View::AssertValid() const
{
	CView::AssertValid();
}

void CRei60View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRei60Doc* CRei60View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei60Doc)));
	return (CRei60Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei60View メッセージ ハンドラ
