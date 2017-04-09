// Rei46View.cpp : CRei46View クラスの実装
//

#include "stdafx.h"
#include "Rei46.h"

#include "Rei46Doc.h"
#include "Rei46View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei46View

IMPLEMENT_DYNCREATE(CRei46View, CFormView)

BEGIN_MESSAGE_MAP(CRei46View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei46View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei46View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei46View コンストラクション/デストラクション

CRei46View::CRei46View()
	: CFormView(CRei46View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei46View::~CRei46View()
{
}

void CRei46View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei46View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei46View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei46View 診断

#ifdef _DEBUG
void CRei46View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei46View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei46Doc* CRei46View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei46Doc)));
	return (CRei46Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei46View メッセージ ハンドラ
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
    struct tnode *q[128],       /* ポインタ・テーブル */
                 *w[128];       /* 作業用 */
    int i,child,n,level;

    child=1; q[0]=p; level=0;   /* 初期値 */
    do {
        n=0;
        printf("level %d :",level);
        for (i=0;i<child;i++){
            printf("%12s",q[i]->name); /* ノードの表示 */
            /* １つ下のレベルの子へのポインタをスタックに積む */
            if (q[i]->left!=NULL)
                w[n++]=q[i]->left;
            if (q[i]->right!=NULL)
                w[n++]=q[i]->right;
        }
        printf("\n");
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
void CRei46View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    char dat[12];
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,dat);
	root=gentree(root,dat);
}

void CRei46View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	tinit();cls();
	treewalk(root);
	tfin();
}
