// Dr45_2View.cpp : CDr45_2View クラスの実装
//

#include "stdafx.h"
#include "Dr45_2.h"

#include "Dr45_2Doc.h"
#include "Dr45_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr45_2View

IMPLEMENT_DYNCREATE(CDr45_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr45_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr45_2View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr45_2View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CDr45_2View コンストラクション/デストラクション

CDr45_2View::CDr45_2View()
	: CFormView(CDr45_2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr45_2View::~CDr45_2View()
{
}

void CDr45_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr45_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr45_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr45_2View 診断

#ifdef _DEBUG
void CDr45_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr45_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr45_2Doc* CDr45_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr45_2Doc)));
	return (CDr45_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr45_2View メッセージ ハンドラ
/*
 * -----------------------------------------------
 *      ２分探索木のトラバーサル（非再帰版）     *
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
void treewalk(struct tnode *p)   /* 木のトラバーサル（非再帰版） */
{
    struct tnode *q,*w[128];
    int sp=0;

    q=p;
    while (!(sp==0 && q==NULL)){
        while (q!=NULL){         /* 行けるだけ左に進む */
            w[sp++]=q;           /* 親の位置をスタックに積む */
            q=q->left;
        }
        sp--;                    /* １つ前の親に戻る */
        printf("%s\n",w[sp]->name);
        q=w[sp]->right;          /* 右へ進む */
    }
}
struct tnode *gentree(struct tnode *p,char *w)  /* 木の作成の再帰手続き */
{
    if (p==NULL){
        p=talloc();
        strcpy(p->name,w);
        p->left=p->right=NULL;
    }
    else if(strcmp(p->name,w)<0)
        p->right=gentree(p->right,w);
    else
        p->left=gentree(p->left,w);
    return p;
}

void CDr45_2View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    char dat[12];
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,dat);
    root=gentree(root,dat);
}

void CDr45_2View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	tinit();cls();
	treewalk(root);
	tfin();
}
