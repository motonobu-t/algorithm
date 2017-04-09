// Dr19_2View.cpp : CDr19_2View クラスの実装
//

#include "stdafx.h"
#include "Dr19_2.h"

#include "Dr19_2Doc.h"
#include "Dr19_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr19_2View

IMPLEMENT_DYNCREATE(CDr19_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr19_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr19_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr19_2View コンストラクション/デストラクション

CDr19_2View::CDr19_2View()
	: CFormView(CDr19_2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr19_2View::~CDr19_2View()
{
}

void CDr19_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr19_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr19_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr19_2View 診断

#ifdef _DEBUG
void CDr19_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr19_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr19_2Doc* CDr19_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr19_2Doc)));
	return (CDr19_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr19_2View メッセージ ハンドラ
/*
 * ----------------------------------------
 *      シェル・ソート（改良挿入法 ）     *
 * ----------------------------------------
 */

#include "mfcform.h"

#define N 100   /* データ数 */
void CDr19_2View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int a[N],i,j,gap,t;

    for(i=0;i<N;i++)        /* Ｎ個の乱数 */
        a[i]=rand();
                            /* Ｎより小さい範囲で最大のｇａｐを決める */
    for (gap=1;gap<N/3;gap=3*gap+1)
        ;

    while (gap>0){
        for (i=gap;i<N;i++){
            for (j=i-gap;j>=0;j=j-gap){
                if (a[j]>a[j+gap]){
                    t=a[j]; a[j]=a[j+gap]; a[j+gap]=t;
                }
                else
                    break;
            }
        }
        gap=gap/3;             /* ギャップを１／３にする */
    }

	tinit();cls();
    for (i=0;i<N;i++)
        printf("%8d",a[i]);
    printf("\n");
	tfin();
}
