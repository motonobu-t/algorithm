// Dr30_2View.cpp : CDr30_2View クラスの実装
//

#include "stdafx.h"
#include "Dr30_2.h"

#include "Dr30_2Doc.h"
#include "Dr30_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr30_2View

IMPLEMENT_DYNCREATE(CDr30_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr30_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr30_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr30_2View コンストラクション/デストラクション

CDr30_2View::CDr30_2View()
	: CFormView(CDr30_2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr30_2View::~CDr30_2View()
{
}

void CDr30_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr30_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr30_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr30_2View 診断

#ifdef _DEBUG
void CDr30_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr30_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr30_2Doc* CDr30_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr30_2Doc)));
	return (CDr30_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr30_2View メッセージ ハンドラ
/*
 * -------------------------------
 *      すべての迷路をたどる     *
 * -------------------------------
 */

#include "mfcform.h"

int m[9][9]={{2,2,2,2,2,2,2,2,2},
             {2,0,0,0,0,0,0,0,2},
             {2,0,2,2,0,2,2,0,2},
             {2,0,2,0,0,2,0,0,2},
             {2,0,2,0,2,0,2,0,2},
             {2,0,0,0,0,0,2,0,2},
             {2,2,0,2,2,0,2,2,2},
             {2,0,0,0,0,0,0,0,2},
             {2,2,2,2,2,2,2,2,2}};

int Si,Sj,Ei,Ej,success,
    sp,ri[100],rj[100];         /* 通過位置を入れるスタック */
int visit(int i,int j)
{
    int k;
    static int path=1;

    m[i][j]=1;
    ri[sp]=i; rj[sp]=j; sp++;   /* 訪問位置をスタックに積む */

    if (i==Ei && j==Ej){        /* 出口に到達したとき */
		printf("\n");    // printf("\n・・・)は単独の改行に変更
        printf("path=%d\n",path++);     /* 通過点の表示 */
        for (k=0;k<sp;k++)
            printf("(%d,%d) ",ri[k],rj[k]);
        success=1;
    }
                                /* 迷路をさまよう */
    if (m[i][j+1]==0) visit(i,j+1);
    if (m[i+1][j]==0) visit(i+1,j);
    if (m[i][j-1]==0) visit(i,j-1);
    if (m[i-1][j]==0) visit(i-1,j);

    sp--;                       /* スタックから捨てる */
    m[i][j]=0;                  /* 別な経路の探索のため */

    return success;
}

void CDr30_2View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    sp=0;                       /* スタック・ポインタの初期化 */
    success=0;                  /* 脱出に成功したかを示すフラグ */
    Si=1; Sj=1; Ei=7; Ej=7;     /* 入口と出口の位置 */
	tinit();cls();
    printf("\n迷路の探索");
    if (visit(Si,Sj)==0)
        printf("出口は見つかりませんでした\n");
    printf("\n");
	tfin();
}
