// Dr57View.cpp : CDr57View クラスの実装
//

#include "stdafx.h"
#include "Dr57.h"

#include "Dr57Doc.h"
#include "Dr57View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr57View

IMPLEMENT_DYNCREATE(CDr57View, CView)

BEGIN_MESSAGE_MAP(CDr57View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr57View コンストラクション/デストラクション

CDr57View::CDr57View()
{
	// TODO: 構築コードをここに追加します。

}

CDr57View::~CDr57View()
{
}

BOOL CDr57View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CDr57View 描画
/*
 * ------------------------
 *     ２次元回転変換     *
 * ------------------------
 */

#include "mfcglib.h"

void multi(double factx,double facty,double *x,double *y)
{
    *x=factx*(*x);
    *y=facty*(*y);
}
void rotate(double deg,double *x,double *y)	/* 回転変換 */
{
    double dx,dy,rd=3.14159/180;
    dx=(*x)*cos(deg*rd)-(*y)*sin(deg*rd);
    dy=(*x)*sin(deg*rd)+(*y)*cos(deg*rd);
    *x=dx; *y=dy;
}

void CDr57View::OnDraw(CDC* pDC)
{
	CDr57Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
    double x[]={0,100,100,  0,0},
           y[]={0,  0,200,200,0};
    int j,k,n=5;

    ginit(); cls(); window(-320,-200,320,200);

    for (j=0;j<12;j++){
        for (k=0;k<n;k++){
            multi(.8,.8,&x[k],&y[k]);
            rotate(30,&x[k],&y[k]);
            if (k==0)
                setpoint(x[k],y[k]);
            else
                moveto(x[k],y[k]);
        }
    }
}


// CDr57View 印刷

BOOL CDr57View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CDr57View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CDr57View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CDr57View 診断

#ifdef _DEBUG
void CDr57View::AssertValid() const
{
	CView::AssertValid();
}

void CDr57View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr57Doc* CDr57View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr57Doc)));
	return (CDr57Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr57View メッセージ ハンドラ
