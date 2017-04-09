// Dr48_2View.cpp : CDr48_2View クラスの実装
//

#include "stdafx.h"
#include "Dr48_2.h"

#include "Dr48_2Doc.h"
#include "Dr48_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr48_2View

IMPLEMENT_DYNCREATE(CDr48_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr48_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr48_2View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr48_2View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CDr48_2View コンストラクション/デストラクション

CDr48_2View::CDr48_2View()
	: CFormView(CDr48_2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr48_2View::~CDr48_2View()
{
}

void CDr48_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr48_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr48_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr48_2View 診断

#ifdef _DEBUG
void CDr48_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr48_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr48_2Doc* CDr48_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr48_2Doc)));
	return (CDr48_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr48_2View メッセージ ハンドラ
/*
 * -------------------------
 *      ヒープ・ソート     *
 * -------------------------
 */

#include "mfcform.h"

int heap[100],n=1;
void swap(int *a,int *b)
{
    int w;
    w=*a; *a=*b; *b=w;
}
void shiftdown(int p,int n,int heap[])   /* 下方移動 */
{
    int s;
    s=2*p;
    while (s<=n){
        if( s<n && heap[s+1]>heap[s])    /* 左と右の子の大きい方 */
            s++;
        if (heap[p]>=heap[s])
            break;
        swap(&heap[p],&heap[s]);
        p=s; s=2*p;                      /* 親と子の位置の更新 */
    }
}
void CDr48_2View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	CString buf;
	text1.GetWindowText(buf);
	heap[n]=stoi(buf);
	n++;
}

void CDr48_2View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	int i,m;
	m=n-1;                        /* ｎの保存 */
    for (i=m/2;i>=1;i--)        /* 初期ヒープの作成 */
        shiftdown(i,m,heap);
    while (m>1){
        swap(&heap[1],&heap[m]);
        m--;                        /* 木の終端を切り離す */
        shiftdown(1,m,heap);
    }
	tinit();cls();
    for (i=1;i<n;i++)
        printf("%d ",heap[i]);
    printf("\n");
	n=1;  // 最初からやり直す
	tfin();
}
