// Dr14_1View.cpp : CDr14_1View クラスの実装
//

#include "stdafx.h"
#include "Dr14_1.h"

#include "Dr14_1Doc.h"
#include "Dr14_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr14_1View

IMPLEMENT_DYNCREATE(CDr14_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr14_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr14_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr14_1View コンストラクション/デストラクション

CDr14_1View::CDr14_1View()
	: CFormView(CDr14_1View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr14_1View::~CDr14_1View()
{
}

void CDr14_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr14_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr14_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr14_1View 診断

#ifdef _DEBUG
void CDr14_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr14_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr14_1Doc* CDr14_1View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr14_1Doc)));
	return (CDr14_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr14_1View メッセージ ハンドラ
/*
 * -----------------------
 *      ｅの多桁計算     *
 * -----------------------
 */

#include "mfcform.h"

#define L 1000          /* 求める桁数      */
#define L1 ((L/4)+1)    /* 配列のサイズ    */
#define L2 (L1+1)       /* 一つ余分に取る  */
#define N 451           /* 計算する項数    */
void printresult(short c[])       /* 結果の表示 */
{
    short i;
    printf("%3d. ",c[0]);         /* 最上位桁の表示 */
	for (i=1;i<L1;i++)
        printf("%04d ",c[i]);
    printf("\n");
}
void ladd(short a[],short b[],short c[])
{
    short i,cy=0;
    for (i=L2;i>=0;i--){
        c[i]=a[i]+b[i]+cy;
        if (c[i]<10000)
            cy=0;
        else {
            c[i]=c[i]-10000;
            cy=1;
        }
    }
}
void lsub(short a[],short b[],short c[])
{
    short i,brrw=0;
    for (i=L2;i>=0;i--){
        c[i]=a[i]-b[i]-brrw;
        if (c[i]>=0)
            brrw=0;
        else {
            c[i]=c[i]+10000;
            brrw=1;
        }
    }
}
void ldiv(short a[],short b,short c[])    /* ロング数÷ショート数 */
{
    short i;long d,rem=0;
    for (i=0;i<=L2;i++){
        d=a[i];
        c[i]=(short)((d+rem)/b);
        rem=((d+rem)%b)*10000;
    }
}

void CDr14_1View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    short s[L2+2],w[L2+2];
    short k;

    for (k=0;k<=L2;k++)
        s[k]=w[k]=0;

    s[0]=w[0]=1;
    for (k=1;k<=N;k++){
        ldiv(w,k,w);
        ladd(s,w,s);
    }

	tinit();cls();
    printresult(s);
	tfin();
}
