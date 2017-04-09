// Dr38_2View.cpp : CDr38_2View クラスの実装
//

#include "stdafx.h"
#include "Dr38_2.h"

#include "Dr38_2Doc.h"
#include "Dr38_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr38_2View

IMPLEMENT_DYNCREATE(CDr38_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr38_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr38_2View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr38_2View コンストラクション/デストラクション

CDr38_2View::CDr38_2View()
	: CFormView(CDr38_2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr38_2View::~CDr38_2View()
{
}

void CDr38_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr38_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr38_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr38_2View 診断

#ifdef _DEBUG
void CDr38_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr38_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr38_2Doc* CDr38_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr38_2Doc)));
	return (CDr38_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr38_2View メッセージ ハンドラ
/*
 * -------------------------------------------------
 *      逆ポーランド記法（かっこの処理を含む）     *
 * -------------------------------------------------
 */

#include "mfcform.h"

char stack[50],polish[50];
int pri[256];                   /* 優先順位表 */
int sp1,sp2;                    /* スタック・ポインタ */

void CDr38_2View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i;
    char *p="(a+b)*(c+d)";      /* 式 */

    for (i=0;i<=255;i++)        /* オペランドの優先順位 */
        pri[i]=3;
    pri['+']=pri['-']=1; pri['*']=pri['/']=2;    /* 演算子の優先順位 */
    pri['(']=4; pri[')']=0;

    stack[0]=0;pri[0]=-1;       /* 番兵 */
    sp1=sp2=0;
    while  (*p!='\0'){
        while (pri[*p]<=pri[stack[sp1]] && stack[sp1]!='(')
            polish[++sp2]=stack[sp1--];
        if (*p!=')')
            stack[++sp1]=*p;
        else
            sp1--;
        p++;

    }
    for (i=sp1;i>0;i--)        /* スタックの残りを取り出す */
        polish[++sp2]=stack[i];
	tinit();cls();
    for (i=1;i<=sp2;i++)       /* 逆ポーランド式の表示 */
        putchar(polish[i]);
    printf("\n");
	tfin();
}
