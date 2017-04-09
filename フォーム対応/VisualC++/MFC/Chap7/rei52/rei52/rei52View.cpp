// rei52View.cpp : Crei52View クラスの実装
//

#include "stdafx.h"
#include "rei52.h"

#include "rei52Doc.h"
#include "rei52View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Crei52View

IMPLEMENT_DYNCREATE(Crei52View, CFormView)

BEGIN_MESSAGE_MAP(Crei52View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &Crei52View::OnBnClickedButton1)
END_MESSAGE_MAP()

// Crei52View コンストラクション/デストラクション

Crei52View::Crei52View()
	: CFormView(Crei52View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

Crei52View::~Crei52View()
{
}

void Crei52View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL Crei52View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void Crei52View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// Crei52View 診断

#ifdef _DEBUG
void Crei52View::AssertValid() const
{
	CFormView::AssertValid();
}

void Crei52View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Crei52Doc* Crei52View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Crei52Doc)));
	return (Crei52Doc*)m_pDocument;
}
#endif //_DEBUG


// Crei52View メッセージ ハンドラ
/*
 * ---------------------------------
 *      グラフの探索（幅優先）     *
 * ---------------------------------
 */

#include "mfcform.h"

#define N 8                                 /* 点の数 */

int a[N+1][N+1]={{0,0,0,0,0,0,0,0,0},       /* 隣接行列 */
                 {0,0,1,0,0,0,0,0,0},
                 {0,1,0,1,1,1,0,0,0},
                 {0,0,1,0,0,0,0,1,0},
                 {0,0,1,0,0,0,0,0,0},
                 {0,0,1,0,0,0,1,0,0},
                 {0,0,0,0,0,1,0,1,1},
                 {0,0,0,1,0,0,1,0,1},
                 {0,0,0,0,0,0,1,1,0}};
int v[N+1];                                 /* 訪問フラグ */

int queue[100];             /* キュー */
int head=0,                 /* 先頭データのインデックス */
    tail=0;                 /* 終端データのインデックス */

void Crei52View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i,j;
	tinit();cls();
    for (i=1;i<=N;i++)
        v[i]=0;

    queue[tail++]=1;v[1]=1;
    do {
        i=queue[head++];            /* キューから取り出す */
        for (j=1;j<=N;j++){
            if (a[i][j]==1 && v[j]==0){
                printf("%d->%d ",i,j);
                queue[tail++]=j;    /* キューに入れる */
                v[j]=1;
            }
        }
    } while (head!=tail);
    printf("\n");
	tfin();
}
