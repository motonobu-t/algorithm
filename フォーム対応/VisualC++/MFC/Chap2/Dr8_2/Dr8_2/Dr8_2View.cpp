// Dr8_2View.cpp : CDr8_2View クラスの実装
//

#include "stdafx.h"
#include "Dr8_2.h"

#include "Dr8_2Doc.h"
#include "Dr8_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr8_2View

IMPLEMENT_DYNCREATE(CDr8_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr8_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr8_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr8_2View コンストラクション/デストラクション

CDr8_2View::CDr8_2View()
	: CFormView(CDr8_2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr8_2View::~CDr8_2View()
{
}

void CDr8_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr8_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr8_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr8_2View 診断

#ifdef _DEBUG
void CDr8_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr8_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr8_2Doc* CDr8_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr8_2Doc)));
	return (CDr8_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr8_2View メッセージ ハンドラ
/*
 * -------------------------------------------
 *      正規乱数（ボックス・ミュラー法）     *
 * -------------------------------------------
 */

#include "mfcform.h"

void brnd(double sig,double m,double *x,double *y)
{
    double r1,r2;
    r1=rand()/(RAND_MAX+0.1); r2=rand()/(RAND_MAX+0.1);
    *x=sig*sqrt(-2*log(r1))*cos(2*3.14159*r2)+m;
    *y=sig*sqrt(-2*log(r1))*sin(2*3.14159*r2)+m;
}
void CDr8_2View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i,j,hist[100];
    double x,y;

    for (i=0;i<100;i++)
        hist[i]=0;

    for (i=0;i<1000;i++){
        brnd(2.5,10.0,&x,&y);
        hist[(int)x]++;
        hist[(int)y]++;
    }

	tinit();cls();
    for (i=0;i<=20;i++){            /* ヒスト・グラムの表示 */
        printf("%3d : I ",i);
        for (j=1;j<=hist[i]/10;j++){
            printf("*");
        }
        printf("\n");
    }
	tfin();
}
