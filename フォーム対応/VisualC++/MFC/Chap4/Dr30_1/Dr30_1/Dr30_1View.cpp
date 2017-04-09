// Dr30_1View.cpp : CDr30_1View クラスの実装
//

#include "stdafx.h"
#include "Dr30_1.h"

#include "Dr30_1Doc.h"
#include "Dr30_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr30_1View

IMPLEMENT_DYNCREATE(CDr30_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr30_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr30_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr30_1View コンストラクション/デストラクション

CDr30_1View::CDr30_1View()
	: CFormView(CDr30_1View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr30_1View::~CDr30_1View()
{
}

void CDr30_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr30_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr30_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr30_1View 診断

#ifdef _DEBUG
void CDr30_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr30_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr30_1Doc* CDr30_1View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr30_1Doc)));
	return (CDr30_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr30_1View メッセージ ハンドラ
/*
 * ---------------------------------------------------
 *      迷路をたどる（経路をスタックに記録する）     *
 * ---------------------------------------------------
 */

#include "mfcform.h"

int m[7][7]={{2,2,2,2,2,2,2},
             {2,0,0,0,0,0,2},
             {2,0,2,0,2,0,2},
             {2,0,0,2,0,2,2},
             {2,2,0,2,0,2,2},
             {2,0,0,0,0,0,2},
             {2,2,2,2,2,2,2}};

int Si,Sj,Ei,Ej,success,
    sp,ri[100],rj[100];         /* 通過位置を入れるスタック */
int visit(int i,int j)
{
    int k;

    m[i][j]=1;
    ri[sp]=i; rj[sp]=j; sp++;       /* 訪問位置をスタックに積む */

    if (i==Ei && j==Ej){            /* 出口に到達したとき */
        for (k=0;k<sp;k++)          /* 通過点の表示 */
            printf("(%d,%d) ",ri[k],rj[k]);
        success=1;
    }
                            /* 出口に到達しない間迷路をさまよう */
    if (success!=1 && m[i][j+1]==0) visit(i,j+1);
    if (success!=1 && m[i+1][j]==0) visit(i+1,j);
    if (success!=1 && m[i][j-1]==0) visit(i,j-1);
    if (success!=1 && m[i-1][j]==0) visit(i-1,j);

    sp--;                            /* スタックから捨てる */
    return success;
}

void CDr30_1View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    sp=0;                       /* スタック・ポインタの初期化 */
    success=0;                  /* 脱出に成功したかを示すフラグ */
    Si=1; Sj=1; Ei=5; Ej=5;     /* 入口と出口の位置 */
	tinit();cls();
    printf("\n迷路の探索\n");
    if (visit(Si,Sj)==0)
        printf("出口は見つかりませんでした\n");
    printf("\n");
	tfin();
}
