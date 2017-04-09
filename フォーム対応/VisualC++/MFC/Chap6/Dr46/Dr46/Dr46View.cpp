// Dr46View.cpp : CDr46View クラスの実装
//

#include "stdafx.h"
#include "Dr46.h"

#include "Dr46Doc.h"
#include "Dr46View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr46View

IMPLEMENT_DYNCREATE(CDr46View, CFormView)

BEGIN_MESSAGE_MAP(CDr46View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr46View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr46View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CDr46View コンストラクション/デストラクション

CDr46View::CDr46View()
	: CFormView(CDr46View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr46View::~CDr46View()
{
}

void CDr46View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr46View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr46View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr46View 診断

#ifdef _DEBUG
void CDr46View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr46View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr46Doc* CDr46View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr46Doc)));
	return (CDr46Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr46View メッセージ ハンドラ
/*
 * -----------------------------------------------
 *      レベルごとの２分探索木のトラバーサル     *
 * -----------------------------------------------
 */

#include "mfcform.h"

struct tnode {
    struct tnode *left;     /* 左部分木へのポインタ */
    char name[12];          /* 名前 */
    struct tnode *right;    /* 右部分木へのポインタ */
} *root=NULL;
struct tnode *talloc(void)     /* 記憶領域の取得 */
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}
void treewalk(struct tnode *p)  /* レベルごとの木のトラバーサル */
{
    struct connect {            /* 接続関係を示す構造体 */
        struct tnode *node;     /* 子ノード */
        char *parent;           /* 親の名前 */
        char direct;            /* 親の左の子か右の子かを示す */
    } q[128],w[128];
    int i,child,n,level;

    child=1; level=0;           /* 初期値 */
    q[0].node=p; q[0].parent="root"; q[0].direct=' ';
    do {
        n=0;
        printf("level %d :\n",level);
        for (i=0;i<child;i++){
            printf("%12s->%c:%12s\n",q[i].parent,q[i].direct,q[i].node->name);
            /* １つ下のレベルの子へのポインタをスタックに積む */
            if (q[i].node->left!=NULL){
                w[n].parent=q[i].node->name;
                w[n].direct='l';
                w[n].node=q[i].node->left;
                n++;
            }
            if (q[i].node->right!=NULL){
                w[n].parent=q[i].node->name;
                w[n].direct='r';
                w[n].node=q[i].node->right;
                n++;
            }
        }
        child=n;            /* １つ下のレベルの子の数 */
        for (i=0;i<child;i++)
            q[i]=w[i];
        level++;
    } while (child!=0);
}
struct tnode *gentree(struct tnode *p,char *w)  /* 木の作成の再帰手続き */
{
    if (p==NULL){
        p=talloc();
        strcpy(p->name,w);
        p->left=p->right=NULL;
    }
    else if(strcmp(w,p->name)<0)
        p->left=gentree(p->left,w);
    else
        p->right=gentree(p->right,w);
    return p;
}
void CDr46View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    char dat[12];
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,dat);
    root=gentree(root,dat);
}

void CDr46View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	tinit();cls();
	treewalk(root);
	tfin();
}
