// Dr28_1View.cpp : CDr28_1View クラスの実装
//

#include "stdafx.h"
#include "Dr28_1.h"

#include "Dr28_1Doc.h"
#include "Dr28_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr28_1View

IMPLEMENT_DYNCREATE(CDr28_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr28_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr28_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr28_1View コンストラクション/デストラクション

CDr28_1View::CDr28_1View()
	: CFormView(CDr28_1View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr28_1View::~CDr28_1View()
{
}

void CDr28_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr28_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr28_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr28_1View 診断

#ifdef _DEBUG
void CDr28_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr28_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr28_1Doc* CDr28_1View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr28_1Doc)));
	return (CDr28_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr28_1View メッセージ ハンドラ
/*
 * -------------------------------
 *      順列生成（辞書式順）     *
 * -------------------------------
 */

#include "mfcform.h"

#define N 4
int p[N+1];
void perm(int i)
{
    int j,k,t;

    if (i<N){
        for (j=i;j<=N;j++){
            t=p[j];                  /* p[i]～p[j]の右ローテイト */
            for (k=j;k>i;k--)
                p[k]=p[k-1];
            p[i]=t;

            perm(i+1);               /* 再帰呼び出し */

            for (k=i;k<j;k++)        /* 配列の並びを再帰呼び出し前に戻す */
                p[k]=p[k+1];
            p[j]=t;
        }
    }
    else {
        for (j=1;j<=N;j++)           /* 順列の表示 */
            printf("%d ",p[j]);
        printf("\n");
    }
}

void CDr28_1View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i;

    for (i=1;i<=N;i++)        /* 初期設定 */
        p[i]=i;
	tinit();cls();
    perm(1);
	tfin();
}
