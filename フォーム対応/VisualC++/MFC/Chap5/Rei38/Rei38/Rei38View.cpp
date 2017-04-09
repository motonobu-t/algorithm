// Rei38View.cpp : CRei38View クラスの実装
//

#include "stdafx.h"
#include "Rei38.h"

#include "Rei38Doc.h"
#include "Rei38View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei38View

IMPLEMENT_DYNCREATE(CRei38View, CFormView)

BEGIN_MESSAGE_MAP(CRei38View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei38View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei38View コンストラクション/デストラクション

CRei38View::CRei38View()
	: CFormView(CRei38View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei38View::~CRei38View()
{
}

void CRei38View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei38View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei38View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei38View 診断

#ifdef _DEBUG
void CRei38View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei38View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei38Doc* CRei38View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei38Doc)));
	return (CRei38Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei38View メッセージ ハンドラ
/*
 * ---------------------------
 *      逆ポーランド記法     *
 * ---------------------------
 */

#include "mfcform.h"

char stack[50],polish[50];
int pri[256];                   /* 優先順位表 */
int sp1,sp2;                    /* スタック・ポインタ */

void CRei38View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    int i;
    char *p="a+b-c*d/e";        /* 式 */

	for (i=0;i<=255;i++)        /* 優先順位表の作成 */
        pri[i]=3;
    pri['+']=pri['-']=1; pri['*']=pri['/']=2;

    stack[0]=0;pri[0]=-1;       /* 番兵 */
    sp1=sp2=0;
    while  (*p!='\0'){
        while (pri[*p]<=pri[stack[sp1]])
            polish[++sp2]=stack[sp1--];
        stack[++sp1]=*p++;
    }
    for (i=sp1;i>0;i--)         /* スタックの残りを取り出す */
        polish[++sp2]=stack[i];

	tinit();cls();
    for (i=1;i<=sp2;i++)
        putchar(polish[i]);
    printf("\n");
	tfin();
}
