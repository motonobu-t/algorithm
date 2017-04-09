// rei54View.cpp : Crei54View クラスの実装
//

#include "stdafx.h"
#include "rei54.h"

#include "rei54Doc.h"
#include "rei54View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Crei54View

IMPLEMENT_DYNCREATE(Crei54View, CFormView)

BEGIN_MESSAGE_MAP(Crei54View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &Crei54View::OnBnClickedButton1)
END_MESSAGE_MAP()

// Crei54View コンストラクション/デストラクション

Crei54View::Crei54View()
	: CFormView(Crei54View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

Crei54View::~Crei54View()
{
}

void Crei54View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL Crei54View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void Crei54View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// Crei54View 診断

#ifdef _DEBUG
void Crei54View::AssertValid() const
{
	CFormView::AssertValid();
}

void Crei54View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

Crei54Doc* Crei54View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Crei54Doc)));
	return (Crei54Doc*)m_pDocument;
}
#endif //_DEBUG


// Crei54View メッセージ ハンドラ
/*
 * -------------------------------
 *      Ｅｕｌｅｒの一筆書き     *
 * -------------------------------
 */

#include "mfcform.h"

#define Node 4        /* 節点の数 */
#define Root 6        /* 辺の数 */
#define Start 1       /* 開始点 */

int a[Node+1][Node+1]={{0,0,0,0,0},
                       {0,0,1,0,1},
                       {0,1,0,1,2},
                       {0,0,1,0,1},
                       {0,1,2,1,0}};
int success,
    v[Root+1],      /* 経路を入れるスタック */
    n;              /* 通過した道の数 */
void visit(int i)
{
    int j;
    v[n]=i;
    if (n==0 && i==Start){    /* 辺の数だけ通過し元に戻ったら */
        printf("解 %d:",++success);
        for (i=0;i<=Root;i++)
            printf("%d",v[i]);
        printf("\n");
    }
    else {
        for (j=1;j<=Node;j++)
            if (a[i][j]!=0){
                a[i][j]--; a[j][i]--;    /* 通つた道を切り離す */
                n--;
                visit(j);
                a[i][j]++; a[j][i]++;    /* 道を復旧する */
                n++;
            }
    }
}

void Crei54View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	tinit();cls();
	success=0; n=Root;
    visit(Start);
    if (success==0)
        printf("解なし\n");
	tfin();
}
