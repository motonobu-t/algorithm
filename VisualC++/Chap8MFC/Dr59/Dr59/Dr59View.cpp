// Dr59View.cpp : CDr59View クラスの実装
//

#include "stdafx.h"
#include "Dr59.h"

#include "Dr59Doc.h"
#include "Dr59View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr59View

IMPLEMENT_DYNCREATE(CDr59View, CView)

BEGIN_MESSAGE_MAP(CDr59View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr59View コンストラクション/デストラクション

CDr59View::CDr59View()
{
	// TODO: 構築コードをここに追加します。

}

CDr59View::~CDr59View()
{
}

BOOL CDr59View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CDr59View 描画
/*
 * -------------------
 *      透視変換     *
 * -------------------
 */

#include "mfcglib.h"

void CDr59View::OnDraw(CDC* pDC)
{
	CDr59Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
    struct {
        int f;
        double x,y,z;
    }a[]
      ={-1,80,50,100,   1,0,50,100,   1,0,0,100,    1,80,0,100,
        1,80,0,0,       1,80,50,0,    1,80,50,100,  1,80,0,100,
        -1,0,50,100,    1,0,50,0,     1,0,0,0,      1,0,0,100,
        -1,0,50,0,      1,80,50,0,    -1,0,0,0,     1,80,0,0,
        -1,0,50,100,    1,40,80,100,  1,80,50,100,  -1,0,50,0,
        1,40,80,0,      1,80,50,0,    -1,40,80,100, 1,40,80,0,
        -1,50,72,100,   1,50,90,100,  1,65,90,100,  1,65,61,100,
        1,65,61,80,     1,65,90,80,   1,50,90,80,   1,50,90,100,
        -1,65,90,100,   1,65,90,80,   -1,50,90,80,  1,50,72,80,
        1,65,61,80,     -1,50,72,100, 1,50,72,80,   -999,0,0,0 };

    double ay=-35*3.14159/180,    /* ｙ軸回りの回転角 */
           vp=-300.0,             /* 投影中心 */
           l=-25.0,               /* ｘ方向の移動量 */
           m=-70.0,               /* ｙ方向の移動量 */
           n=0.0,                 /* ｚ方向の移動量*/
           h,px,py;
    int k;

    ginit(); cls();
    window(-320,-200,320,200);
    for (k=0;a[k].f!=-999;k++){
                                              /* 透視変換 */
        h=-a[k].x*sin(ay)/vp+a[k].z*cos(ay)/vp+n/vp+1;
        px=(a[k].x*cos(ay)+a[k].z*sin(ay)+l)/h;
        py=(a[k].y+m)/h;

        if (a[k].f==-1)
            setpoint(px,py);
        else
            moveto(px,py);
    }
}


// CDr59View 印刷

BOOL CDr59View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CDr59View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CDr59View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CDr59View 診断

#ifdef _DEBUG
void CDr59View::AssertValid() const
{
	CView::AssertValid();
}

void CDr59View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr59Doc* CDr59View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr59Doc)));
	return (CDr59Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr59View メッセージ ハンドラ
