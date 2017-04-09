// Dr26_2View.cpp : CDr26_2View クラスの実装
//

#include "stdafx.h"
#include "Dr26_2.h"

#include "Dr26_2Doc.h"
#include "Dr26_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr26_2View

IMPLEMENT_DYNCREATE(CDr26_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr26_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr26_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr26_2View コンストラクション/デストラクション

CDr26_2View::CDr26_2View()
	: CFormView(CDr26_2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr26_2View::~CDr26_2View()
{
}

void CDr26_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr26_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr26_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr26_2View 診断

#ifdef _DEBUG
void CDr26_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr26_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr26_2Doc* CDr26_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr26_2Doc)));
	return (CDr26_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr26_2View メッセージ ハンドラ
/*
 * ------------------------------
 *      nＣrの計算（再帰版）    *
 * ------------------------------
 */

#include "mfcform.h"
long combi(int n,int r)
{
    if (r==0 || r==n)
        return 1L;
    else
        return combi(n-1,r)+combi(n-1,r-1);
}

void CDr26_2View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int n,r;
	tinit();cls();
    for (n=0;n<=5;n++) {
        for (r=0;r<=n;r++)
            printf("%dＣ%d=%ld  ",n,r,combi(n,r));
        printf("\n");
    }
	tfin();
}
