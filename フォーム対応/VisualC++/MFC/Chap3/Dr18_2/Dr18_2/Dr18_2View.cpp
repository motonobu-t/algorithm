// Dr18_2View.cpp : CDr18_2View クラスの実装
//

#include "stdafx.h"
#include "Dr18_2.h"

#include "Dr18_2Doc.h"
#include "Dr18_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr18_2View

IMPLEMENT_DYNCREATE(CDr18_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr18_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr18_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr18_2View コンストラクション/デストラクション

CDr18_2View::CDr18_2View()
	: CFormView(CDr18_2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr18_2View::~CDr18_2View()
{
}

void CDr18_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr18_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr18_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr18_2View 診断

#ifdef _DEBUG
void CDr18_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr18_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr18_2Doc* CDr18_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr18_2Doc)));
	return (CDr18_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr18_2View メッセージ ハンドラ
/*
 * -----------------------------
 *      シェーカー・ソート     *
 * -----------------------------
 */

#include "mfcform.h"

#define N 9
void CDr18_2View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int a[]={3,5,6,9,2,7,8,10,4};
    int left,right,i,shift,t;

    left=0;right=N-1;
    while (left<right){
        for (i=left;i<right;i++){
            if (a[i]>a[i+1]){
                t=a[i];a[i]=a[i+1];a[i+1]=t;
                shift=i;
            }
        }
        right=shift;
        for (i=right;i>left;i--){
            if (a[i]<a[i-1]){
                t=a[i];a[i]=a[i-1];a[i-1]=t;
                shift=i;
            }
        }
        left=shift;
    }

	tinit();cls();
	for (i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");
	tfin();
}
