// Dr63_5View.cpp : CDr63_5View クラスの実装
//

#include "stdafx.h"
#include "Dr63_5.h"

#include "Dr63_5Doc.h"
#include "Dr63_5View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr63_5View

IMPLEMENT_DYNCREATE(CDr63_5View, CView)

BEGIN_MESSAGE_MAP(CDr63_5View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr63_5View コンストラクション/デストラクション

CDr63_5View::CDr63_5View()
{
	// TODO: 構築コードをここに追加します。

}

CDr63_5View::~CDr63_5View()
{
}

BOOL CDr63_5View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CDr63_5View 描画
/*
 * -------------------------------
 *      シェルピンスキー曲線     *
 * -------------------------------
 */

#include "mfcglib.h"

void sierpin(int n,double l)
{
    if (n==0){
        turn(-90);
        return;
    }
    sierpin(n-1,l);move(l);
    sierpin(n-1,l);turn(135);move(l);
    turn(135);sierpin(n-1,l);move(l);
    sierpin(n-1,l);
}

void CDr63_5View::OnDraw(CDC* pDC)
{
	CDr63_5Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
    int i,n =3,         /* 次数 */
        leng=10;        /* 長さ */

    ginit(); cls();

    setpoint(350,300);setangle(-45);
    for (i=0;i<4;i++){
        move(leng);
        sierpin(n,leng);
    }
}


// CDr63_5View 印刷

BOOL CDr63_5View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CDr63_5View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CDr63_5View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CDr63_5View 診断

#ifdef _DEBUG
void CDr63_5View::AssertValid() const
{
	CView::AssertValid();
}

void CDr63_5View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr63_5Doc* CDr63_5View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr63_5Doc)));
	return (CDr63_5Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr63_5View メッセージ ハンドラ
