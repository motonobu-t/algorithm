// Dr18_1View.cpp : CDr18_1View クラスの実装
//

#include "stdafx.h"
#include "Dr18_1.h"

#include "Dr18_1Doc.h"
#include "Dr18_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr18_1View

IMPLEMENT_DYNCREATE(CDr18_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr18_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr18_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr18_1View コンストラクション/デストラクション

CDr18_1View::CDr18_1View()
	: CFormView(CDr18_1View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr18_1View::~CDr18_1View()
{
}

void CDr18_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr18_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr18_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr18_1View 診断

#ifdef _DEBUG
void CDr18_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr18_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr18_1Doc* CDr18_1View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr18_1Doc)));
	return (CDr18_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr18_1View メッセージ ハンドラ
/*
 * -----------------------------
 *        バブル・ソート       *
 * -----------------------------
 */

#include "mfcform.h"

#define N 6

void CDr18_1View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int a[]={80,41,35,90,40,20};
    int t,i,j;

    for (i=0;i<N-1;i++){
        for (j=N-1;j>i;j--){
            if (a[j]<a[j-1]){
                t=a[j];    a[j]=a[j-1]; a[j-1]=t;
            }
        }
    }

	tinit();cls();
    for (i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");
	tfin();
}
