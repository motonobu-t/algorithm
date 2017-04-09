// Dr59View.cpp : CDr59View クラスの実装
//

#include "stdafx.h"
#include "Dr59.h"

#include "Dr59Doc.h"
#include "Dr59View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr59View

IMPLEMENT_DYNCREATE(CDr59View, CFormView)

BEGIN_MESSAGE_MAP(CDr59View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr59View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr59View コンストラクション/デストラクション

CDr59View::CDr59View()
	: CFormView(CDr59View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr59View::~CDr59View()
{
}

void CDr59View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr59View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr59View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr59View 診断

#ifdef _DEBUG
void CDr59View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr59View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr59Doc* CDr59View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr59Doc)));
	return (CDr59Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr59View メッセージ ハンドラ
/*
 * -------------------
 *      透視変換     *
 * -------------------
 */

#include "mfcform.h"
void CDr59View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    struct {
        int f;
        double x,y,z;
    }a[]
      ={-1,80,50,100,   1,0,50,100,   1,0,0,100,    1,80,0,100,
        1,80,0,0,       1,80,50,0,    1,80,50,100,  1,80,0,100,
        -1,0,50,100,    1,0,50,0,     1,0,0,0,      1,0,0,100,
        -1,0,50,0,      1,80,50,0,    -1,0,0,0,     1,80,0,0,
        -1,0,50,100,    1,40,80,100,  1,80,50,100,  -1,0,50,0,
        1,40,80,0,      1,80,50,0,    -1,40,80,100, 1,40,80,0,
        -1,50,72,100,   1,50,90,100,  1,65,90,100,  1,65,61,100,
        1,65,61,80,     1,65,90,80,   1,50,90,80,   1,50,90,100,
        -1,65,90,100,   1,65,90,80,   -1,50,90,80,  1,50,72,80,
        1,65,61,80,     -1,50,72,100, 1,50,72,80,   -999,0,0,0 };

    double ay=-35*3.14159/180,    /* ｙ軸回りの回転角 */
           vp=-300.0,             /* 投影中心 */
           l=-25.0,               /* ｘ方向の移動量 */
           m=-70.0,               /* ｙ方向の移動量 */
           n=0.0,                 /* ｚ方向の移動量*/
           h,px,py;
    int k;

    ginit(); cls();
    window(-320,-200,320,200);
    for (k=0;a[k].f!=-999;k++){
                                              /* 透視変換 */
        h=-a[k].x*sin(ay)/vp+a[k].z*cos(ay)/vp+n/vp+1;
        px=(a[k].x*cos(ay)+a[k].z*sin(ay)+l)/h;
        py=(a[k].y+m)/h;

        if (a[k].f==-1)
            setpoint(px,py);
        else
            moveto(px,py);
    }
}
