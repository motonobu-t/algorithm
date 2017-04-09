// Rei19View.cpp : CRei19View クラスの実装
//

#include "stdafx.h"
#include "Rei19.h"

#include "Rei19Doc.h"
#include "Rei19View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei19View

IMPLEMENT_DYNCREATE(CRei19View, CFormView)

BEGIN_MESSAGE_MAP(CRei19View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei19View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei19View コンストラクション/デストラクション

CRei19View::CRei19View()
	: CFormView(CRei19View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei19View::~CRei19View()
{
}

void CRei19View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei19View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei19View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei19View 診断

#ifdef _DEBUG
void CRei19View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei19View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei19Doc* CRei19View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei19Doc)));
	return (CRei19Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei19View メッセージ ハンドラ
/*
 * ---------------------
 *      基本挿入法     *
 * ---------------------
 */

#include "mfcform.h"

#define N 100     /* データ数 */

void CRei19View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int a[N],i,j,t;

    for(i=0;i<N;i++)       /* Ｎ個の乱数 */
        a[i]=rand();

    for (i=1;i<N;i++){
        for (j=i-1;j>=0;j--){
            if (a[j]>a[j+1]){
                t=a[j]; a[j]=a[j+1]; a[j+1]=t;
            }
            else
                break;
        }
    }

	tinit();cls();
    for (i=0;i<N;i++)
        printf("%8d",a[i]);
    printf("\n");
	tfin();
}
