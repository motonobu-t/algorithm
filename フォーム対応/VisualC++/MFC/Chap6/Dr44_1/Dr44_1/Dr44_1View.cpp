// Dr44_1View.cpp : CDr44_1View クラスの実装
//

#include "stdafx.h"
#include "Dr44_1.h"

#include "Dr44_1Doc.h"
#include "Dr44_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CDr44_1View

IMPLEMENT_DYNCREATE(CDr44_1View, CFormView)

BEGIN_MESSAGE_MAP(CDr44_1View, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, &CDr44_1View::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDr44_1View::OnBnClickedButton2)
END_MESSAGE_MAP()

// CDr44_1View コンストラクション/デストラクション

CDr44_1View::CDr44_1View()
	: CFormView(CDr44_1View::IDD)
{
	// TODO: 構築コードをここに追加します。

}

CDr44_1View::~CDr44_1View()
{
}

void CDr44_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PICT, pict);
	DDX_Control(pDX, IDC_EDIT1, text1);
}

BOOL CDr44_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: この位置で CREATESTRUCT cs を修正して Window クラスまたはスタイルを
	//  修正してください。

	return CFormView::PreCreateWindow(cs);
}

void CDr44_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}


// CDr44_1View 診断

#ifdef _DEBUG
void CDr44_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CDr44_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CDr44_1Doc* CDr44_1View::GetDocument() const // デバッグ以外のバージョンはインラインです。
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDr44_1Doc)));
	return (CDr44_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CDr44_1View メッセージ ハンドラ
/*
 * ---------------------------------------
 *      ２分探索木のサーチ（再帰版）     *
 * ---------------------------------------
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
struct tnode *search(struct tnode *p,char *key)  /* 木のサーチ */
{
    if (p==NULL || strcmp(key,p->name)==0)
        return p;
    if (strcmp(key,p->name)<0)
        return search(p->left,key);
    else
        return search(p->right,key);
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
void CDr44_1View::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
    char key[12];
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,key);
    root=gentree(root,key);
}

void CDr44_1View::OnBnClickedButton2()
{
	// TODO: ここにコントロール通知ハンドラ コードを追加します。
	struct tnode *p;
	char key[12];
	CString buf;
	text1.GetWindowText(buf);
	stoc(buf,key);
	tinit();cls();
    if ((p=search(root,key))!=NULL)
        printf("%s が見つかりました\n",p->name);
    else
        printf("見つかりません\n");
	tfin();
}
