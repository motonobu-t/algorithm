// Dr58View.cpp : CDr58View クラスの実装
//

#include "stdafx.h"
#include "Dr58.h"

#include "Dr58Doc.h"
#include "Dr58View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr58View

IMPLEMENT_DYNCREATE(CDr58View, CView)

BEGIN_MESSAGE_MAP(CDr58View, CView)
	// 標準印刷コマンド
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CDr58View コンストラクション/デストラクション

CDr58View::CDr58View()
{
	// TODO: 構築コードをここに追加します。

}

CDr58View::~CDr58View()
{
}

BOOL CDr58View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CView::PreCreateWindow(cs);
}

// CDr58View 描画
/*
 * -------------------
 *      √２分割     *
 * -------------------
 */

#include "mfcglib.h"

void CDr58View::OnDraw(CDC* pDC)
{
	CDr58Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: この場所にネイティブ データ用の描画コードを追加します。
    int k;
    double leng=400.0,            /* 対角線の初期値 */
           rd=3.14159/180,
           x,y;

    ginit(); cls();
    setpoint(0,380); setangle(-54.7);
    for (k=1;k<=10;k++){
        move(leng);                 /* 対角線を引く */
        x=leng*cos(54.7*rd);        /* ｘ方向の長さ */
        y=leng*sin(54.7*rd);        /* ｙ方向の長さ */
        turn(180-35.3); move(y);    /* 長方形を描く */
        turn(90); move(x);
        turn(90); move(y);
        turn(90); move(x);
        turn(35.3);
        leng=leng/sqrt(2.0);
    }
}


// CDr58View 印刷

BOOL CDr58View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 既定の印刷準備
	return DoPreparePrinting(pInfo);
}

void CDr58View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷前の特別な初期化処理を追加してください。
}

void CDr58View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 印刷後の後処理を追加してください。
}


// CDr58View 診断

#ifdef _DEBUG
void CDr58View::AssertValid() const
{
	CView::AssertValid();
}

void CDr58View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDr58Doc* CDr58View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr58Doc)));
	return (CDr58Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr58View メッセージ ハンドラ
