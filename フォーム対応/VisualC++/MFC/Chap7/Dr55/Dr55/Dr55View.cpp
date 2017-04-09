// Dr55View.cpp : CDr55View クラスの実装
//

#include "stdafx.h"
#include "Dr55.h"

#include "Dr55Doc.h"
#include "Dr55View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr55View

IMPLEMENT_DYNCREATE(CDr55View, CFormView)

BEGIN_MESSAGE_MAP(CDr55View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr55View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr55View コンストラクション/デストラクション

CDr55View::CDr55View()
	: CFormView(CDr55View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr55View::~CDr55View()
{
}

void CDr55View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr55View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr55View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr55View 診断

#ifdef _DEBUG
void CDr55View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr55View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr55Doc* CDr55View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr55Doc)));
	return (CDr55Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr55View メッセージ ハンドラ
/*
 * -------------------------------
 *      最短路のルートの表示     *
 * -------------------------------
 */

#include "mfcform.h"

#define N 8         /* 節点の数 */
#define M 9999

int a[N+1][N+1]={{0,0,0,0,0,0,0,0,0}, /* 隣接行列 */
                 {0,0,1,7,2,M,M,M,M},
                 {0,1,0,M,M,2,4,M,M},
                 {0,7,M,0,M,M,2,3,M},
                 {0,2,M,M,0,M,M,5,M},
                 {0,M,2,M,M,0,1,M,M},
                 {0,M,4,2,M,1,0,M,6},
                 {0,M,M,3,5,M,M,0,2},
                 {0,M,M,M,M,M,6,2,0}};
void CDr55View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int j,k,p,start,min,
        leng[N+1],              /* 節点までの距離 */
        v[N+1],                 /* 確定フラグ */
        index[N+1];             /* 前の節点へのポインタ */
	tinit();cls();
	CString buf;
	text1.GetWindowText(buf);
	start=stoi(buf);

    for (k=1;k<=N;k++){
        leng[k]=M;v[k]=0;
    }
    leng[start]=0;
    index[start]=0;        /* 始点はどこも示さない */

    for (j=1;j<=N;j++){
        min=M;             /* 最小の節点を捜す */
        for (k=1;k<=N;k++){
            if (v[k]==0 && leng[k]<min){
                p=k; min=leng[k];
            }
        }
        v[p]=1;            /* 最小の節点を確定する */

        if (min==M){
            printf("グラフは連結でない\n");
            exit(1);
        }

        /* ｐを経由してｋに至る長さがそれまでの最短路より小さければ更新 */
        for (k=1;k<=N;k++){
            if((leng[p]+a[p][k])<leng[k]){
                leng[k]=leng[p]+a[p][k];
                index[k]=p;
            }
        }
    }
    for (j=1;j<=N;j++){                  /* 最短路のルートの表示 */
        printf("%3d : %d",leng[j],j);    /* 終端 */
        p=j;
        while (index[p]!=0){
            printf(" <-- %d",index[p]);
            p=index[p];
        }
        printf("\n");
    }
	tfin();
}
