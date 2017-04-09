// Rei44View.cpp : CRei44View クラスの実装
//

#include "stdafx.h"
#include "Rei44.h"

#include "Rei44Doc.h"
#include "Rei44View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRei44View

IMPLEMENT_DYNCREATE(CRei44View, CFormView)

BEGIN_MESSAGE_MAP(CRei44View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CRei44View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRei44View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CRei44View コンストラクション/デストラクション

CRei44View::CRei44View()
	: CFormView(CRei44View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CRei44View::~CRei44View()
{
}

void CRei44View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CRei44View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CRei44View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CRei44View 診断

#ifdef _DEBUG
void CRei44View::AssertValid() const
{
	CFormView::AssertValid();
}

void CRei44View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRei44Doc* CRei44View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRei44Doc)));
	return (CRei44Doc*)m_pDocument;
}
#endif //_DEBUG


// CRei44View メッセージ ハンドラ
/*
 * -------------------------------------
 *      ２分探索木の作成（再帰版）     *
 * -------------------------------------
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


void CRei44View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    char dat[12];
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,dat);
    root=gentree(root,dat);
}

void CRei44View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	struct tnode *p;
	p=root;
	tinit();cls();
	while (p!=NULL) {
		printf("%s\n",p->name);
		p=p->left;
	}
	tfin();
}
