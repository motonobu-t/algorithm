// Dr44_2View.cpp : CDr44_2View クラスの実装
//

#include "stdafx.h"
#include "Dr44_2.h"

#include "Dr44_2Doc.h"
#include "Dr44_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr44_2View

IMPLEMENT_DYNCREATE(CDr44_2View, CFormView)

BEGIN_MESSAGE_MAP(CDr44_2View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr44_2View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr44_2View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CDr44_2View コンストラクション/デストラクション

CDr44_2View::CDr44_2View()
	: CFormView(CDr44_2View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr44_2View::~CDr44_2View()
{
}

void CDr44_2View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr44_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr44_2View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr44_2View 診断

#ifdef _DEBUG
void CDr44_2View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr44_2View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr44_2Doc* CDr44_2View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr44_2Doc)));
	return (CDr44_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr44_2View メッセージ ハンドラ
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
void gentree(struct tnode **p,char *w)  /* 木の作成の再帰手続き */
{                                       /* 参照による呼出し     */
    if ((*p)==NULL){
        (*p)=talloc();
        strcpy((*p)->name,w);
        (*p)->left=(*p)->right=NULL;
    }
    else if(strcmp(w,(*p)->name)<0)
        gentree(&((*p)->left),w);
    else
        gentree(&((*p)->right),w);
}
void CDr44_2View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    char dat[12];
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,dat);
	gentree(&root,dat);
}

void CDr44_2View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	struct tnode *p;
	p=root;
	tinit();cls();
    while (p!=NULL){
        printf("%s\n",p->name);
        p=p->left;
    }
	tfin();
}
