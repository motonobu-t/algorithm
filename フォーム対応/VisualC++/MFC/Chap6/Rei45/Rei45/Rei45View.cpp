// Rei45View.cpp : CRei45View クラスの実装
//

#include "stdafx.h"
#include "Rei45.h"

#include "Rei45Doc.h"
#include "Rei45View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei45View

IMPLEMENT_DYNCREATE(CRei45View, CFormView)

BEGIN_MESSAGE_MAP(CRei45View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei45View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei45View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei45View コンストラクション/デストラクション

CRei45View::CRei45View()
	: CFormView(CRei45View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei45View::~CRei45View()
{
}

void CRei45View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei45View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei45View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei45View 診断

#ifdef _DEBUG
void CRei45View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei45View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei45Doc* CRei45View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei45Doc)));
	return (CRei45Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei45View メッセージ ハンドラ
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
        treewalk(p->left);
        printf("%s\n",p->name);
        treewalk(p->right);
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

void CRei45View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    char dat[12];
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,dat);
	root=gentree(root,dat);
}

void CRei45View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	tinit();cls();
	treewalk(root);
	tfin();
}
