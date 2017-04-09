// Dr20_3View.cpp : CDr20_3View クラスの実装
//

#include "stdafx.h"
#include "Dr20_3.h"

#include "Dr20_3Doc.h"
#include "Dr20_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr20_3View

IMPLEMENT_DYNCREATE(CDr20_3View, CFormView)

BEGIN_MESSAGE_MAP(CDr20_3View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr20_3View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr20_3View コンストラクション/デストラクション

CDr20_3View::CDr20_3View()
	: CFormView(CDr20_3View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr20_3View::~CDr20_3View()
{
}

void CDr20_3View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr20_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr20_3View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr20_3View 診断

#ifdef _DEBUG
void CDr20_3View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr20_3View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr20_3Doc* CDr20_3View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr20_3Doc)));
	return (CDr20_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr20_3View メッセージ ハンドラ
/*
 * ---------------------
 *      基本挿入法     *
 * ---------------------
 */

#include "mfcform.h"

#define N 100   /* データ数 */
void CDr20_3View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int a[N+1],i,j,t;

    for(i=1;i<=N;i++)        /* Ｎ個の乱数 */
        a[i]=rand();

    a[0]=-9999;              /* 番兵 */
    for (i=2;i<=N;i++){
        t=a[i];
        for (j=i-1;a[j]>t;j--)
            a[j+1]=a[j];
        a[j+1]=t;
    }

	tinit();cls();
    for (i=1;i<=N;i++)
        printf("%8d",a[i]);
    printf("\n");
	tfin();
}
