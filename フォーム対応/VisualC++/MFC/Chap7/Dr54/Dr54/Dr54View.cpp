// Dr54View.cpp : CDr54View クラスの実装
//

#include "stdafx.h"
#include "Dr54.h"

#include "Dr54Doc.h"
#include "Dr54View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr54View

IMPLEMENT_DYNCREATE(CDr54View, CFormView)

BEGIN_MESSAGE_MAP(CDr54View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr54View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr54View コンストラクション/デストラクション

CDr54View::CDr54View()
	: CFormView(CDr54View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr54View::~CDr54View()
{
}

void CDr54View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr54View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr54View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr54View 診断

#ifdef _DEBUG
void CDr54View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr54View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr54Doc* CDr54View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr54Doc)));
	return (CDr54Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr54View メッセージ ハンドラ
/*
 * -----------------------------------------------
 *      Ｅｕｌｅｒの一筆書き（有向グラフ版）     *
 * -----------------------------------------------
 */

#include "mfcform.h"

#define Node 4        /* 節点の数 */
#define Root 6        /* 辺の数 */
#define Start 1       /* 開始点 */

int a[Node+1][Node+1]={{0,0,0,0,0},
                       {0,0,1,0,0},
                       {0,0,0,1,1},
                       {0,0,0,0,1},
                       {0,1,1,0,0}};
int success,
    v[Root+1],      /* 経路を入れるスタック */
    n;              /* 通過した道の数 */
void visit(int i)
{
    int j;
    v[n]=i;
    if (n==0 && i==Start){     /* 辺の数だけ通過し元に戻ったら */
        printf("解 %d:",++success);
        for (i=0;i<=Root;i++)
            printf("%d",v[i]);
        printf("\n");
    }
    else {
        for (j=1;j<=Node;j++)
            if (a[i][j]!=0){
                a[i][j]--;     /* 通つた道を切り離す */
                n--;
                visit(j);
                a[i][j]++;     /* 道を復旧する */
                n++;
            }
    }
}

void CDr54View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	tinit();cls(); 
	success=0; n=Root;
    visit(Start);
    if (success==0)
        printf("解なし\n");
	tfin();
}
