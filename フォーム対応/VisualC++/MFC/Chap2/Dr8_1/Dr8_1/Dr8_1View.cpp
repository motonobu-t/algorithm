// Dr8_1View.cpp : CDr8_1View クラスの実装
//

#include "stdafx.h"
#include "Dr8_1.h"

#include "Dr8_1Doc.h"
#include "Dr8_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr8_1View

IMPLEMENT_DYNCREATE(CDr8_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr8_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr8_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr8_1View コンストラクション/デストラクション

CDr8_1View::CDr8_1View()
	: CFormView(CDr8_1View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr8_1View::~CDr8_1View()
{
}

void CDr8_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr8_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr8_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr8_1View 診断

#ifdef _DEBUG
void CDr8_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr8_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr8_1Doc* CDr8_1View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr8_1Doc)));
	return (CDr8_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr8_1View メッセージ ハンドラ
/*
 * ----------------------
 *     一様性の検定　   *
 * ----------------------
 */

#include "mfcform.h"

#define N 1000             /* 乱数の発生回数 */
#define M 10               /* 整数乱数の範囲 */
#define F (N/M)            /* 期待値 */
#define SCALE (40.0/F)     /* ヒストグラムの高さ（自動スケール） */

unsigned rndnum=13;        /* 乱数の初期値 */
unsigned irnd(void)        /* 0～32767の整数乱数 */
{
    rndnum=(rndnum*109+1021) % 32768;
    return rndnum;
}
double rnd(void)           /* 0～1未満の実数乱数 */
{
    return irnd()/32767.1;
}

void CDr8_1View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i,j,rank,hist[M+1];
    double e=0.0;

    for (i=1;i<=M;i++)
        hist[i]=0;

    for (i=0;i<N;i++){
        rank=(int)(M*rnd()+1);         /* 1～Mの乱数を１つ発生 */
        hist[rank]++;
    }

	tinit();cls();
    for (i=1;i<=M;i++){
        printf("%3d:%3d ",i,hist[i]);
        for (j=0;j<hist[i]*SCALE;j++)      /* ヒストグラムの表示 */
            printf("*");
        printf("\n");

        e=e+(double)(hist[i]-F)*(hist[i]-F)/F;        /* χ2の計算 */
    }
    printf("χ2=%f\n",e);
	tfin();
}
