// Dr1_2View.cpp : CDr1_2View クラスの実装
//

#include "stdafx.h"
#include "Dr1_2.h"

#include "Dr1_2Doc.h"
#include "Dr1_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr1_2View

IMPLEMENT_DYNCREATE(CDr1_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr1_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr1_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr1_2View コンストラクション/デストラクション

CDr1_2View::CDr1_2View()
	: CFormView(CDr1_2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr1_2View::~CDr1_2View()
{
}

void CDr1_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr1_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr1_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr1_2View 診断

#ifdef _DEBUG
void CDr1_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr1_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr1_2Doc* CDr1_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr1_2Doc)));
	return (CDr1_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr1_2View メッセージ ハンドラ
/*
 * --------------------------------
 *      Ｐａｓｃａｌの三角形      *
 * --------------------------------
 */

#include "mfcform.h"
#define N 12
long combi(int n,int r)
{
    int i;
    long p=1;

    for (i=1;i<=r;i++)
        p=p*(n-i+1)/i;
    return p;
}
void CDr1_2View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int n,r,t;
	tinit();cls();
    for (n=0;n<=N;n++){
        for (t=0;t<(N-n)*3;t++)        /* 空白 */
            printf(" ");
        for (r=0;r<=n;r++)
            printf("%3ld   ",combi(n,r));
        printf("\n");
    }
	tfin();
}
