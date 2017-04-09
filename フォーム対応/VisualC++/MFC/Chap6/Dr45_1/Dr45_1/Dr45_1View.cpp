// Dr45_1View.cpp : CDr45_1View クラスの実装
//

#include "stdafx.h"
#include "Dr45_1.h"

#include "Dr45_1Doc.h"
#include "Dr45_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr45_1View

IMPLEMENT_DYNCREATE(CDr45_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr45_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr45_1View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr45_1View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CDr45_1View コンストラクション/デストラクション

CDr45_1View::CDr45_1View()
	: CFormView(CDr45_1View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr45_1View::~CDr45_1View()
{
}

void CDr45_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr45_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr45_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr45_1View 診断

#ifdef _DEBUG
void CDr45_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr45_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr45_1Doc* CDr45_1View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr45_1Doc)));
	return (CDr45_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr45_1View メッセージ ハンドラ
/*
 * -----------------------------------
 *      ２分探索木のトラバーサル     *
 * -----------------------------------
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
void treewalk(struct tnode *p)  /* 木のトラバーサル */
{
    if (p!=NULL){
        treewalk(p->right);
        printf("%s\n",p->name);
        treewalk(p->left);
    }
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

void CDr45_1View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    char dat[12];
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,dat);
	root=gentree(root,dat);
}

void CDr45_1View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	tinit();cls();
	treewalk(root);
	tfin();
}
