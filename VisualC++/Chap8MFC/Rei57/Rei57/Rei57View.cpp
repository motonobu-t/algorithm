// Rei57View.cpp : CRei57View クラスの実装
//

#include "stdafx.h"
#include "Rei57.h"

#include "Rei57Doc.h"
#include "Rei57View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei57View

IMPLEMENT_DYNCREATE(CRei57View, CView)

BEGIN_MESSAGE_MAP(CRei57View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CRei57View コンストラクション/デストラクション

CRei57View::CRei57View()
{
	// TODO: 構築コードをここに追加します。

}

CRei57View::~CRei57View()
{
}

BOOL CRei57View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CRei57View 描画
/*
 * -------------------
 *      対称移動     *
 * -------------------
 */

#include "mfcglib.h"

void mirror(int flag,double m,double *dat)    /* 対称移動 */
{
    int i;
    for (i=1;i<=2*dat[0];i=i+2){    /* dat[0]はデータ数 */
        if (flag==1)                /* ｙ軸中心 */
            dat[i]=2*m-dat[i];
        if (flag==0)                /* ｘ軸中心 */
            dat[i+1]=2*m-dat[i+1];
    }
}
void draw(double *dat)              /* 図形の描画 */
{
    int i;
    setpoint(dat[1],dat[2]);        /* 始点 */
    for (i=3;i<=2*dat[0];i=i+2)     /* dat[0]はデータ数 */
        moveto(dat[i],dat[i+1]);
}

void CRei57View::OnDraw(CDC* pDC)
{
	CRei57Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
    double a[]={11,0,80,5,75,17,80,20,60,15,55,0,55,
                 0,20,10,40,20,40,10,20,0,20};
    ginit(); cls(); window(-160,-100,160,100);

    draw(a);
    mirror(1,0.0,a);draw(a);
    mirror(0,0.0,a);draw(a);
    mirror(1,0.0,a);draw(a);
}


// CRei57View 印刷

BOOL CRei57View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CRei57View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CRei57View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CRei57View 診断

#ifdef _DEBUG
void CRei57View::AssertValid() const
{
	CView::AssertValid();
}

void CRei57View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRei57Doc* CRei57View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei57Doc)));
	return (CRei57Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei57View メッセージ ハンドラ
