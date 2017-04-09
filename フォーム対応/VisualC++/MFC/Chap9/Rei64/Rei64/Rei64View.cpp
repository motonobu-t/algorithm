// Rei64View.cpp : CRei64View クラスの実装
//

#include "stdafx.h"
#include "Rei64.h"

#include "Rei64Doc.h"
#include "Rei64View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei64View

IMPLEMENT_DYNCREATE(CRei64View, CFormView)

BEGIN_MESSAGE_MAP(CRei64View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei64View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei64View コンストラクション/デストラクション

CRei64View::CRei64View()
	: CFormView(CRei64View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei64View::~CRei64View()
{
}

void CRei64View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei64View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei64View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei64View 診断

#ifdef _DEBUG
void CRei64View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei64View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei64Doc* CRei64View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei64Doc)));
	return (CRei64Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei64View メッセージ ハンドラ
/*
 * ---------------------
 *      奇数魔方陣     *
 * ---------------------
 */
#include "mfcform.h"

#define N 7     /* ｎ方陣(n=3,5,7,9,･･･) */

void CRei64View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int hojin[N+1][N+1],i,j,k;
	tinit();cls();
    j=(N+1)/2; i=0;
    for (k=1;k<=N*N;k++){
        if ((k%N)==1)
            i++;
        else {
            i--; j++;
        }
        if (i==0)
            i=N;
        if (j>N)
            j=1;
        hojin[i][j]=k;
    }

    printf("        奇数魔方陣 (N=%d)\n",N);
    for (i=1;i<=N;i++){
        for (j=1;j<=N;j++)
            printf("%4d",hojin[i][j]);
        printf("\n");
    }
	tfin();
}
