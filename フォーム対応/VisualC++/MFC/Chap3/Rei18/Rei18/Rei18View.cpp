// Rei18View.cpp : CRei18View クラスの実装
//

#include "stdafx.h"
#include "Rei18.h"

#include "Rei18Doc.h"
#include "Rei18View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei18View

IMPLEMENT_DYNCREATE(CRei18View, CFormView)

BEGIN_MESSAGE_MAP(CRei18View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei18View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei18View コンストラクション/デストラクション

CRei18View::CRei18View()
	: CFormView(CRei18View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei18View::~CRei18View()
{
}

void CRei18View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei18View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei18View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei18View 診断

#ifdef _DEBUG
void CRei18View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei18View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei18Doc* CRei18View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei18Doc)));
	return (CRei18Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei18View メッセージ ハンドラ
/*
 * ---------------------------------
 *      直接選択法によるソート     *
 * ---------------------------------
 */

#include "mfcform.h"

#define N 6

void CRei18View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int a[]={80,41,35,90,40,20};
    int min,s,t,i,j;

    for (i=0;i<N-1;i++){
        min=a[i];
        s=i;
        for (j=i+1;j<N;j++){
            if (a[j]<min){
                min=a[j];
                s=j;
            }
        }
        t=a[i]; a[i]=a[s]; a[s]=t;
    }

	tinit();cls();
    for (i=0;i<N;i++)
        printf("%d ",a[i]);
    printf("\n");
	tfin();
}
