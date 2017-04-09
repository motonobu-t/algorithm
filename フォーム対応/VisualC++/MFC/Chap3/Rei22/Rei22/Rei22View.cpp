// Rei22View.cpp : CRei22View クラスの実装
//

#include "stdafx.h"
#include "Rei22.h"

#include "Rei22Doc.h"
#include "Rei22View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei22View

IMPLEMENT_DYNCREATE(CRei22View, CFormView)

BEGIN_MESSAGE_MAP(CRei22View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei22View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei22View コンストラクション/デストラクション

CRei22View::CRei22View()
	: CFormView(CRei22View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei22View::~CRei22View()
{
}

void CRei22View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei22View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei22View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei22View 診断

#ifdef _DEBUG
void CRei22View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei22View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei22Doc* CRei22View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei22Doc)));
	return (CRei22Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei22View メッセージ ハンドラ
/*
 * --------------------------
 *      マージ （併合）     *
 * --------------------------
 */

#include "mfcform.h"

#define M 10
#define N 5
void CRei22View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int a[]={2,4,5,7,8,10,15,20,30,40},
        b[]={6,11,25,33,35},
        c[M+N];
    int i,j,p;

    i=j=p=0;
    while (i<M && j<N){        /* a[],b[]とも終わりでない間 */
        if (a[i]<=b[j])
            c[p++]=a[i++];
        else
            c[p++]=b[j++];
    }
    while (i<M)                /* a[]が終わりになるまで */
        c[p++]=a[i++];
    while (j<N)                /* b[]が終わりになるまで */
        c[p++]=b[j++];

	tinit();cls();
    for (i=0;i<M+N;i++)
        printf("%d ",c[i]);
    printf("\n");
	tfin();
}
