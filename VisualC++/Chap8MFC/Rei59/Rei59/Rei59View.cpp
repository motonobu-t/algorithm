// Rei59View.cpp : CRei59View クラスの実装
//

#include "stdafx.h"
#include "Rei59.h"

#include "Rei59Doc.h"
#include "Rei59View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei59View

IMPLEMENT_DYNCREATE(CRei59View, CView)

BEGIN_MESSAGE_MAP(CRei59View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CRei59View コンストラクション/デストラクション

CRei59View::CRei59View()
{
	// TODO: 構築コードをここに追加します。

}

CRei59View::~CRei59View()
{
}

BOOL CRei59View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CRei59View 描画
/*
 * ----------------------
 *       軸測投影       *
 * ----------------------
 */

#include "mfcglib.h"

void rotate(double ax,double ay,double az,double x,double y,double z,
       double *px,double *py)      /* ３次元回転変換 */
{
    double x1,y1,z1,x2,y2;
    x1=x*cos(ay)+z*sin(ay);        /* ｙ軸回り */
    y1=y;
    z1=-x*sin(ay)+z*cos(ay);
    x2=x1;                         /* ｘ軸回り */
    y2=y1*cos(ax)-z1*sin(ax);
    *px=x2*cos(az)-y2*sin(az);     /* ｚ軸回り */
    *py=x2*sin(az)+y2*cos(az);
}

void CRei59View::OnDraw(CDC* pDC)
{
	CRei59Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
    struct {
        int f;
        double x,y,z;
    } a[]
    ={-1,80,50,100,   1,0,50,100,   1,0,0,100,    1,80,0,100,
      1,80,0,0,       1,80,50,0,    1,80,50,100,  1,80,0,100,
      -1,0,50,100,    1,0,50,0,     1,0,0,0,      1,0,0,100,
      -1,0,50,0,      1,80,50,0,    -1,0,0,0,     1,80,0,0,
      -1,0,50,100,    1,40,80,100,  1,80,50,100,  -1,0,50,0,
      1,40,80,0,      1,80,50,0,    -1,40,80,100, 1,40,80,0,
      -1,50,72,100,   1,50,90,100,  1,65,90,100,  1,65,61,100,
      1,65,61,80,     1,65,90,80,   1,50,90,80,   1,50,90,100,
      -1,65,90,100,   1,65,90,80,   -1,50,90,80,  1,50,72,80,
      1,65,61,80,     -1,50,72,100, 1,50,72,80,   -999,0,0,0  };

    int k;
    double ax=20*3.14159/180,
           ay=-45*3.14159/180,
           az=0*3.14159/180,
           px,py;

    ginit(); cls();
    window(-160,-100,160,100);
    for (k=0;a[k].f!=-999;k++){
        rotate(ax,ay,az,a[k].x,a[k].y,a[k].z,&px,&py);
        if (a[k].f==-1)          /* 始点なら */
            setpoint(px,py);
        else
            moveto(px,py);
    }
}


// CRei59View 印刷

BOOL CRei59View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CRei59View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CRei59View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CRei59View 診断

#ifdef _DEBUG
void CRei59View::AssertValid() const
{
	CView::AssertValid();
}

void CRei59View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRei59Doc* CRei59View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei59Doc)));
	return (CRei59Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei59View メッセージ ハンドラ
