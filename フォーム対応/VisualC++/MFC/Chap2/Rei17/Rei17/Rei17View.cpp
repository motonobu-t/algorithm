// Rei17View.cpp : CRei17View クラスの実装
//

#include "stdafx.h"
#include "Rei17.h"

#include "Rei17Doc.h"
#include "Rei17View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei17View

IMPLEMENT_DYNCREATE(CRei17View, CFormView)

BEGIN_MESSAGE_MAP(CRei17View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei17View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei17View コンストラクション/デストラクション

CRei17View::CRei17View()
	: CFormView(CRei17View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei17View::~CRei17View()
{
}

void CRei17View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei17View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei17View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei17View 診断

#ifdef _DEBUG
void CRei17View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei17View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei17Doc* CRei17View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei17Doc)));
	return (CRei17Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei17View メッセージ ハンドラ
/*
 * ---------------------
 *      最小２乗法     *
 * ---------------------
 */

#include "mfcform.h"

#define N 7             /* データ数 */
#define M 5             /* 当てはめ次数 */
double ipow(double p,int n)        /* ｐ＾ｎ　を求める関数 */
{
    int k;
    double s=1;
    for (k=1;k<=n;k++)
        s=s*p;
    return s;
}

void CRei17View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    double x[]={-3,-2,-1, 0,1,2,3},
           y[]={ 5,-2,-3,-1,1,4,5},
           a[M+1][M+2],s[2*M+1],t[M+1];

    int i,j,k;
    double p,d,px;

    for (i=0;i<=2*M;i++)
        s[i]=0;
    for (i=0;i<=M;i++)
        t[i]=0;

    for (i=0;i<N;i++){
        for (j=0;j<=2*M;j++)                /* s0 から s2m の計算 */
            s[j]=s[j]+ipow(x[i],j);
        for (j=0;j<=M;j++)                  /* t0 から tm の計算 */
            t[j]=t[j]+ipow(x[i],j)*y[i];
    }

    for (i=0;i<=M;i++){               /* a[][] に s[],t[] の値を入れる */
        for (j=0;j<=M;j++)
            a[i][j]=s[i+j];
        a[i][M+1]=t[i];
    }

    for (k=0;k<=M;k++){             /* はき出し */
        p=a[k][k];
        for (j=k;j<=M+1;j++)
            a[k][j]=a[k][j]/p;
        for (i=0;i<=M;i++){
            if (i!=k){
                d=a[i][k];
                for (j=k;j<=M+1;j++)
                    a[i][j]=a[i][j]-d*a[k][j];
            }
        }
    }

	tinit();cls();
    printf("    x    y\n");        /* 補間多項式によるｙの値の計算 */
    for (px=-3;px<=3;px=px+.5){
        p=0;
        for (k=0;k<=M;k++)
            p=p+a[k][M+1]*ipow(px,k);

        printf("%5.1f%5.1f\n",px,p);
    }
	tfin();
}
