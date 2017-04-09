// Rei28View.cpp : CRei28View クラスの実装
//

#include "stdafx.h"
#include "Rei28.h"

#include "Rei28Doc.h"
#include "Rei28View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei28View

IMPLEMENT_DYNCREATE(CRei28View, CFormView)

BEGIN_MESSAGE_MAP(CRei28View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei28View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei28View コンストラクション/デストラクション

CRei28View::CRei28View()
	: CFormView(CRei28View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei28View::~CRei28View()
{
}

void CRei28View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei28View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei28View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei28View 診断

#ifdef _DEBUG
void CRei28View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei28View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei28Doc* CRei28View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei28Doc)));
	return (CRei28Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei28View メッセージ ハンドラ
/*
 * -------------------------------------
 *      順列生成（辞書式順でない）     *
 * -------------------------------------
 */

#include "mfcform.h"

#define N 4
int p[N+1];
void perm(int i)
{
    int j,t;

    if (i<N){
        for (j=i;j<=N;j++){
            t=p[i]; p[i]=p[j]; p[j]=t;    /* p[i]とp[j]の交換 */
            perm(i+1);                    /* 再帰呼び出し */
            t=p[i]; p[i]=p[j]; p[j]=t;    /* 元に戻す */
        }
    }
    else {
        for (j=1;j<=N;j++)                /* 順列の表示 */
            printf("%d ",p[j]);
        printf("\n");
    }
}

void CRei28View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i;

    for (i=1;i<=N;i++)        /* 初期設定 */
        p[i]=i;
	tinit();cls();  // 再帰呼び出しの前後でtinit()とtfin()を入れる
    perm(1);
	tfin();
}
