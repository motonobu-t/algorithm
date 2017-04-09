// Rei31View.cpp : CRei31View クラスの実装
//

#include "stdafx.h"
#include "Rei31.h"

#include "Rei31Doc.h"
#include "Rei31View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei31View

IMPLEMENT_DYNCREATE(CRei31View, CFormView)

BEGIN_MESSAGE_MAP(CRei31View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei31View::OnBnClickedButton1)
//	ON_STN_CLICKED(IDC_PICT, &CRei31View::OnStnClickedPict)
END_MESSAGE_MAP()

// CRei31View コンストラクション/デストラクション

CRei31View::CRei31View()
	: CFormView(CRei31View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei31View::~CRei31View()
{
}

void CRei31View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei31View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei31View 診断

#ifdef _DEBUG
void CRei31View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei31View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei31Doc* CRei31View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei31Doc)));
	return (CRei31Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei31View メッセージ ハンドラ
/*
 * ---------------------------
 *      クイック・ソート     *
 * ---------------------------
 */

#include "mfcform.h"

#define N 10
void quick(int a[],int left,int right)
{
    int s,t,i,j;

    if (left<right){
        s=a[left];              /* 左端の項を軸にする */
        i=left; j=right+1;      /* 軸より小さいグループと       */
        while (1){              /*       大きいグループに分ける */
            while (a[++i]<s);
            while (a[--j]>s);
            if (i>=j) break;
            t=a[i]; a[i]=a[j]; a[j]=t;
        }
        a[left]=a[j]; a[j]=s;   /* 軸を正しい位置に入れる */

        quick(a,left,j-1);      /* 左部分列に対する再帰呼び出し */
        quick(a,j+1,right);     /* 右部分列に対する再帰呼び出し */
    }
}

void CRei31View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    static int a[]={41,24,76,11,45,64,21,69,19,36};
    int k;

    quick(a,0,N-1);
	tinit();cls();
    for (k=0;k<N;k++)
        printf("%4d",a[k]);
    printf("\n");
	tfin();
}
