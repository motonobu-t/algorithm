// Rei60View.cpp : CRei60View クラスの実装
//

#include "stdafx.h"
#include "Rei60.h"

#include "Rei60Doc.h"
#include "Rei60View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei60View

IMPLEMENT_DYNCREATE(CRei60View, CFormView)

BEGIN_MESSAGE_MAP(CRei60View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei60View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei60View コンストラクション/デストラクション

CRei60View::CRei60View()
	: CFormView(CRei60View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei60View::~CRei60View()
{
}

void CRei60View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei60View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei60View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei60View 診断

#ifdef _DEBUG
void CRei60View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei60View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei60Doc* CRei60View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei60Doc)));
	return (CRei60Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei60View メッセージ ハンドラ
/*
 * -------------------------------------
 *      回転体モデル（ワイングラス）   *
 * -------------------------------------
 */

#include "mfcform.h"
void rotate(double ax,double ay,double az,double x,double y,double z,
            double *px,double *py)   /* ３次元回転変換 */
{
    double x1,y1,z1,x2,y2;
    x1=x*cos(ay)+z*sin(ay);          /* ｙ軸回り */
    y1=y;
    z1=-x*sin(ay)+z*cos(ay);
    x2=x1;                           /* ｘ軸回り */
    y2=y1*cos(ax)-z1*sin(ax);
    *px=x2*cos(az)-y2*sin(az);       /* ｚ軸回り */
    *py=x2*sin(az)+y2*cos(az);
}

void CRei60View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int n,k;
    double x,z,px,py,ax,ay,az,rd=3.14159/180;
    double y[]={180,140,100,60,20,10,4,0,-999},   /* 高さ */
           r[]={100,55,10,10,10,50,80,80,-999};   /* 半径 */
    ax=35*rd;   /* ｘ軸回りの回転角 */
    ay=0;       /* ｙ軸回りの回転角 */
    az=20*rd;   /* ｚ軸回りの回転角 */

    ginit(); cls();
    window(-320,-100,320,300);

    for (k=0;(int)y[k]!=-999;k++){    /* ｙ軸回りの回転軌跡 */
        for (n=0;n<=360;n=n+10){
            x=r[k]*cos(n*rd);
            z=r[k]*sin(n*rd);
            rotate(ax,ay,az,x,y[k],z,&px,&py);
            if (n==0)
                setpoint(px,py);
            else
                moveto(px,py);
        }
    }
    for (n=0;n<=360;n=n+60){        /* 稜線 */
        for (k=0;(int)y[k]!=-999;k++){
            x=r[k]*cos(n*rd);
            z=r[k]*sin(n*rd);
            rotate(ax,ay,az,x,y[k],z,&px,&py);
            if (k==0)
                setpoint(px,py);
            else
                moveto(px,py);
        }
    }
}
