// Dr51_2View.cpp : CDr51_2View クラスの実装
//

#include "stdafx.h"
#include "Dr51_2.h"

#include "Dr51_2Doc.h"
#include "Dr51_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr51_2View

IMPLEMENT_DYNCREATE(CDr51_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr51_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr51_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr51_2View コンストラクション/デストラクション

CDr51_2View::CDr51_2View()
	: CFormView(CDr51_2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr51_2View::~CDr51_2View()
{
}

void CDr51_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr51_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr51_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr51_2View 診断

#ifdef _DEBUG
void CDr51_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr51_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr51_2Doc* CDr51_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr51_2Doc)));
	return (CDr51_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr51_2View メッセージ ハンドラ
/*
 * -----------------------------------------
 *      非連結グラフの探索（深さ優先）     *
 * -----------------------------------------
 */
#include "mfcform.h"

#define N 8                            /* 点の数 */

int a[N+1][N+1]={{0,0,0,0,0,0,0,0,0},  /* 隣接行列 */
                 {0,0,1,1,0,0,0,0,0},
                 {0,1,0,1,1,0,0,0,0},
                 {0,1,1,0,0,1,0,0,0},
                 {0,0,1,0,0,1,0,0,0},
                 {0,0,0,1,1,0,0,0,0},
                 {0,0,0,0,0,0,0,1,1},
                 {0,0,0,0,0,0,1,0,1},
                 {0,0,0,0,0,0,1,1,0}};
int v[N+1];                            /* 訪問フラグ */
void visit(int i)
{
    int j;

    printf("%d ",i);
    v[i]=1;
    for (j=1;j<=N;j++){
        if (a[i][j]==1 && v[j]==0)
            visit(j);
    }
}

void CDr51_2View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i,count=1;    /* 連結成分のカウント用 */
	tinit();cls();
    for (i=1;i<=N;i++)
        v[i]=0;
    for (i=1;i<=N;i++){
        if (v[i]!=1){
            printf("%d :",count++);
            visit(i);
            printf("\n");
        }
    }
	tfin();
}
