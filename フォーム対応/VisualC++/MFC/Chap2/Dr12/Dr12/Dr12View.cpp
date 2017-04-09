// Dr12View.cpp : CDr12View クラスの実装
//

#include "stdafx.h"
#include "Dr12.h"

#include "Dr12Doc.h"
#include "Dr12View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr12View

IMPLEMENT_DYNCREATE(CDr12View, CFormView)

BEGIN_MESSAGE_MAP(CDr12View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr12View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr12View コンストラクション/デストラクション

CDr12View::CDr12View()
	: CFormView(CDr12View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr12View::~CDr12View()
{
}

void CDr12View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr12View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr12View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr12View 診断

#ifdef _DEBUG
void CDr12View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr12View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr12Doc* CDr12View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr12Doc)));
	return (CDr12Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr12View メッセージ ハンドラ
/*
 * -------------------------
 *      ニュートン補間     *
 * -------------------------
 */

#include "mfcform.h"
double newton(double x[],double y[],int n,double t)
{
    static int flag=1;
    static double a[100];      /* 係数配列 */
    double        w[100],      /* 作業用   */
           s;
    int i,j;

    if (flag==1){    /* １度目に呼ばれた時だけ a[] に係数を求める */
        for (i=0;i<n;i++){
            w[i]=y[i];
            for (j=i-1;j>=0;j--)
                w[j]=(w[j+1]-w[j])/(x[i]-x[j]);
            a[i]=w[0];
        }
        flag=-1;
    }

    s=a[n-1];               /* x=t における補間 */
    for (i=n-2;i>=0;i--)
        s=s*(t-x[i])+a[i];
    return s;
}

void CDr12View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    double x[]={0.0,1.0,3.0,6.0,7.0},
           y[]={0.8,3.1,4.5,3.9,2.8};

    double t;
	tinit();cls();
    printf("      x      y\n");
    for (t=0.0;t<=7.0;t=t+.5)
        printf("%7.2f%7.2f\n",t,newton(x,y,5,t));
	tfin();
}
