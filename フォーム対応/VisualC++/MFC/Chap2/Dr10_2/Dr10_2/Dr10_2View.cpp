// Dr10_2View.cpp : CDr10_2View クラスの実装
//

#include "stdafx.h"
#include "Dr10_2.h"

#include "Dr10_2Doc.h"
#include "Dr10_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr10_2View

IMPLEMENT_DYNCREATE(CDr10_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr10_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr10_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr10_2View コンストラクション/デストラクション

CDr10_2View::CDr10_2View()
	: CFormView(CDr10_2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr10_2View::~CDr10_2View()
{
}

void CDr10_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr10_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr10_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr10_2View 診断

#ifdef _DEBUG
void CDr10_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr10_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr10_2Doc* CDr10_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr10_2Doc)));
	return (CDr10_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr10_2View メッセージ ハンドラ
/*
 * ---------------------------------------
 *      テイラー展開（ｃｏｓ（ｘ））     *
 * ---------------------------------------
 */

#include "mfcform.h"

double mycos(double x)
{
    double EPS=1e-08;
    double s=1.0,e=1.0,d;
    int k;

    x=fmod(x,2*3.14159265358979);      /* ｘの値を０～２πに収める */
    for (k=1;k<=200;k=k+2) {
        d=s;
        e=-e*x*x/(k*(k+1));
        s=s+e;
        if (fabs(s-d)<EPS*fabs(d))     /* 打ち切り誤差 */
            return s;
    }
    return 9999.0;                     /* 収束しないとき */
}

void CDr10_2View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    double x,rd=3.14159/180;
	tinit();cls();
    printf("    x      mycos(x)        cos(x)\n");
    for (x=0;x<=180;x=x+10)
        printf("%5.1f%14.6f%14.6f\n",x,mycos(x*rd),cos(x*rd));
	tfin();
}
