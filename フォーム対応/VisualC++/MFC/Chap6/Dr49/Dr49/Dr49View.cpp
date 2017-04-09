// Dr49View.cpp : CDr49View クラスの実装
//

#include "stdafx.h"
#include "Dr49.h"

#include "Dr49Doc.h"
#include "Dr49View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr49View

IMPLEMENT_DYNCREATE(CDr49View, CFormView)

BEGIN_MESSAGE_MAP(CDr49View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr49View::OnBnClickedButton1)
END_MESSAGE_MAP()

// CDr49View コンストラクション/デストラクション

CDr49View::CDr49View()
	: CFormView(CDr49View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr49View::~CDr49View()
{
}

void CDr49View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
}

BOOL CDr49View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr49View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr49View 診断

#ifdef _DEBUG
void CDr49View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr49View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr49Doc* CDr49View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr49Doc)));
	return (CDr49Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr49View メッセージ ハンドラ
/*
 * ---------------------------------
 *      式の木を用いた式の計算     *
 * ---------------------------------
 */

#include "mfcform.h"

struct tnode {
    struct tnode *left;     /* 左部分木へのポインタ */
    int ope;                /* 項目 */
    struct tnode *right;    /* 右部分木へのポインタ */
};
struct tnode *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
struct tnode *gentree(struct tnode *p,char *w)  /* 式の木の作成 */
{
    int n;

    n=strlen(w);
    p=talloc();                     /* 文字列の終端をノードにする */
    if ('0'<=w[n-1] && w[n-1]<='9')        /* 定数のときは数値に変換 */
        p->ope=w[n-1]-'0';
    else
        p->ope=w[n-1];
    w[n-1]='\0';                /* 終端を除く */
    if (!(p->ope=='-' || p->ope=='+' || p->ope=='*' || p->ope=='/')){
        p->left=p->right=NULL;
    }
    else {
        p->right=gentree(p->right,w);
        p->left=gentree(p->left,w);
    }
    return p;
}
void postfix(struct tnode *p)    /* 式の木の計算 */
{
    if (p!=NULL){
        postfix(p->left);
        postfix(p->right);
        switch (p->ope){
            case '+': p->ope=(p->left->ope)+(p->right->ope);break;
            case '-': p->ope=(p->left->ope)-(p->right->ope);break;
            case '*': p->ope=(p->left->ope)*(p->right->ope);break;
            case '/': p->ope=(p->left->ope)/(p->right->ope);break;
        }
    }
}
void CDr49View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    struct tnode *root;
    char expression[]="53*64+2/-";
    root=NULL;
    root=gentree(root,expression);
	tinit();cls();
    postfix(root);         /* 式の計算 */
    printf("value=%d\n",root->ope);
	tfin();
}
