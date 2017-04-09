// Dr47View.cpp : CDr47View クラスの実装
//

#include "stdafx.h"
#include "Dr47.h"

#include "Dr47Doc.h"
#include "Dr47View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr47View

IMPLEMENT_DYNCREATE(CDr47View, CFormView)

BEGIN_MESSAGE_MAP(CDr47View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr47View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr47View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CDr47View コンストラクション/デストラクション

CDr47View::CDr47View()
	: CFormView(CDr47View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr47View::~CDr47View()
{
}

void CDr47View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr47View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr47View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr47View 診断

#ifdef _DEBUG
void CDr47View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr47View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr47Doc* CDr47View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr47Doc)));
	return (CDr47Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr47View メッセージ ハンドラ
/*
 * -----------------------------------
 *      ヒープの作成（下方移動）     *
 * -----------------------------------
 */

#include "mfcform.h"

int heap[100],n=1;

void swap(int *a,int *b)
{
    int w;
    w=*a; *a=*b; *b=w;
}

void CDr47View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	CString buf;
	text1.GetWindowText(buf);
	heap[n]=stoi(buf);
    n++;
}

void CDr47View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i,p,s,m;
    m=n-1;                     /* データ数 */
    for (i=m/2;i>=1;i--){
        p=i;                 /* 親の位置 */
        s=2*p;               /* 左の子の位置 */
        while (s<=m){
            if (s<m && heap[s+1]<heap[s])    /* 左と右の子の小さい方 */
                s++;
            if (heap[p]<=heap[s])
                break;
            swap(&heap[p],&heap[s]);
            p=s; s=2*p;                      /* 親と子の位置の更新 */
        }
    }

	tinit();cls();
	for (i=1;i<=m;i++)
        printf("%d ",heap[i]);
    printf("\n");
	tfin();
}
