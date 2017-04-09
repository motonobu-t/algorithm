// Dr13View.cpp : CDr13View クラスの実装
//

#include "stdafx.h"
#include "Dr13.h"

#include "Dr13Doc.h"
#include "Dr13View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr13View

IMPLEMENT_DYNCREATE(CDr13View, CFormView)

BEGIN_MESSAGE_MAP(CDr13View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr13View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr13View コンストラクション/デストラクション

CDr13View::CDr13View()
	: CFormView(CDr13View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr13View::~CDr13View()
{
}

void CDr13View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr13View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr13View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr13View 診断

#ifdef _DEBUG
void CDr13View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr13View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr13Doc* CDr13View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr13Doc)));
	return (CDr13Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr13View メッセージ ハンドラ
/*
 * -------------------
 *      多桁計算     *
 * -------------------
 */

#include "mfcform.h"

#define KETA 20             /* 桁数 */
#define N ((KETA-1)/4+1)    /* 配列サイズ */

void lmul(short a[],short b,short c[])    /* ロング数×ショート数 */
{
    short i;long d,cy=0;
    for (i=N-1;i>=0;i--){
        d=a[i];
        c[i]=(d*b+cy)%10000;
        cy=(d*b+cy)/10000;
    }
}
void ldiv(short a[],short b,short c[])    /* ロング数÷ショート数 */
{
    short i;long d,rem=0;
    for (i=0;i<N;i++){
        d=a[i];
        c[i]=(short)((d+rem)/b);
        rem=((d+rem)%b)*10000;
    }
}
void print(short c[])            /* ロング数の表示 */
{
    short i;
    for (i=0;i<N;i++)
        printf("%04d ",c[i]);
    printf("\n");
}

void CDr13View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    short a[N+2]={   0,3050,2508,8080,1233},
          c[N+2];
	tinit();cls();
    lmul(a,101,c); print(c);
    ldiv(a,200,c); print(c);
	tfin();
}
