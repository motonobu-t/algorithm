// Dr52View.cpp : CDr52View クラスの実装
//

#include "stdafx.h"
#include "Dr52.h"

#include "Dr52Doc.h"
#include "Dr52View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr52View

IMPLEMENT_DYNCREATE(CDr52View, CFormView)

BEGIN_MESSAGE_MAP(CDr52View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr52View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr52View コンストラクション/デストラクション

CDr52View::CDr52View()
	: CFormView(CDr52View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr52View::~CDr52View()
{
}

void CDr52View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr52View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr52View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr52View 診断

#ifdef _DEBUG
void CDr52View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr52View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr52Doc* CDr52View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr52Doc)));
	return (CDr52Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr52View メッセージ ハンドラ
/*
 * ---------------------------------
 *      グラフの探索（幅優先）     *
 * ---------------------------------
 */

#include "mfcform.h"

#define N 8                                 /* 点の数 */

int a[N+1][N+1]={{0,0,0,0,0,0,0,0,0},   /* 隣接行列 */
                 {0,0,1,0,0,0,0,0,0},
                 {0,1,0,1,1,1,0,0,0},
                 {0,0,1,0,0,0,0,1,0},
                 {0,0,1,0,0,0,0,0,0},
                 {0,0,1,0,0,0,1,0,0},
                 {0,0,0,0,0,1,0,1,1},
                 {0,0,0,1,0,0,1,0,1},
                 {0,0,0,0,0,0,1,1,0}};
int v[N+1];                             /* 訪問フラグ */

int queue[100];             /* キュー */
int head,                   /* 先頭データのインデックス */
    tail;                   /* 終端データのインデックス */


void CDr52View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i,j,p;
	tinit();cls();
    for (p=1;p<=N;p++){
        for (i=1;i<=N;i++)
            v[i]=0;
        head=tail=0;
        queue[tail++]=p;v[p]=1;
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
    }
	tfin();
}
