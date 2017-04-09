// Rei51View.cpp : CRei51View クラスの実装
//

#include "stdafx.h"
#include "Rei51.h"

#include "Rei51Doc.h"
#include "Rei51View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei51View

IMPLEMENT_DYNCREATE(CRei51View, CFormView)

BEGIN_MESSAGE_MAP(CRei51View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei51View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei51View コンストラクション/デストラクション

CRei51View::CRei51View()
	: CFormView(CRei51View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei51View::~CRei51View()
{
}

void CRei51View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei51View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei51View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei51View 診断

#ifdef _DEBUG
void CRei51View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei51View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei51Doc* CRei51View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei51Doc)));
	return (CRei51Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei51View メッセージ ハンドラ
/*
 * -----------------------------------
 *      グラフの探索（深さ優先）     *
 * -----------------------------------
 */
#include "mfcform.h"

#define N 8                             /* 点の数 */

int a[N+1][N+1]={{0,0,0,0,0,0,0,0,0},   /* 隣接行列 */
                 {0,0,1,0,0,0,0,0,0},
                 {0,1,0,1,1,0,0,0,0},
                 {0,0,1,0,0,0,0,1,0},
                 {0,0,1,0,0,1,0,0,0},
                 {0,0,0,0,1,0,1,0,0},
                 {0,0,0,0,0,1,0,1,1},
                 {0,0,0,1,0,0,1,0,1},
                 {0,0,0,0,0,0,1,1,0}};
int v[N+1];                             /* 訪問フラグ */
void visit(int i)
{
    int j;

    v[i]=1;
    for (j=1;j<=N;j++){
        if (a[i][j]==1 && v[j]==0){
            printf("%d->%d ",i,j);
            visit(j);
        }
    }
}

void CRei51View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i;
	tinit();cls();
    for (i=1;i<=N;i++)
        v[i]=0;
    visit(1);
    printf("\n");
	tfin();
}
