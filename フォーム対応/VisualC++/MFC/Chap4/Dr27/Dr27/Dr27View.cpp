// Dr27View.cpp : CDr27View クラスの実装
//

#include "stdafx.h"
#include "Dr27.h"

#include "Dr27Doc.h"
#include "Dr27View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr27View

IMPLEMENT_DYNCREATE(CDr27View, CFormView)

BEGIN_MESSAGE_MAP(CDr27View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr27View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr27View コンストラクション/デストラクション

CDr27View::CDr27View()
	: CFormView(CDr27View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr27View::~CDr27View()
{
}

void CDr27View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr27View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr27View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr27View 診断

#ifdef _DEBUG
void CDr27View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr27View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr27Doc* CDr27View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr27Doc)));
	return (CDr27Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr27View メッセージ ハンドラ
/*
 * --------------------------------------
 *      フィボナッチ数（非再帰版）      *
 * --------------------------------------
 */

#include "mfcform.h"
long fib(long n)
{
    long a,b,dummy,k;
    a=1L; b=1L;
    for (k=3;k<=n;k++){
        dummy=b;
        b=a+b;
        a=dummy;
    }
    return b;
}

void CDr27View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    long n;
	tinit();cls();
    for (n=1;n<=20;n++)
        printf("%3ld: %ld\n",n,fib(n));
	tfin();
}
