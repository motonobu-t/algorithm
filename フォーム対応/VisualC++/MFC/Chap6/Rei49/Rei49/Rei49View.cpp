// Rei49View.cpp : CRei49View クラスの実装
//

#include "stdafx.h"
#include "Rei49.h"

#include "Rei49Doc.h"
#include "Rei49View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei49View

IMPLEMENT_DYNCREATE(CRei49View, CFormView)

BEGIN_MESSAGE_MAP(CRei49View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei49View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CRei49View コンストラクション/デストラクション

CRei49View::CRei49View()
	: CFormView(CRei49View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei49View::~CRei49View()
{
}

void CRei49View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CRei49View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei49View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei49View 診断

#ifdef _DEBUG
void CRei49View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei49View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei49Doc* CRei49View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei49Doc)));
	return (CRei49Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei49View メッセージ ハンドラ
/*
 * -----------------
 *      式の木     *
 * -----------------
 */

#include "mfcform.h"

struct tnode {
    struct tnode *left;     /* 左部分木へのポインタ */
    char ope;               /* 項目 */
    struct tnode *right;    /* 右部分木へのポインタ */
};

struct tnode *talloc(void)       /* 記憶領域の取得 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
struct tnode *gentree(struct tnode *p,char *w)  /* 式の木の作成 */
{
    int n;

    n=strlen(w);
    p=talloc();
    p->ope=w[n-1];         /* 文字列の終端をノードにする */
    w[n-1]='\0';           /* 終端を除く */
    if (!(p->ope=='-' || p->ope=='+' || p->ope=='*' || p->ope=='/')){
        p->left=p->right=NULL;
    }
    else {
        p->right=gentree(p->right,w);
        p->left=gentree(p->left,w);
    }
    return p;
}
void prefix(struct tnode *p)     /* 接頭形 */
{
    if (p!=NULL){
        putchar(p->ope);
        prefix(p->left);
        prefix(p->right);
    }
}
void infix(struct tnode *p)      /* 挿入形 */
{
    if (p!=NULL){
        infix(p->left);
        putchar(p->ope);
        infix(p->right);
    }
}
void postfix(struct tnode *p)    /* 接尾形 */
{
    if (p!=NULL){
        postfix(p->left);
        postfix(p->right);
        putchar(p->ope);
    }
}
void CRei49View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    struct tnode *root;
    char expression[]="ab*cd+e/-";
    root=NULL;
    root=gentree(root,expression);
	tinit();cls();
    printf("prefix  = ");prefix(root);        /* 式の木の走査 */
	printf("\n");  // 改行を単独処理に
	printf("infix   = ");infix(root);
	printf("\n");
	printf("postfix = ");postfix(root);
    printf("\n");
	tfin();
}
