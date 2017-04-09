// Dr19_1View.cpp : CDr19_1View クラスの実装
//

#include "stdafx.h"
#include "Dr19_1.h"

#include "Dr19_1Doc.h"
#include "Dr19_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr19_1View

IMPLEMENT_DYNCREATE(CDr19_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr19_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr19_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr19_1View コンストラクション/デストラクション

CDr19_1View::CDr19_1View()
	: CFormView(CDr19_1View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr19_1View::~CDr19_1View()
{
}

void CDr19_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr19_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr19_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr19_1View 診断

#ifdef _DEBUG
void CDr19_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr19_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr19_1Doc* CDr19_1View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr19_1Doc)));
	return (CDr19_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr19_1View メッセージ ハンドラ
/*
 * ----------------------------------------
 *      シェル・ソート（改良挿入法 ）     *
 * ----------------------------------------
 */

#include "mfcform.h"

#define N 100   /* データ数 */
void CDr19_1View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int a[N],i,j,k,gap,t;

    for(i=0;i<N;i++)        /* Ｎ個の乱数 */
        a[i]=rand();

    gap=N/2;                /* ギャップの初期値 */
    while (gap>0){
        for (k=0;k<gap;k++){    /* ギャプとびの部分数列のソート */
            for (i=k+gap;i<N;i=i+gap){
                for (j=i-gap;j>=k;j=j-gap){
                    if (a[j]>a[j+gap]){
                        t=a[j]; a[j]=a[j+gap]; a[j+gap]=t;
                    }
                    else
                        break;
                }
            }
        }
        gap=gap/2;             /* ギャップを半分にする */
    }

	tinit();cls();
    for (i=0;i<N;i++)
        printf("%8d",a[i]);
    printf("\n");
	tfin();
}
