// Dr4View.cpp : CDr4View クラスの実装
//

#include "stdafx.h"
#include "Dr4.h"

#include "Dr4Doc.h"
#include "Dr4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr4View

IMPLEMENT_DYNCREATE(CDr4View, CFormView)

BEGIN_MESSAGE_MAP(CDr4View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr4View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr4View コンストラクション/デストラクション

CDr4View::CDr4View()
	: CFormView(CDr4View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr4View::~CDr4View()
{
}

void CDr4View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr4View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr4View 診断

#ifdef _DEBUG
void CDr4View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr4View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr4Doc* CDr4View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr4Doc)));
	return (CDr4Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr4View メッセージ ハンドラ
/*
 * ------------------------------------
 *      ランダムな順列（改良版）      *
 * ------------------------------------
 */

#include "mfcform.h"

#define N 20
int irnd(int n)        /* １～ｎの乱数 */
{
    return (int)(rand()/(RAND_MAX+0.1)*n+1);
}
void CDr4View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i,j,d,a[N+1];

	for (i=1;i<=N;i++)
        a[i]=i;

    for (i=N;i>1;i--){
        j=irnd(i-1);
        d=a[i];a[i]=a[j];a[j]=d;
    }

	tinit();cls();
    for (i=1;i<=N;i++)
        printf("%d ",a[i]);
    printf("\n");
	tfin();
}
