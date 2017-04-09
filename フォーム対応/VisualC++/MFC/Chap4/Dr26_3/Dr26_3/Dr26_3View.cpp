// Dr26_3View.cpp : CDr26_3View クラスの実装
//

#include "stdafx.h"
#include "Dr26_3.h"

#include "Dr26_3Doc.h"
#include "Dr26_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr26_3View

IMPLEMENT_DYNCREATE(CDr26_3View, CFormView)

BEGIN_MESSAGE_MAP(CDr26_3View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr26_3View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr26_3View コンストラクション/デストラクション

CDr26_3View::CDr26_3View()
	: CFormView(CDr26_3View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr26_3View::~CDr26_3View()
{
}

void CDr26_3View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr26_3View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr26_3View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr26_3View 診断

#ifdef _DEBUG
void CDr26_3View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr26_3View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr26_3Doc* CDr26_3View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr26_3Doc)));
	return (CDr26_3Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr26_3View メッセージ ハンドラ
/*
 * ---------------------------------------
 *      Ｈｏｒｎｅｒの方法（再帰版）     *
 * ---------------------------------------
 */

#include "mfcform.h"

#define N 4        /* 次数 */
double fn(double x,double a[],int i)
{
    if (i==0)
        return a[N];
    else
        return fn(x,a,i-1)*x+a[N-i];
}
void CDr26_3View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    double a[]={1,2,3,4,5};
	tinit();cls();
    printf("%f\n",fn(2,a,N));
	tfin();
}
