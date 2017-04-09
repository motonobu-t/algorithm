// Dr1_1View.cpp : CDr1_1View クラスの実装
//

#include "stdafx.h"
#include "Dr1_1.h"

#include "Dr1_1Doc.h"
#include "Dr1_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr1_1View

IMPLEMENT_DYNCREATE(CDr1_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr1_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr1_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr1_1View コンストラクション/デストラクション

CDr1_1View::CDr1_1View()
	: CFormView(CDr1_1View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr1_1View::~CDr1_1View()
{
}

void CDr1_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr1_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr1_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr1_1View 診断

#ifdef _DEBUG
void CDr1_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr1_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr1_1Doc* CDr1_1View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr1_1Doc)));
	return (CDr1_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr1_1View メッセージ ハンドラ
/*
 * --------------------------
 *     Ｈｏｒｎｅｒの方法   *
 * --------------------------
 */

#include "mfcform.h"
double fn(double x,double a[],int n)
{
    double p;
    int i;

    p=a[n];
    for (i=n-1;i>=0;i--)
        p=p*x+a[i];
    return p;
}

void CDr1_1View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    double a[]={1,2,3,4,5};    /* 係数 */
    double x;
	tinit();cls();
    for (x=1;x<=5;x++)
        printf("fn(%f)=%f\n",x,fn(x,a,4));
	tfin();
}
