// Dr31View.cpp : CDr31View クラスの実装
//

#include "stdafx.h"
#include "Dr31.h"

#include "Dr31Doc.h"
#include "Dr31View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr31View

IMPLEMENT_DYNCREATE(CDr31View, CFormView)

BEGIN_MESSAGE_MAP(CDr31View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr31View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr31View コンストラクション/デストラクション

CDr31View::CDr31View()
	: CFormView(CDr31View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr31View::~CDr31View()
{
}

void CDr31View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr31View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr31View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr31View 診断

#ifdef _DEBUG
void CDr31View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr31View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr31Doc* CDr31View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr31Doc)));
	return (CDr31Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr31View メッセージ ハンドラ
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
        s=a[(left+right)/2];    /* 中央の値を軸にする */
        i=left-1; j=right+1;    /* 軸より小さいグループと       */
        while (1){              /*       大きいグループに分ける */
            while (a[++i]<s);
            while (a[--j]>s);
            if (i>=j) break;
            t=a[i]; a[i]=a[j]; a[j]=t;
        }

        quick(a,left,i-1);        /* 左部分列に対する再帰呼び出し */
        quick(a,j+1,right);       /* 右部分列に対する再帰呼び出し */
    }
}

void CDr31View::OnBnClickedButton1()
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
