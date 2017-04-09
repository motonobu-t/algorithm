// Dr61View.cpp : CDr61View クラスの実装
//

#include "stdafx.h"
#include "Dr61.h"

#include "Dr61Doc.h"
#include "Dr61View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr61View

IMPLEMENT_DYNCREATE(CDr61View, CView)

BEGIN_MESSAGE_MAP(CDr61View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr61View コンストラクション/デストラクション

CDr61View::CDr61View()
{
	// TODO: 構築コードをここに追加します。

}

CDr61View::~CDr61View()
{
}

BOOL CDr61View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CDr61View 描画

/*
 * --------------------------------
 *      ３次元関数の陰線処理      *
 * --------------------------------
 */

#include "mfcglib.h"

void CDr61View::OnDraw(CDC* pDC)
{
	CDr61Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
    int ymin[640],ymax[640];
    int k,px,py;
    double cos_x,sin_x,cos_y,sin_y,x,y,z,rd=3.1415927/180;

    ginit(); cls();
    for (k=0;k<640;k++){        /* 最大・最小判定配列 */
        ymin[k]=399;ymax[k]=0;
    }
    cos_x=cos(30*rd);  sin_x=sin(30*rd);
    cos_y=cos(-30*rd); sin_y=sin(-30*rd);
    for (z=200.0;z>=-200.0;z=z-10.0){
        for (x=-200.0;x<=200.0;x++){
            y=30*(cos(sqrt(x*x+z*z)*rd)+cos(3*sqrt(x*x+z*z)*rd));
            px=(int)(x*cos_y+z*sin_y+320);              /* 回転変換 */
            py=(int)(y*cos_x-(-x*sin_y+z*cos_y)*sin_x+200);
            if (py<ymin[px]){               /* 今までの最小より小さい */
                ymin[px]=py;pset(px,py);
            }
            if (py>ymax[px]){               /* 今までの最大より大きい */
                ymax[px]=py;pset(px,py);
            }
        }
    }
}


// CDr61View 印刷

BOOL CDr61View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CDr61View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CDr61View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CDr61View 診断

#ifdef _DEBUG
void CDr61View::AssertValid() const
{
	CView::AssertValid();
}

void CDr61View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr61Doc* CDr61View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr61Doc)));
	return (CDr61Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr61View メッセージ ハンドラ
