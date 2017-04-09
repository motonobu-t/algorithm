// Dr53View.cpp : CDr53View クラスの実装
//

#include "stdafx.h"
#include "Dr53.h"

#include "Dr53Doc.h"
#include "Dr53View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr53View

IMPLEMENT_DYNCREATE(CDr53View, CFormView)

BEGIN_MESSAGE_MAP(CDr53View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr53View::OnBnClickedButton1)
//	ON_STN_CLICKED(IDC_PICT, &CDr53View::OnStnClickedPict)
END_MESSAGE_MAP()

// CDr53View コンストラクション/デストラクション

CDr53View::CDr53View()
	: CFormView(CDr53View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr53View::~CDr53View()
{
}

void CDr53View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr53View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr53View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr53View 診断

#ifdef _DEBUG
void CDr53View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr53View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr53Doc* CDr53View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr53Doc)));
	return (CDr53Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr53View メッセージ ハンドラ
/*
 * ---------------------------------------------------
 *      トポロジカル・ソート（閉路の判定を含む）     *
 * ---------------------------------------------------
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
int v[N+1],                             /* 訪問フラグ */
    s[N+1];                             /* ソート結果格納用 */
void visit(int i)
{
    int j;
    static int sp=1;    /* スタック・ポインタ */
    v[i]=1;
    for (j=1;j<=N;j++){
        if (a[i][j]==1 && v[j]==0)
            visit(j);
        if (a[i][j]==1 && v[j]==1){
            printf("%d と %d の付近にループがあります\n",i,j);
            exit(1);
        }
    }
    v[i]=2;             /* 閉路の判定のため */
    s[sp++]=i;          /* スタックに格納   */
}

void CDr53View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i;
	tinit();cls();
    for (i=1;i<=N;i++)
        v[i]=0;
    for (i=1;i<=N;i++)
        if (v[i]==0)
            visit(i);
    for (i=N;i>=1;i--)
        printf("%d ",s[i]);
    printf("\n");
	tfin();
}

