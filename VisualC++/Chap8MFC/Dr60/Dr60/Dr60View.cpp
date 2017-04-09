// Dr60View.cpp : CDr60View クラスの実装
//

#include "stdafx.h"
#include "Dr60.h"

#include "Dr60Doc.h"
#include "Dr60View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr60View

IMPLEMENT_DYNCREATE(CDr60View, CView)

BEGIN_MESSAGE_MAP(CDr60View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr60View コンストラクション/デストラクション

CDr60View::CDr60View()
{
	// TODO: 構築コードをここに追加します。

}

CDr60View::~CDr60View()
{
}

BOOL CDr60View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CDr60View 描画
/*
 * --------------------
 *      柱体モデル    *
 * --------------------
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

void CDr60View::OnDraw(CDC* pDC)
{
	CDr60Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
    int k,n;
    double ax,ay,az,rd=3.14159/180;
    double x[]={ 0,20,  0, 60,100,60, 0,-999},   /* ｘ座標 */
           z[]={40,60,100,120, 60,20,40,-999},   /* ｚ座標 */
           h=100.0,                              /* 高さ */
           btx[30],bty[30],                      /* 底面 */
           tpx[30],tpy[30];                      /* 上面 */
    ax=35*rd;                       /* ｘ軸回りの回転角 */
    ay=-60*rd;                      /* ｙ軸回りの回転角 */
    az=0;

    ginit(); cls();
    window(-320,-200,320,200);

    for (k=0;(int)x[k]!=-999;k++){      /* 底面 */
        rotate(ax,ay,az,x[k],0.0,z[k],&btx[k],&bty[k]);
        if (k==0)
            setpoint(btx[k],bty[k]);
        else
            moveto(btx[k],bty[k]);
    }
    n=k;
    for (k=0;k<n;k++){                  /* 上面 */
        rotate(ax,ay,az,x[k],h,z[k],&tpx[k],&tpy[k]);
        if (k==0)
            setpoint(tpx[k],tpy[k]);
        else
            moveto(tpx[k],tpy[k]);
    }
    for (k=0;k<n;k++)       /* 底面と上面の各点を結ぶ */
        line(tpx[k],tpy[k],btx[k],bty[k]);
}


// CDr60View 印刷

BOOL CDr60View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CDr60View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CDr60View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CDr60View 診断

#ifdef _DEBUG
void CDr60View::AssertValid() const
{
	CView::AssertValid();
}

void CDr60View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr60Doc* CDr60View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr60Doc)));
	return (CDr60Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr60View メッセージ ハンドラ
