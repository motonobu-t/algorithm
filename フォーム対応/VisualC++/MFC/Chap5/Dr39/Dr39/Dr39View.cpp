// Dr39View.cpp : CDr39View クラスの実装
//

#include "stdafx.h"
#include "Dr39.h"

#include "Dr39Doc.h"
#include "Dr39View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr39View

IMPLEMENT_DYNCREATE(CDr39View, CFormView)

BEGIN_MESSAGE_MAP(CDr39View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr39View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr39View コンストラクション/デストラクション

CDr39View::CDr39View()
	: CFormView(CDr39View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr39View::~CDr39View()
{
}

void CDr39View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr39View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr39View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr39View 診断

#ifdef _DEBUG
void CDr39View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr39View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr39Doc* CDr39View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr39Doc)));
	return (CDr39Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr39View メッセージ ハンドラ
/*
 * ---------------------------------------
 *      優先順位パージング（直接法）     *
 * ---------------------------------------
 */

#include "mfcform.h"

#define Max(a,b) ((a)>(b)?(a):(b))
#define Min(a,b) ((a)<(b)?(a):(b))

double v[50];        /* 計算用スタック */
char ope[50];        /* 演算子用スタック */
int pri[256];        /* 優先順位表 */
int sp1,sp2;         /* スタック・ポインタ */

void calc(void)             /* 演算処理 */
{
    switch (ope[sp1]) {
        case '|' : v[sp2-1]=(v[sp2-1]+v[sp2])/2;break;
        case '>' : v[sp2-1]=Max(v[sp2-1],v[sp2]);break;
        case '<' : v[sp2-1]=Min(v[sp2-1],v[sp2]);break;
    }
    sp2--; sp1--;
}

void CDr39View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    char *expression="(1>2|2<8|3<4)|(9<2)",*p=expression;

    pri['|']=1; pri['<']=pri['>']=2;
    pri['(']=3; pri[')']=0;

    ope[0]=0; pri[0]=-1;        /* 番兵 */
    sp1=sp2=0;
    while  (*p!='\0'){
        if ('0'<=*p && *p<='9')
            v[++sp2]=*p-'0';
        else {
            while (pri[*p]<=pri[ope[sp1]] && ope[sp1]!='(')
                calc();
            if (*p!=')')
                ope[++sp1]=*p;
            else
                sp1--;      /* （を取り除く */
        }
        p++;
    }
    while (sp1>0)           /* 演算子スタックが空になるまで */
        calc();
	tinit();cls();
    printf("%s=%f\n",expression,v[1]);
	tfin();
}
