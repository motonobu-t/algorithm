// Rei58View.cpp : CRei58View クラスの実装
//

#include "stdafx.h"
#include "Rei58.h"

#include "Rei58Doc.h"
#include "Rei58View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei58View

IMPLEMENT_DYNCREATE(CRei58View, CFormView)

BEGIN_MESSAGE_MAP(CRei58View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei58View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei58View コンストラクション/デストラクション

CRei58View::CRei58View()
	: CFormView(CRei58View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei58View::~CRei58View()
{
}

void CRei58View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei58View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei58View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei58View 診断

#ifdef _DEBUG
void CRei58View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei58View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei58Doc* CRei58View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei58Doc)));
	return (CRei58Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei58View メッセージ ハンドラ
/*
 * --------------------
 *       対称模様     *
 * --------------------
 */

#include "mfcform.h"

#define N 9     /* データ数 */

void CRei58View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    double x[]={ 35, 19,10, 3,0,-3,-10,-19,-35},
           y[]={-20,-20,-5,-5,0,-5, -5,-20,-20};
    int a,b,j,k;
    double rd=3.14159/180,
           m,h,vy,vx,px,py;

    ginit(); cls();
    m=70.0; h=m*sqrt(3.0)/2;      /* 正３角形の辺の長さ、高さ */
    window(-m/2,-h/3,m/2,h*2/3);
    b=1;
    for (vy=0.0;vy<=310.0;vy=vy+h){
        a=1;
        for (vx=50.0;vx<=500.0;vx=vx+m/2){
            view(vx,vy,vx+m,vy+h);        /* ビューポートの設定 */
            for (j=0;j<3;j++){
                for (k=0;k<N;k++){
                    px=x[k]*cos(120*j*rd)-y[k]*sin(120*j*rd);
                    py=x[k]*sin(120*j*rd)+y[k]*cos(120*j*rd);
                    if (a*b==-1)
                        py=-py+h/3;        /* 逆像補正 */
                    if (k==0)
                        setpoint(px,py);
                    else
                        moveto(px,py);
                }
            }
            a=-a;
        }
        b=-b;
    }
}
