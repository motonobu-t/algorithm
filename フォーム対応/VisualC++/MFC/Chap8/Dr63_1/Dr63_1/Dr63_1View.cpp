// Dr63_1View.cpp : CDr63_1View クラスの実装
//

#include "stdafx.h"
#include "Dr63_1.h"

#include "Dr63_1Doc.h"
#include "Dr63_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr63_1View

IMPLEMENT_DYNCREATE(CDr63_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr63_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr63_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr63_1View コンストラクション/デストラクション

CDr63_1View::CDr63_1View()
	: CFormView(CDr63_1View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr63_1View::~CDr63_1View()
{
}

void CDr63_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr63_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr63_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr63_1View 診断

#ifdef _DEBUG
void CDr63_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr63_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr63_1Doc* CDr63_1View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr63_1Doc)));
	return (CDr63_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr63_1View メッセージ ハンドラ
/*
 * --------------------------
 *       樹木曲線その２     *
 * --------------------------
 */

#include "mfcform.h"
void ctree(int n,double x0,double y0,double leng,double angle)
                                  /* 樹木曲線の再帰手続き */
{
    double rd=3.14159/180;
    int k;

    if (n==0)
        return;

    setpoint(x0,y0);setangle(angle);
    for (k=1;k<=4;k++){        /* 正方形を描く */
        turn(90);
        move(leng);
    }

    ctree(n-1,x0+leng*cos((angle-45)*rd)/sqrt(2.0),  /* 右部分木 */
              y0+leng*sin((angle-45)*rd)/sqrt(2.0),
              leng/sqrt(2.0),angle-45);
    ctree(n-1,x0+sqrt(2.0)*leng*cos((angle+45)*rd),  /* 左部分木 */
              y0+sqrt(2.0)*leng*sin((angle+45)*rd),
              leng/sqrt(2.0),angle+45);
}

void CDr63_1View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int    n=9;               /* 枝の次数 */
    double x0=0.0,y0=50.0,    /* 根の位置 */
           leng=100.0,        /* 枝の長さ */
           angle=90.0;        /* 枝の向き */

    ginit(); cls();
    window(-640,-400,640,400);

    ctree(n,x0,y0,leng,angle);    /* 再帰呼び出し */
}
