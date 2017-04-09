// Rei53View.cpp : CRei53View クラスの実装
//

#include "stdafx.h"
#include "Rei53.h"

#include "Rei53Doc.h"
#include "Rei53View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei53View

IMPLEMENT_DYNCREATE(CRei53View, CFormView)

BEGIN_MESSAGE_MAP(CRei53View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei53View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei53View コンストラクション/デストラクション

CRei53View::CRei53View()
	: CFormView(CRei53View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei53View::~CRei53View()
{
}

void CRei53View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei53View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei53View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei53View 診断

#ifdef _DEBUG
void CRei53View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei53View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei53Doc* CRei53View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei53Doc)));
	return (CRei53Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei53View メッセージ ハンドラ
/*
 * -------------------------------
 *      トポロジカル・ソート     *
 * -------------------------------
 */
#include "mfcform.h"

#define N 8                             /* 点の数 */

int a[N+1][N+1]={{0,0,0,0,0,0,0,0,0},   /* 隣接行列 */
                 {0,0,0,1,0,0,0,0,0},
                 {0,1,0,0,0,1,0,0,0},
                 {0,0,0,0,1,0,0,1,0},
                 {0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,1,0,1,0,0},
                 {0,0,0,0,0,0,0,1,1},
                 {0,0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,1,0}};
int v[N+1];                             /* 訪問フラグ */
void visit(int i)
{
    int j;
    v[i]=1;
    for (j=1;j<=N;j++){
        if (a[i][j]==1 && v[j]==0)
            visit(j);
    }
    printf("%d ",i);
}

void CRei53View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i;
	tinit();cls();
    for (i=1;i<=N;i++)
        v[i]=0;
    for (i=1;i<=N;i++)
        if (v[i]==0)
            visit(i);
    printf("\n");
	tfin();
}
