// Dr38_1View.cpp : CDr38_1View クラスの実装
//

#include "stdafx.h"
#include "Dr38_1.h"

#include "Dr38_1Doc.h"
#include "Dr38_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr38_1View

IMPLEMENT_DYNCREATE(CDr38_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr38_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr38_1View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr38_1View コンストラクション/デストラクション

CDr38_1View::CDr38_1View()
	: CFormView(CDr38_1View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr38_1View::~CDr38_1View()
{
}

void CDr38_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr38_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr38_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr38_1View 診断

#ifdef _DEBUG
void CDr38_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr38_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr38_1Doc* CDr38_1View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr38_1Doc)));
	return (CDr38_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr38_1View メッセージ ハンドラ
/*
 * -------------------------------------------------
 *      逆ポーランド記法（かっこの処理を含む）     *
 * -------------------------------------------------
 */

#include "mfcform.h"

char stack[50],polish[50];
int pri[256];                   /* 優先順位表 */
int sp1,sp2;                    /* スタック・ポインタ */

void CDr38_1View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i;
    char *p="(a+b)*(c+d)";      /* 式 */

    for (i=0;i<=255;i++)        /* オペランドの優先順位 */
        pri[i]=3;
    pri['+']=pri['-']=1; pri['*']=pri['/']=2;
    pri['(']=0;

    stack[0]=0;pri[0]=-1;       /* 番兵 */
    sp1=sp2=0;
    while  (*p!='\0'){
        if (*p=='(')            /* ( の処理 */
            stack[++sp1]=*p;
        else if(*p==')'){       /* ) の処理 */
            while (stack[sp1]!='(')
                polish[++sp2]=stack[sp1--];
            sp1--;
        }
        else {                  /* オペランドと演算子の処理 */
            while (pri[*p]<=pri[stack[sp1]])
                polish[++sp2]=stack[sp1--];
            stack[++sp1]=*p;
        }
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
