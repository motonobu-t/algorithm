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

IMPLEMENT_DYNCREATE(CDr57View, CFormView)

BEGIN_MESSAGE_MAP(CDr57View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr57View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr57View コンストラクション/デストラクション

CDr57View::CDr57View()
	: CFormView(CDr57View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr57View::~CDr57View()
{
}

void CDr57View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr57View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr57View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr57View 診断

#ifdef _DEBUG
void CDr57View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr57View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr57Doc* CDr57View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr57Doc)));
	return (CDr57Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr57View メッセージ ハンドラ
/*
 * ------------------------
 *     ２次元回転変換     *
 * ------------------------
 */

#include "mfcform.h"

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

void CDr57View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
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
