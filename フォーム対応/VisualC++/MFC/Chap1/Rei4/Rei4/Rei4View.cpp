// Rei4View.cpp : CRei4View クラスの実装
//

#include "stdafx.h"
#include "Rei4.h"

#include "Rei4Doc.h"
#include "Rei4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei4View

IMPLEMENT_DYNCREATE(CRei4View, CFormView)

BEGIN_MESSAGE_MAP(CRei4View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei4View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei4View コンストラクション/デストラクション

CRei4View::CRei4View()
	: CFormView(CRei4View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei4View::~CRei4View()
{
}

void CRei4View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei4View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei4View 診断

#ifdef _DEBUG
void CRei4View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei4View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei4Doc* CRei4View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei4Doc)));
	return (CRei4Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei4View メッセージ ハンドラ
/*
 * ---------------------------------------
 *    ランダムな順列（効率の悪い方法）   *
 * ---------------------------------------
 */

#include "mfcform.h"

#define N 20

int irnd(int n)        /* １～ｎの乱数 */
{
    return (int)(rand()/(RAND_MAX+0.1)*n+1);
}

void CRei4View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i,j,flag,a[N+1];

    a[1]=irnd(N);
    for (i=2;i<=N;i++){
        do {
            a[i]=irnd(N);flag=0;
            for (j=1;j<i;j++)
                if (a[i]==a[j]){
                    flag=1;break;
                }
        } while (flag==1);
    }

	tinit();cls();
    for (i=1;i<=N;i++)
        printf("%d ",a[i]);
    printf("\n");
	tfin();
}
