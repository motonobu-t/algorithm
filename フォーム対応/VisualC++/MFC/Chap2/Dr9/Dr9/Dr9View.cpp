// Dr9View.cpp : CDr9View クラスの実装
//

#include "stdafx.h"
#include "Dr9.h"

#include "Dr9Doc.h"
#include "Dr9View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr9View

IMPLEMENT_DYNCREATE(CDr9View, CFormView)

BEGIN_MESSAGE_MAP(CDr9View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr9View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr9View コンストラクション/デストラクション

CDr9View::CDr9View()
	: CFormView(CDr9View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr9View::~CDr9View()
{
}

void CDr9View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, text1);
	DDX_Control(pDX, IDC_EDIT2, text2);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr9View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr9View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr9View 診断

#ifdef _DEBUG
void CDr9View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr9View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr9Doc* CDr9View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr9Doc)));
	return (CDr9Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr9View メッセージ ハンドラ
/*
 * -----------------------------
 *      シンプソンの定積分     *
 * -----------------------------
 */

#include "mfcform.h"

#define f(x) (sqrt(4-(x)*(x)))   /* 被積分関数 */

void CDr9View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int k;
    double a,b,n,h,fo,fe,sum;

	CString buf;
	text1.GetWindowText(buf);
	a=stod(buf);
	text2.GetWindowText(buf);
	b=stod(buf);

    n=50;              /* ａ～ｂ間の分割数 */
    h=(b-a)/(2*n);     /* 区間幅 */
    fo=0; fe=0;
    for (k=1;k<=2*n-3;k=k+2){
        fo=fo+f(a+h*k);         /* 奇数項の和 */
        fe=fe+f(a+h*(k+1));     /* 偶数項の和 */
    }
    sum=(f(a)+f(b)+4*(fo+f(b-h))+2*fe)*h/3;

	tinit();cls();
    printf("   /%f\n",b);
    printf("   |  sqrt(4-x*x) =%f\n",sum);
    printf("   /%f\n",a);
	tfin();
}
